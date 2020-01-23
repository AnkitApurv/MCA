<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApp1.WebForm1" Trace="true" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <style type="text/css">
        .body { font-family: Sans-Serif; }
    </style>
    <title></title>
</head>
<body style="font-family:Sans-Serif;">
    <form id="form1" runat="server">
    <div>
        <asp:Table ID="Table1" runat="server" CellPadding="5" CellSpacing="5">
            <asp:TableRow>
                <asp:TableCell><asp:Label ID="Label1" runat="server" Text="SomethingSomething"></asp:Label></asp:TableCell>
                <asp:TableCell><asp:Button ID="Bt1" runat="server" onclick="Bt1_Click" Text="NoClicks!" /></asp:TableCell>
                <asp:TableCell><asp:TextBox ID="TextBox1" runat="server"></asp:TextBox></asp:TableCell>
                <asp:TableCell><asp:TextBox ID="TextBox2" runat="server"></asp:TextBox></asp:TableCell>
                <asp:TableCell><asp:Label ID="Label2" runat="server"></asp:Label></asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell>
                    <asp:RadioButton id="rdlMagazine" Text="Magazine Article" GroupName="Source" Runat="server" /><br />
                    <asp:RadioButton id="rdlTelevision" Text="Television Program" GroupName="Source" Runat="server" /> <br />
                    <asp:RadioButton id="rdlOther" Text="Other Source" GroupName="Source" Runat="server" /> 
                </asp:TableCell>
                <asp:TableCell>
                    <asp:Button ID="Btn3" runat="server" Text="Radios" OnClick="Btn3_Click"/>
                </asp:TableCell>
                <asp:TableCell> 
                    <asp:Label ID="Label3" runat="server" Text=""></asp:Label>
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell>
                    <asp:Label ID="Label4" runat="server" Text="Time"></asp:Label>
                </asp:TableCell>
                <asp:TableCell>
                    <asp:Button ID="Button1" runat="server" Text="Time?" OnClick="Button1_Click" />
                </asp:TableCell>
                <asp:TableCell>
                    <asp:LinkButton ID="LinkButton1" runat="server" OnClientClick="return confirm(‘Are you sure?’);" OnClick="lnkBtn1_Click">LinkButton</asp:LinkButton></asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell>
                    <asp:Label ID="Label5" runat="server" Text="0"></asp:Label>
                </asp:TableCell>
                <asp:TableCell>
                    <asp:Button ID="Button2" runat="server" Text="Button" OnClick="Button2_Click" />
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell>
                    <asp:Button ID="Button4" runat="server" Text="0" OnClick="Button3_Click" />
                </asp:TableCell>
                <asp:TableCell>
                    <asp:Button ID="Button3" runat="server" Text="0" OnClick="Button3_Click" />
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell RowSpan="2"><asp:ImageButton ImageAlign="Middle" ID="img1" ImageUrl="img01.gif" runat="server" OnClick="igBt2_Click"/></asp:TableCell>
                <asp:TableCell RowSpan="2"><asp:Label ID="Label7" runat="server" Text=""></asp:Label></asp:TableCell>
            </asp:TableRow>
        </asp:Table>
    </div>
    </form>
</body>
</html>
