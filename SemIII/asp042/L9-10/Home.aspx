<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Home.aspx.cs" Inherits="L9_10.WebForm4" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>    
        <h1>
            Home Page
        </h1>
        <p>
            <asp:LinkButton ID="LinkButton1" runat="server" onclick="LinkButton1_Click">View Customer Details</asp:LinkButton>
            <br />
            <br />
            <asp:LinkButton ID="LinkButton2" runat="server" onclick="LinkButton2_Click">Loan Records</asp:LinkButton>
            <br />
            <br />
            <asp:LinkButton ID="LinkButton3" runat="server" onclick="LinkButton3_Click">Add Payment Details</asp:LinkButton>
        </p>    
    </div>    
    </form>
</body>
</html>
