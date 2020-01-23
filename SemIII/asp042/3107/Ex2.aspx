<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Ex2.aspx.cs" Inherits="_3107.Ex2" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <table style="width: 100%;">
        <tr>
            <td>
                <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="~/a.png" OnClick="ImgBtn_OnClick" />
            </td>
            <td>
                <asp:ImageButton ID="ImageButton2" runat="server" ImageUrl="~/b.png" OnClick="ImgBtn_OnClick" />
            </td>
            <td>
                <asp:ImageButton ID="ImageButton3" runat="server" ImageUrl="~/c.png" OnClick="ImgBtn_OnClick" />
            </td>
            <td>
                <asp:ImageButton ID="ImageButton4" runat="server" ImageUrl="~/d.png" OnClick="ImgBtn_OnClick" />
            </td>
        </tr>
        <tr>
            <td rowspan="4">
                <asp:ImageButton ID="ImageButton5" runat="server" ImageUrl="~/blank.png" OnClick="ImgBtn_OnClick" />
            </td>
        </tr>
    </table>
    
</asp:Content>
