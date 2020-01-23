<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Ex1n2.aspx.cs" Inherits="_3107.Ex1" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
<script type="text/javascript">
    function changeColor() {
        var btn = document.getElementById("Button3");
        btn.style = "background-color:Yellow;";
        return;
    }
    function changeColor2() {
        var btn = document.getElementById("Button3");
        btn.style = "background-color:Green;";
        return;
    }
    </script>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <asp:ListBox ID="ListBox1" runat="server" AutoPostBack="true" OnTextChanged="Button1_Click">
        <asp:ListItem>Air India</asp:ListItem>
        <asp:ListItem>Indigo</asp:ListItem>
        <asp:ListItem>SpiceJet</asp:ListItem>
        <asp:ListItem>GoAir</asp:ListItem>
    </asp:ListBox>
    <asp:RadioButtonList ID="RadioButtonList1" runat="server" AutoPostBack="true" OnTextChanged="Button1_Click">
        <asp:ListItem Text="Good" Value="Good"></asp:ListItem>
        <asp:ListItem Text="Ok" Value="Ok"></asp:ListItem>
        <asp:ListItem Text="Bad" Value="Bad"></asp:ListItem>
    </asp:RadioButtonList>
    <asp:Button ID="Button1" runat="server" Text="Send Feedback!" OnClick="Button1_Click" />
    <br /><asp:Label ID="Label1" runat="server" Text=""></asp:Label>
    <br /><asp:Button ID="Button2" runat="server" Text="Exercise2" 
        BackColor="Green" OnClick="Button2_Click"/>
    <input id="Button3" type="button" value="button" onmouseover="changeColor();" onmouseout="changeColor2();" style="background-color:Green;"/>
    
</asp:Content>
