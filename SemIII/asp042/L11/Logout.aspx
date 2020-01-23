<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Logout.aspx.cs" Inherits="L11.Logout" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
<table>
    <tr>
        <td><asp:Label runat="server" ID="lUid"></asp:Label></td>
        <td><asp:Button runat="server" ID="bLogout" Text="Logout" OnCommand="logoutUser" /></td>
    </tr>
</table>
    </asp:Content>
