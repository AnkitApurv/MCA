<%@ Page Title="Registration" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Registration.aspx.cs" Inherits="_0708.Registration" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <table style="width: 100%;">
        <tr>
            <td colspan="100%">
                Registration
            </td>
        </tr>
        <tr>
            <td>
                Name
            </td>
            <td>
                <asp:TextBox ID="TextBox1" runat="server" 
                    ValidationGroup="form"></asp:TextBox>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                    ErrorMessage="Your Name Please" ValidationGroup="form" ControlToValidate="TextBox1" ></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td>
                Gender
            </td>
            <td>
                <asp:RadioButtonList ID="RadioButtonList1" runat="server" 
                    ValidationGroup="form">
                    <asp:ListItem Text="M" Value="M"></asp:ListItem>
                    <asp:ListItem Text="F" Value="F"></asp:ListItem>
                    <asp:ListItem Text="O" Value="O"></asp:ListItem>
                </asp:RadioButtonList>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" 
                    ErrorMessage="Your Gender needed" ValidationGroup="form" ControlToValidate="RadioButtonList1"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td>
                D.O.B.
            </td>
            <td>
                <asp:Calendar ID="Calendar1" runat="server" 
                    onselectionchanged="Calendar1DOB_Selected"></asp:Calendar><br />
                <asp:TextBox ID="TextBox7" runat="server" Enabled="false" ReadOnly="true"></asp:TextBox>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" 
                    ErrorMessage="Date of Birth needed" ValidationGroup="form" ControlToValidate="TextBox7"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td>
                Password
            </td>
            <td>
                <asp:TextBox ID="TextBox2" runat="server" TextMode="Password" 
                    ValidationGroup="form"></asp:TextBox>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" 
                    ErrorMessage="Password needed" ValidationGroup="form" ControlToValidate="TextBox2"></asp:RequiredFieldValidator>
                <br />
                <!--https://stackoverflow.com/questions/23082460/regular-expression-for-13-characters-alphanumeric-string-having-exactly-3-charac-->
                <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" 
                    ErrorMessage="Invalid Passowrd" ValidationGroup="form" ControlToValidate="TextBox2" ValidationExpression="(?=^[a-zA-Z0-9]{13}$)"></asp:RegularExpressionValidator>
            </td>
        </tr>
        <tr>
            <td>
                Confirm Password
            </td>
            <td>
                <asp:TextBox ID="TextBox3" runat="server" TextMode="Password" 
                    ValidationGroup="form"></asp:TextBox>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator5" runat="server" 
                    ErrorMessage="Confirm Password needed" ValidationGroup="form" ControlToValidate="TextBox3"></asp:RequiredFieldValidator>
                    <br />
                <asp:CompareValidator ID="CompareValidator1" runat="server" 
                    ErrorMessage="Password and Confirm Password do not match." ValidationGroup="form" ControlToValidate="TextBox3" ControlToCompare="TextBox2"></asp:CompareValidator>
            </td>
        </tr>
        <tr>
            <td>
                Email
            </td>
            <td>
                <asp:TextBox ID="TextBox8" runat="server" TextMode="Email" 
                    ValidationGroup="form"></asp:TextBox>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator6" runat="server" 
                    ErrorMessage="Email needed" ValidationGroup="form" ControlToValidate="TextBox8"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td>
                Contact
            </td>
            <td>
                <asp:TextBox ID="TextBox4" runat="server" TextMode="Phone" 
                    ValidationGroup="form"></asp:TextBox>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator7" runat="server" 
                    ErrorMessage="Phone/Contact needed" ValidationGroup="form" ControlToValidate="TextBox4"></asp:RequiredFieldValidator>
            </td>
        </tr>

        <tr>
            <td>
                Address
            </td>
            <td>
                <asp:TextBox ID="TextBox5" runat="server" TextMode="MultiLine" 
                    ValidationGroup="form"></asp:TextBox>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator8" runat="server" 
                    ErrorMessage="Address needed" ValidationGroup="form" ControlToValidate="TextBox5"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td>
                Nationality
            </td>
            <td>
                <asp:TextBox ID="TextBox6" runat="server" 
                    ValidationGroup="form"></asp:TextBox>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator9" runat="server" 
                    ErrorMessage="Your domicile status" ValidationGroup="form" ControlToValidate="Textbox6"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td>
                Image
            </td>
            <td>
                <asp:FileUpload ID="PhotoUpload" runat="server" />
            </td>
            <td><asp:CustomValidator ID="PhotoTypeValidator" runat="server" ControlToValidate="PhotoUpload" OnServerValidate="validateImageType" ErrorMessage="File provided for photograph is not an image."></asp:CustomValidator>
                <br />
                <asp:CustomValidator ID="PhotoSizeValidator" runat="server" ControlToValidate="PhotoUpload" OnServerValidate="validateImageSize" ErrorMessage="Photograph provided is larger than 100KB."></asp:CustomValidator>
            </td>
        </tr>
        <tr>
            <td>
                Resume
            </td>
            <td>
                <asp:FileUpload ID="ResumeUpload" runat="server" />
            </td>
            <td><asp:CustomValidator ID="ResumeTypeValidator" runat="server" ControlToValidate="ResumeUpload" OnServerValidate="validateResumeType" ErrorMessage="File provided for resume is not a pdf."></asp:CustomValidator></td>
        </tr>
        <tr>
            <td>
                <asp:Button ID="Button1" runat="server" Text="Submit" ValidationGroup="form" 
                    onclick="Button1_Click" />
            </td>
            <td>
                <input id="Reset1" type="reset" value="Reset" />
            </td>
            <td>
                <asp:ValidationSummary ID="ValidationSummary1" runat="server" ValidationGroup="form" />
            </td>
        </tr>
    </table>
</asp:Content>
