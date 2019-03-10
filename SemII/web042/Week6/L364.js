function validate() {
	
	if(checkEmpty() && checkIsValid())
		window.location.href = "./L63.html";	// similar behavior as clicking on a link
	return;
}

function checkEmpty() {
	var isFilled = false;
	if(document.getElementById("txtFname").value.trim() === "")
	{
		document.getElementById("msgFname").innerHTML = "We need your first name!<br/>";
		document.getElementById("msgFname").style.visibility = "visible";
		isFilled = false;
	}
	else
	{
		document.getElementById("msgFname").style.visibility = "hidden";
		isFilled = true;
	}
	
	if(document.getElementById("txtLname").value.trim() === "")
	{
		document.getElementById("msgLname").innerHTML = "We need your last name!<br/>";
		document.getElementById("msgLname").style.visibility = "visible";
		isFilled = false;
	}
	else
	{
		document.getElementById("msgLname").style.visibility = "hidden";
		isFilled = true;
	}
	
	if(document.getElementById("txtEmail").value.trim() === "")
	{
		document.getElementById("msgEmail").innerHTML = "We need your email!<br/>";
		document.getElementById("msgEmail").style.visibility = "visible";
		isFilled = false;
	}
	else
	{
		document.getElementById("msgEmail").style.visibility = "hidden";
		isFilled = true;
	}
	
	if(document.getElementById("passwdOriginal").value.trim() === "" || document.getElementById("passwdConfirm").value.trim() === "" )
	{
		document.getElementById("msgPasswd").innerHTML = "We need your password!<br/>";
		document.getElementById("msgPasswd").style.visibility = "visible";
		isFilled = false;
	}
	else
	{
		document.getElementById("msgPasswd").style.visibility = "hidden";
		isFilled = true;
	}
	return isFilled;
}

function checkIsValid() {
	var isValid = false;
	var email = document.getElementById("txtEmail").value.trim();
	var passwdOriginal = document.getElementById("passwdOriginal").value.trim();
	var passwdConfirm = document.getElementById("passwdConfirm").value.trim();
	
	if( (isValid = email.match(/^([\-\$]*\w+[\-\$]*)*gmail\.(com|in)$/)) )
		document.getElementById("msgEmail").style.visibility = "hidden";
	else
	{
		document.getElementById("msgEmail").innerHTML = "Your email does not seem right...<br/>";
		document.getElementById("msgEmail").style.visibility = "visible";
	}
	
	if( (isValid = (passwdOriginal === passwdConfirm) ) )
		document.getElementById("msgPasswdConf").style.visibility = "hidden";
	else
	{
		document.getElementById("msgPasswdConf").innerHTML = "Your password does not seem to match...<br/>";
		document.getElementById("msgPasswdConf").style.visibility = "visible";
	}
	
	if( (isValid = passwdOriginal.match(/^\w(8, 12)$/) ) )
		document.getElementById("msgPasswd").style.visibility = "hidden";
	else
	{
		document.getElementById("msgPasswd").innerHTML = "Passwords need to be 8 to 12 characters...<br/>";
		document.getElementById("msgPasswd").style.visibility = "visible";
	}
	
	return isValid;
}

//txtFname txtLname txtEmail passwdOriginal passwdConfirm
//msgFname msgLname msgLmail msgPasswd