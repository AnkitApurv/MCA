<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>L11 CRUD</title>
    <link rel="stylesheet" type="text/css" href="form.css">
</head>
<body>
<a href="./show.php">View All Entries</a>
<?php
    $isbn = $title = $author = $edition = $publisher = "";
?>
    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="POST">
        <label>ISBN</label><input type=text name="isbn" value="<?php echo $isbn;?>" /><br/>
        <label>Title</label><input type=text name="title" value="<?php echo $title;?>" /><br/>
        <label>Author</label><input type=text name="author" value="<?php echo $author;?>" /><br/>
        <label>Edition</label><input type=text name="edition" value="<?php echo $edition;?>" /><br/>
        <label>Publisher</label><input type=text name="publisher" value="<?php echo $publisher;?>" /><br/>
        <input type=submit value="Add New" />
    </form>
</body>
<?php
include_once("connect.php");

function add() {
    //insert data
	$conn = $GLOBALS["conn"];
	$isbn = $conn->real_escape_string($_POST['isbn']);
	$title = $conn->real_escape_string($_POST['title']);
	$author = $conn->real_escape_string($_POST['author']);
    $edition = $conn->real_escape_string($_POST['edition']);
    $publisher = $conn->real_escape_string($_POST['publisher']);

	$sql = "INSERT INTO books (isbn, title, author, edition, publisher) VALUES ('$isbn', '$title', '$author', '$edition', '$publisher');";
	if($conn->query($sql) === true)
		return true;
}

if( isset($_POST['isbn']) )   //on form submit
    add();
header("Location : ./show.php");
?>
</html>