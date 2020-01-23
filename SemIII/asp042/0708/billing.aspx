<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="billing.aspx.cs" Inherits="_0708.billing" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="true" OnSelectedIndexChanged="displayImg">
            <asp:ListItem Value="4" Text="HB Pencil"></asp:ListItem>
            <asp:ListItem Value="5" Text="A4 Sheet"></asp:ListItem>
            <asp:ListItem Value="3" Text="Writing Pen"></asp:ListItem>
            <asp:ListItem Value="30" Text="Signature Pen"></asp:ListItem>
            <asp:ListItem Value="10" Text="Coloring Sheet"></asp:ListItem>
        </asp:DropDownList>
        <asp:Image ID="Image1" runat="server" ImageUrl="./Images/blank.png"/>
        <asp:Button ID="Button1" runat="server" Text="Total" OnClick="total" />
        <asp:Label ID="Label1" runat="server" Text="0"></asp:Label><br />
        Quantity <asp:TextBox ID="TextBox1" runat="server" TextMode="Number" Enabled="False" OnTextChanged="generateBill"></asp:TextBox><br />
        <asp:Label ID="Label2" runat="server" Text=""></asp:Label>
    </div>
    </form>
</body>
</html>
