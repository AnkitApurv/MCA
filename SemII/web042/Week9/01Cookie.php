<!-- timestamp cookie -->
<!DOCTYPE html>
<?php
	$lastVisit;
	if( isset($_COOKIE['lastVisit']) ) {
		$lastVisit = $_COOKIE['lastVisit'];
	}
	$time = date("H:i:s, l, d/m/Y");
	$expiry = strtotime("+1 Month");
	setcookie("lastVisit", $time, $expiry);
?>
<html>
<head>
	<meta charst="utf-8"/>
	<title>01 Cookie Timestamp</title>
</head>
<body>
<?php
	if( isset($_COOKIE['lastVisit']) ) {
		echo "Last visit : " . $lastVisit;
	}
	else {
		echo "First visit";
	}
?>
</body>
</html>