<?php
require "/eventmanager/Server/api/inc/bootstrap.php";

header('Access-Control-Allow-Origin: *');
header("Access-Control-Allow-Methods: HEAD, GET, POST, PUT, PATCH, DELETE, OPTIONS");
header("Access-Control-Allow-Headers: X-API-KEY, Origin, X-Requested-With, Content-Type, Accept, Access-Control-Request-Method,Access-Control-Request-Headers, Authorization");
header('Content-Type: application/json');

if ($_SERVER['REQUEST_METHOD'] == 'OPTIONS') {
  return 0;
}

$uri = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
$uri = explode('/', $uri);

// Redirects request to proper controller
if (isset($uri[2]) && $uri[2] == 'login') {
  require "/eventmanager/Server/api/Controller/Api/LoginController.php";

  $objFeedController = new LoginController();
  $strMethodName = $uri[3] . 'Action';
  $objFeedController->{$strMethodName}();
} else if (isset($uri[2]) && $uri[2] == 'item') {
  require "/eventmanager/Server/api/Controller/Api/ItemController.php";

  $objFeedController = new ItemController();
  $strMethodName = $uri[3] . 'Action';
  $objFeedController->{$strMethodName}();
} else {
  header("HTTP/1.1 404 Not Found");
  exit();
}
