<?php
require_once '/eventmanager/Server/api/Model/ItemModel.php';

class ItemController extends BaseController
{
    /**
     * "/item/list" Endpoint - Returns password hash
     */
    public function listAction()
    {
        $strErrorDesc = '';
        $requestMethod = $_SERVER["REQUEST_METHOD"];
        $arrQueryStringParams = $this->getQueryStringParams();

        // POST request handling
        if (strtoupper($requestMethod) == 'POST') {
            // Header check
            if (isset($_SERVER['PHP_AUTH_USER']) && isset($_SERVER['PHP_AUTH_PW'])) {
                $user = $_SERVER['PHP_AUTH_USER'];
                $pswd = $_SERVER['PHP_AUTH_PW'];

                try {
                    // Authorization check
                    require '/eventmanager/Server/api/Model/LoginModel.php';
                    $loginModel = new LoginModel();
                    $appArr = $loginModel->getApplication($user);

                    if (count($appArr) == 1 && password_verify($pswd, $appArr[0]['password'])) {
                        // Main request logic
                        $data = file_get_contents('php://input');
                        $body = json_decode($data);
                        $location = $body->{'location'};

                        $itemModel = new ItemModel;
                        if (isset($location)) {
                            $itemArr = $itemModel->getItemsByLocation($appArr[0]['database'], $location);
                        } else {
                            $itemArr = $itemModel->getItems($appArr[0]['database']);
                        }

                        $responseData = json_encode($itemArr);
                    } else if (count($appArr) > 1) {
                        throw new Exception('Too many accounts');
                    } else {
                        $strErrorDesc = 'Not Authorized';
                        $strErrorHeader = 'HTTP/1.1 401 Unauthorized';
                    }
                } catch (Error $e) {
                    $strErrorDesc = $e->getMessage() . 'Something went wrong! Please contact support.';
                    $strErrorHeader = 'HTTP/1.1 500 Internal Server Error';
                }
            } else {
                $strErrorDesc = 'Not Authorized';
                $strErrorHeader = 'HTTP/1.1 401 Unauthorized';
            }
        } else {
            $strErrorDesc = 'Method not supported';
            $strErrorHeader = 'HTTP/1.1 422 Unprocessable Entity';
        }

        // send output
        if (!$strErrorDesc) {
            $this->sendOutput(
                $responseData,
                array('Content-Type: application/json', 'HTTP/1.1 200 OK')
            );
        } else {
            $this->sendOutput(
                json_encode(array('error' => $strErrorDesc)),
                array('Content-Type: application/json', $strErrorHeader)
            );
        }
    }

    /**
     * "/item/add" Endpoint - Adds an item
     * Returns json boolean "added"
     */
    public function addAction()
    {
        $strErrorDesc = '';
        $requestMethod = $_SERVER["REQUEST_METHOD"];
        $arrQueryStringParams = $this->getQueryStringParams();

        // POST request handling
        if (strtoupper($requestMethod) == 'POST') {
            // Header check
            if (isset($_SERVER['PHP_AUTH_USER']) && isset($_SERVER['PHP_AUTH_PW'])) {
                $user = $_SERVER['PHP_AUTH_USER'];
                $pswd = $_SERVER['PHP_AUTH_PW'];

                try {
                    // Authorization check
                    require '/eventmanager/Server/api/Model/LoginModel.php';
                    $loginModel = new LoginModel();
                    $appArr = $loginModel->getApplication($user);

                    if (count($appArr) == 1 && password_verify($pswd, $appArr[0]['password'])) {
                        // Main request logic

                        $name = $_POST['name'];
                        $price = $_POST['price'];
                        $multipliers = $_POST['multipliers'];
                        $locations = $_POST['locations'];

                        $images = $_FILES;

                        $itemModel = new ItemModel();
                        $lastInsertedID = $itemModel->addItem($name, $price, $multipliers, $locations, $appArr[0]['database']);
                        $id = $lastInsertedID[0]['LAST_INSERT_ID()'];

                        if (isset($images)) {
                            $image_dir = '/eventmanager/Server/api/files/item_images/';
                            $app_dir = $appArr[0]['name'] . '/';
                            mkdir($image_dir . $app_dir);
                            $new_name =  $id . '.jpg';
                            move_uploaded_file($images['image']['tmp_name'], $image_dir . $app_dir . $new_name);
                        }

                        $responseData = '{"added":true,"id":' . $id . '}';
                    } else if (count($appArr) > 1) {
                        throw new Exception('Too many accounts');
                    } else {
                        $strErrorDesc = 'Not Authorized';
                        $strErrorHeader = 'HTTP/1.1 401 Unauthorized';
                    }
                } catch (Error $e) {
                    $strErrorDesc = $e->getMessage() . 'Something went wrong! Please contact support.';
                    $strErrorHeader = 'HTTP/1.1 500 Internal Server Error';
                }
            } else {
                $strErrorDesc = 'Not Authorized';
                $strErrorHeader = 'HTTP/1.1 401 Unauthorized';
            }
        } else {
            $strErrorDesc = 'Method not supported';
            $strErrorHeader = 'HTTP/1.1 422 Unprocessable Entity';
        }

        // send output
        if (!$strErrorDesc) {
            $this->sendOutput(
                $responseData,
                array('Content-Type: application/json', 'HTTP/1.1 200 OK')
            );
        } else {
            $this->sendOutput(
                json_encode(array('error' => $strErrorDesc)),
                array('Content-Type: application/json', $strErrorHeader)
            );
        }
    }
}
