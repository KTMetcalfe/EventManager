<?php
require_once "/eventmanager/Server/api/Model/Database.php";

class LocationModel extends Database {
    public function getLocationById($database, $location_id) {
        $location_names = $this->select(sprintf("SELECT name from %s.locations WHERE id=%d", $database, $location_id));
        return $location_names[0]['name'];
    }
}