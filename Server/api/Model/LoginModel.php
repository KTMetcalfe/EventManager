<?php
require_once "/eventmanager/Server/api/Model/Database.php";

class LoginModel extends Database {
    public function getApplication($user) {
        return $this->select(sprintf("SELECT * FROM applications WHERE username='%s'", $user));
    }
}