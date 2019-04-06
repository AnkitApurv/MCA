<?php
include_once("connect.php");
function delete($id) {
    $conn = $GLOBALS["conn"];
    $sql = "DELETE FROM books WHERE id = " . $id . ";";
    $result = $conn->query($sql);
	
    return;
}
if( isset($_GET["id"]) )
    delete($_GET["id"]);
header("Location : ./show.php");
?>