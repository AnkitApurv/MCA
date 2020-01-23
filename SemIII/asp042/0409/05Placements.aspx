<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="05Placements.aspx.cs" Inherits="_0409._05Placements" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body style="font-family:Sans-Serif;">
    <form id="form1" runat="server">
    <div>
        <asp:Wizard ID="Wizard1" runat="server" ActiveStepIndex="0" OnFinishButtonClick="save">
            <WizardSteps>



                <asp:WizardStep ID="WizardStep1" runat="server" Title="Step 1">
                <table style="width: 100%;">
            <tr>
                <td>
                    <asp:Label ID="Label0" runat="server" AssociatedControlID="tName" Text="Name"></asp:Label>
                </td>
                <td>
                    <asp:TextBox runat="server" ID="tName"></asp:TextBox>
                </td>
                <td>
                    &nbsp
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="Label1" runat="server" AssociatedControlID="tAddress" Text="Address"></asp:Label>
                </td>
                <td>
                    <asp:TextBox runat="server" ID="tAddress" TextMode="MultiLine"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="Label2" runat="server" AssociatedControlID="tDOB" Text="DOB"></asp:Label>
                </td>
                <td>
                    <asp:TextBox runat="server" ID="tDOB" TextMode="Date"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="Label3" runat="server" AssociatedControlID="rlGender" Text="Gender"></asp:Label>
                </td>
                <td>
                    <asp:RadioButtonList ID="rlGender" runat="server">
                        <asp:ListItem Text="Male" Value="M"></asp:ListItem>
                        <asp:ListItem Text="Female" Value="F"></asp:ListItem>
                    </asp:RadioButtonList>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
            </table>
                </asp:WizardStep>



                <asp:WizardStep ID="WizardStep2" runat="server" Title="Step 2">
            <table>
                <tr>
                <td>
                    <asp:Label ID="Label4" runat="server" AssociatedControlID="tX" Text="X"></asp:Label>
                </td>
                <td>
                    <asp:TextBox runat="server" ID="tX"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="Label5" runat="server" AssociatedControlID="tXII" Text="XII"></asp:Label>
                </td>
                <td>
                    <asp:TextBox runat="server" ID="tXII"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="Label6" runat="server" AssociatedControlID="tUG" Text="UG"></asp:Label>
                </td>
                <td>
                    <asp:TextBox runat="server" ID="tUG"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="Label7" runat="server" AssociatedControlID="tPG" Text="PG"></asp:Label>
                </td>
                <td>
                    <asp:TextBox runat="server" ID="tPG"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
        </table>
                </asp:WizardStep>
                
                
                
                <asp:WizardStep ID="WizardStep3" runat="server" Title="Step 3">
                <table>
                <tr>
                <td>
                    <asp:Label ID="Label8" runat="server" AssociatedControlID="tAchievements" Text="Achievements"></asp:Label>
                </td>
                <td>
                    <asp:TextBox runat="server" ID="tAchievements"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="Label9" runat="server" AssociatedControlID="tRef1" Text="References"></asp:Label>
                </td>
                <td>
                    <asp:TextBox runat="server" ID="tRef1" TextMode="Email"></asp:TextBox><br />
                    <asp:TextBox runat="server" ID="tRef2" TextMode="Email"></asp:TextBox><br />
                    <asp:TextBox runat="server" ID="tRef3" TextMode="Email"></asp:TextBox>
                </td>
                <td>
                    &nbsp;
                </td>
            </tr>
        </table>
                </asp:WizardStep>



            </WizardSteps>
        </asp:Wizard>
        
            
    </div>
    </form>
</body>
</html>
