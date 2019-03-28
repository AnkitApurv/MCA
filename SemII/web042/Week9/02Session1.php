<!-- session -->
<?php
	session_start();
?>
<!DOCTYPE html>
<html>
<head>
	<title>02 Session Count</title>
</head>
<body>
<?php
	$_SESSION['visitCount'];
	$_SESSION['visitCount']	+= 1;
	echo "Visit count : " . $_SESSION['visitCount'];
?>
<br/><a href="./02Session2.php">Session 2</a>
</body>
</html>