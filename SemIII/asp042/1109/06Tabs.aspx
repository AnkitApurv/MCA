<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="06Tabs.aspx.cs" Inherits="_1109._06Tabs" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <link href="~/Styles/Site.css" rel="stylesheet" type="text/css" />
</head>
<body>
    <form id="form1" runat="server">
    <div class="header clear hideSkiplink">
        <asp:Menu ID="Menu1" runat="server" CssClass="menu" Orientation="Horizontal" OnMenuItemClick="changeView">
        <Items>
            <asp:MenuItem Text="Home" Selected="true" ></asp:MenuItem>
            <asp:MenuItem Text="About"></asp:MenuItem>
            <asp:MenuItem Text="Contacts"></asp:MenuItem>
            <asp:MenuItem Text="Courses"></asp:MenuItem>
        </Items>
        </asp:Menu>
    </div>
    <div class="page">
        <asp:MultiView ID="MultiView1" runat="server">
            <asp:View ID="Home" runat="server">Home</asp:View>
            <asp:View ID="About" runat="server">About</asp:View>
            <asp:View ID="Contacts" runat="server">Contacts</asp:View>
            <asp:View ID="Courses" runat="server">Courses</asp:View>
        </asp:MultiView>
    </div>
    </form>
</body>
</html>
