<?php

use PHPMailer\PHPMailer\OAuth;

session_start();
if (empty($_SESSION['auth_state'])) {
    $_SESSION['auth_state'] = bin2hex(random_bytes(32));
}
?>
<?php
require "/eventmanager/Server/api/inc/bootstrap.php";
require_once "/eventmanager/Server/api/Model/Database.php";

header('Access-Control-Allow-Origin: *');
header("Access-Control-Allow-Methods: HEAD, GET, POST, PUT, PATCH, DELETE, OPTIONS");
header("Access-Control-Allow-Headers: X-API-KEY, Origin, X-Requested-With, Content-Type, Accept, Access-Control-Request-Method,Access-Control-Request-Headers, Authorization");
// header('Content-Type: application/json');

if ($_SERVER['REQUEST_METHOD'] == 'OPTIONS') {
    return 0;
}

$uri = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
$uri = explode('/', $uri);


class OAuthModel extends Database {
    public function addToken($access_token, $token_type, $expires_at, $merchant_id, $refresh_token)
    {
        $oldToken = $this->select(sprintf("SELECT * FROM tokens WHERE access_token='%s'", $access_token));
        if (count($oldToken) < 1) {
            $this->insert(sprintf("INSERT INTO tokens (access_token, token_type, expires_at, merchant_id, refresh_token) VALUES ('%s', '%s', '%s', '%s', '%s')", $access_token, $token_type, $expires_at, $merchant_id, $refresh_token));
        }
    }
}

// Redirects request to proper controller
if (!isset($uri[2])) {
    $code = $_GET['code'];
    $response_type = $_GET['response_type'];
    $state = $_GET['state'];

    if ($state == $_SESSION['auth_state']) {
        $ch = curl_init();

        curl_setopt($ch, CURLOPT_URL, 'https://connect.squareup.com/oauth2/token');
        curl_setopt($ch, CURLOPT_POST, true);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

        $headers = array(
            "Content-Type: application/json",
            "Accept: application/json",
        );
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

        $data = '{"client_id": "' . APPLICATION_ID . '", "client_secret": "' . APPLICATION_SECRET . '", "code": "' . $code . '", "grant_type": "authorization_code"}';
        curl_setopt($ch, CURLOPT_POSTFIELDS, $data);

        $out = curl_exec($ch);
        // print($out);
        $outJson = json_decode($out, true);

        $oauthModel = new OAuthModel();
        $oauthModel->addToken($outJson['access_token'], $outJson['token_type'], $outJson['expires_at'], $outJson['merchant_id'], $outJson['refresh_token']);
        curl_close($ch);

        echo '<script>window.location.replace("eventmanager://em.kianm.net?access_token=' . $outJson['access_token'] . '");</script>';
        exit();
    }
} else if (isset($uri[2]) && $uri[2] == 'authorize') {
    $permissions = urlencode(
            "MERCHANT_PROFILE_READ " .
            "PAYMENTS_WRITE_ADDITIONAL_RECIPIENTS " .
            "PAYMENTS_WRITE_IN_PERSON " .
            "PAYMENTS_WRITE " .
            "PAYMENTS_READ"
    );

    $redirect_url = "https://connect.squareup.com/oauth2/authorize" .
            '?client_id=' . APPLICATION_ID .
            '&scope=' . $permissions .
            '&state=' . $_SESSION['auth_state'];
    echo '<script>window.location.replace("' . $redirect_url . '");</script>';
    exit();
} else {
    header("HTTP/1.1 404 Not Found");
    exit();
}
