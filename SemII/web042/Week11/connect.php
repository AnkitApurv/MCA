<?php
//vars
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "test";
$success = false;
	
// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if($conn === false)
    die("ERROR: Could not connect. " . $conn->connect_error);
else {
    $createTable = "CREATE TABLE IF NOT EXISTS books (
        id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        isbn VARCHAR(30) NOT NULL,
        title VARCHAR(30),
        author VARCHAR(50),
        edition VARCHAR(30),
        publisher VARCHAR(20));";
    $conn->query($createTable);
}
?>