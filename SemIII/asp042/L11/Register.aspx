<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Register.aspx.cs" Inherits="L11.Register" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
<table>
    <tr>
        <td>Username</td>
        <td><asp:TextBox runat="server" ID="tUid"></asp:TextBox></td>
    </tr>
    <tr>
        <td>Password</td>
        <td><asp:TextBox runat="server" ID="tPasswd" TextMode="Password"></asp:TextBox></td>
    </tr>
    <tr>
        <td><asp:Button runat="server" ID="bRegister" OnCommand="createUser" Text="Register"/></td>
        <td><asp:Label runat="server" ID="lStatus"></asp:Label></td>
    </tr>
    <tr>
        <td><a href="Login.aspx">Login</a></td>
    </tr>
</table>
</asp:Content>
