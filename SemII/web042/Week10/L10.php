<!DOCTYPE html>
<!-- 
	@author Ankit Apurv
	@date 27/03/2019
	@desc to perform following tasks on Gmail registration form
		1. form validation
		2. insert to MySQL DB
	using PHP
-->
<html>
<head>
	<title>Google Account - Create</title><link rel="icon" href="./images/logo.png"/>
	<style></style>
	<script></script>
	<?php
		$fname = $lname = $email = $passwd = $confpasswd = "";
	?>
</head>
<body style="font-family : sans-serif; align: center">
	<div style="border-width:1px; border-color:grey">

	<form id="registration" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="POST">

	<table align=center cellpadding=15% cellspacing=0px border=0px width="40%" frame=box>
	<tr>
		<td colspan=2><img src="./images/logo.png"></td>
		<td colspan=2 rowspan=8><img src="./images/googleAccount.png"></td>
	</tr>
	<tr>
		<td colspan=2><font size=5 weight=600>Create your Google Account</font></td>
	</tr>
	<tr>
		<td colspan=1><input type=text name="fname" placeholder="First Name" value="<?php echo $fname;?>" /></td>
		<td colspan=1><input type=text name="lname" placeholder="Last Name" value="<?php echo $lname;?>" /></td>
	</tr>
	<tr>
		<td colspan=2>
			<input type=email name="email" style="width: 98%;" value="<?php echo $email;?>" placeholder="Username                                               @gmail.com"/><br/>
			<sup><font color="grey" size=2>You can use letters, numbers & periods.</font></sup>
		</td>
	</tr>
	<tr>
		<td colspan=2>
			<strong><font color="blue">Use my current email address instead.</font></strong>
		</td>
	</tr>
	<tr>
		<td colspan=2>
			<input type=password name="passwd" style="width: 38%;" value="<?php echo $passwd;?>" placeholder="Password"/>
			 &nbsp &nbsp 
			 <input type=password name="confpasswd" style="width: 38%;" value="<?php echo $confpasswd;?>" placeholder="Confirm"/><img src="./images/hide.png"/>
			<br/>
			<sup><font color="grey" size=2>Use 8 to 20 characters with a mix of letters, numbers or symbols.</font></sup>
		</td>
	</tr>
	<tr>
		<td colspan=1><strong><font color="blue">Sign in instead.</font></strong></td>
		<td colspan=1 align=right><input type=submit value ="Next" style="background-color:blue; font-color:white;"/></td>
	</tr>
	<tr>
		<td colspan=2><font color="grey" size=2>English (United Kingdom)</font></td>
		<td colspan=2><font color="grey" size=2>Help             Privacy           Terms</font></td>
	</tr>
	</table>
	</form>
	</div>

<?php
	function validateForm() {
		$errors = "";
		$isValid = true;
	
		if( (!preg_match("/^[a-zA-Z]*$/", $_POST["fname"])) || (!preg_match("/^[a-zA-Z ]*$/", $_POST["lname"])) ) {
			$errors += "Name may only have alphabets.<br/>";
			$isValid = false;
		}
	
		if( !preg_match("/^([a-z0-9_\.-]+)@([\da-z\.-]+)\.([a-z\.]{2,6})$/", $_POST["email"]) ) {
			$errors += "Invalid Email.<br/>";
			$isValid = false;
		}
		
		if( !preg_match("/^([\w\-]{8,20})$/", $_POST["passwd"]) ) {
			$errors += "Password needs to be 8 to 20 characters long.<br/>";
			$isValid = false;
		}
	
		if($_POST["passwd"] != $_POST["confpasswd"]) {
			$errors += "Passwords do not match.<br/>";
			$isValid = false;
		}
		
		echo $errors;
		return $isValid;
	}
	
	function insertData() {
		$servername = "localhost";
		$username = "root";
		$password = "";
		$dbname = "test";
		$success = false;
	
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
	
		// Check connection
		if($conn->connect_error) {
			die("Connection failed: " . $conn->connect_error);
		}
	
		//create table
		$sql = "CREATE TABLE IF NOT EXISTS gmail (
			id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
			fname VARCHAR(30) NOT NULL,
			lname VARCHAR(30) NOT NULL,
			email VARCHAR(50),
			passwd VARCHAR(20));";
		if($conn->query($sql) === true)
			$success = true;
		
		//insert data
		$fname = $conn->real_escape_string($_POST['fname']);
		$lname = $conn->real_escape_string($_POST['lname']);
		$email = $conn->real_escape_string($_POST['email']);
		$passwd = $conn->real_escape_string($_POST['passwd']);
		$sql = "INSERT INTO gmail (fname, lname, email, passwd) VALUES ('$fname', '$lname', '$email', '$passwd');";
		if($conn->query($sql) === true)
			$success = true;
	
		return $success;
	}

	
	if($_SERVER["REQUEST_METHOD"] == "POST") { 
		if(validateForm()) {
			if(insertData())
				echo "Account Creation Successful!";
			else
				echo "Account Creation Unsccessful!";
		}
	}
?>

</body>
</html>