<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>L11 CRUD</title>
    <link rel="stylesheet" type="text/css" href="form.css">
<?php
include_once("connect.php");

$isbn = $title = $author = $edition = $publisher = $id = "";

if( isset($_GET['id']) )
    fetch();
if( isset($_POST['isbn']) )   //on form submit
    update();
//header("Location : ./show.php");
?>
</head>
<body>
<a href="./show.php">View All Entries</a>
    <form action="<?php echo(htmlspecialchars($_SERVER["PHP_SELF"]));?>" method="POST">
        <label>ISBN</label><input type=text name="isbn" value="<?php echo $isbn;?>" /><br/>
        <label>Title</label><input type=text name="title" value="<?php echo $title;?>" /><br/>
        <label>Author</label><input type=text name="author" value="<?php echo $author;?>" /><br/>
        <label>Edition</label><input type=text name="edition" value="<?php echo $edition;?>" /><br/>
        <label>Publisher</label><input type=text name="publisher" value="<?php echo $publisher;?>" /><br/>
        <input type=submit value="Update" />
    </form>
</body>
<?php
function fetch() {
    $conn = $GLOBALS["conn"];
	$GLOBALS['id'] = $_GET["id"];
	$id = $GLOBALS['id'];
    //get data
    $sql = "SELECT * FROM books WHERE id = " . $id . ";";
    $result = $conn->query($sql);
    $row = $result->fetch_array();

    //fetch the form
    $GLOBALS['isbn'] = $row['isbn'];
    $GLOBALS['title'] = $row['title'];
    $GLOBALS['author'] = $row['author'];
    $GLOBALS['edition'] = $row['edition'];
    $GLOBALS['publisher'] = $row['publisher'];
	
	$expiry = strtotime("+1 Day");
	setcookie("id", $id, $expiry);

    return;
}

function update() {
	$conn = $GLOBALS["conn"];
	$id = $_COOKIE['id'];//$GLOBALS['id'];
	echo $GLOBALS['id'];
	$expiry = strtotime("Today");
	setcookie("id", " ", $expiry);
	
	$isbn = $conn->real_escape_string($_POST['isbn']);
    $title = $conn->real_escape_string($_POST['title']);
    $author = $conn->real_escape_string($_POST['author']);
    $edition = $conn->real_escape_string($_POST['edition']);
    $publisher = $conn->real_escape_string($_POST['publisher']);
	
	$sql = "UPDATE books SET isbn='$isbn', title='$title', author='$author', edition='$edition', publisher='$publisher' WHERE id='$id';";
	$conn->query($sql);
}
?>
</html>