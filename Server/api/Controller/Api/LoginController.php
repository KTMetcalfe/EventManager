<?php
require_once '/eventmanager/Server/api/Model/LoginModel.php';

class LoginController extends BaseController
{
    /**
     * "/login/verify" Endpoint - Verifies a login request
     * Returns json boolean "verified"
     */
    public function verifyAction()
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
                    $loginModel = new LoginModel();
                    $appArr = $loginModel->getApplication($user);

                    if (count($appArr) == 1 && password_verify($pswd, $appArr[0]['password'])) {
                        // Main request logic
                        $data = file_get_contents('php://input');
                        $body = json_decode($data);
                        $location = $body->{'location'};

                        require "/eventmanager/Server/api/Model/LocationModel.php";
                        $locationModel = new LocationModel;
                        if (isset($location)) {
                            $loc_name = $locationModel->getLocationById($appArr[0]['database'], $location);
                            if (isset($loc_name)) {
                                $responseData = '{"verified": true, "location_name": "' . $loc_name . '"}';
                            } else {
                                $strErrorDesc = 'Invalid location';
                                $strErrorHeader = 'HTTP/1.1 401 Unauthorized';
                            }
                        } else {
                            $strErrorDesc = 'No location provided';
                            $strErrorHeader = 'HTTP/1.1 422 Unprocessable Entity';
                        }
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
     * "/login/hash" Endpoint - Returns password hash
     */
    public function hashAction()
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

                $responseData = password_hash($pswd, PASSWORD_BCRYPT);
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
