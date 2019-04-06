<!-- session -->
<?php
	session_start();
	$_SESSION['visitCount']	+= 1;
?>
<!DOCTYPE html>
<html>
<head>
	<title>02 Session Count</title>
</head>
<body>
<?php
	echo "Visit count : " . $_SESSION['visitCount'];
?>
<br/><a href="./02Session1.php">Session 1</a>
</body>
</html>