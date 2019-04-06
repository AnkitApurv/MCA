<!-- 
	@author Ankit Apurv
	@date 27/03/2019
	@desc CRUD application for
        book information such as accession number, title, authors, edition and publisher
        user must also be able to search for a book with the title specified
	using PHP
-->
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>L11 CRUD</title>
    <link rel="stylesheet" type="text/css" href="./table.css"></style>
</head>
<body>
    <a href="./add.php">Add New Entry</a>
</body>
<?php
include_once("connect.php");

function fetchAll() {
    $tableHeader = "<table cellspacing='0'> <thead>
    <tr>
        <th>ISBN</th>
        <th>Title</th>
        <th>Author</th>
        <th>Edition</th>
        <th>Publisher</th>
        <th>Operations</th>
    </tr> </thead> <tbody>";
    $tableFooter = "</tbody> </table>";

    $conn = $GLOBALS["conn"];
    $sql = "SELECT * FROM books;";
    $result = $conn->query($sql);

    echo($tableHeader);
    while($row = $result->fetch_array()){
        echo("<tr>");
        echo("<td>" . $row["isbn"] . "</td>");
        echo("<td>" . $row["title"] . "</td>");
        echo("<td>" . $row["author"] . "</td>");
        echo("<td>" . $row["edition"] . "</td>");
        echo("<td>" . $row["publisher"] . "</td>");
        echo("<td>" . "<a href='update.php?id=". $row['id'] ."'>Update</a>   "
        . "<a href='delete.php?id=". $row['id'] ."'>Delete</a>" . "</td>");
        echo("</tr>");
    }
    echo($tableFooter);
    $result->free();

    return;
}

fetchAll();
?>
</html>