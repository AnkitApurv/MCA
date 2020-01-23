<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="RegForm.aspx.cs" Inherits="_01.RegForm" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table style="width: 100%;">
            <tr>
                <td>
                    <asp:Label ID="Label1" runat="server" Text="Name" AssociatedControlID="tbName"></asp:Label>
                </td>
                <td>
                    <asp:TextBox ID="tbName" runat="server"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="Label2" runat="server" Text="Designation" AssociatedControlID="tbDesig"></asp:Label>
                </td>
                <td>
                    <asp:TextBox ID="tbDesig" runat="server"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="Label3" runat="server" Text="Email" AssociatedControlID="tbEmail"></asp:Label>
                </td>
                <td>
                    <asp:TextBox ID="tbEmail" runat="server" TextMode="Email"></asp:TextBox>
                </td>
                <td>
                <span>forgot regex</span>
                    <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ErrorMessage="Email must belong to 'manipal.edu'" ControlToValidate="tbEmail" ValidationExpression=""></asp:RegularExpressionValidator>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="Label4" runat="server" Text="Mobile" AssociatedControlID="tbMobile"></asp:Label>
                </td>
                <td>
                    <asp:TextBox ID="tbMobile" runat="server" MaxLength="10" TextMode="Phone"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Button ID="Button1" runat="server" Text="Submit" PostBackUrl="~/MsgPage.aspx" CausesValidation="true" />
                </td>
                <td>
                    <asp:Button ID="Button2" runat="server" Text="Cancel" PostBackUrl="~/MsgPage.aspx" CausesValidation="false"/><span>simple redirect would have served, no postback was necessary</span>
                </td>
                <td>
                    <asp:Button ID="Button3" runat="server" Text="Clear" OnCommand="clearPage" CausesValidation="false" />
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
