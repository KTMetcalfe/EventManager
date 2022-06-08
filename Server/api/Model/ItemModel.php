<?php
require_once "/eventmanager/Server/api/Model/Database.php";

class ItemModel extends Database {
    public function getItems($database) {
        return $this->select(sprintf("SELECT * FROM %s.items", $database));
    }

    public function getItemsByLocation($database, $location_id) {
        require "/eventmanager/Server/api/Model/LocationModel.php";
        $locationModel = new LocationModel();
        $loc_name = $locationModel->getLocationById($database, $location_id);
        return $this->select(sprintf("SELECT * FROM %s.items WHERE locations LIKE '%%%s%%'", $database, $loc_name));
    }
}