<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="06Dept.aspx.cs" Inherits="_1109._06Dept" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
    </div>
    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
        DataKeyNames="DeptName" DataSourceID="SqlDataSource1">
        <Columns>
            <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" />
            <asp:TemplateField HeaderText="DeptName" SortExpression="DeptName">
                <EditItemTemplate>
                    <asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("DeptName") %>'></asp:TextBox>
                </EditItemTemplate>
                <FooterTemplate>
                    <asp:TextBox ID="tDept" runat="server"></asp:TextBox>
                </FooterTemplate>
                <ItemTemplate>
                    <asp:Label ID="Label1" runat="server" Text='<%# Bind("DeptName") %>'></asp:Label>
                </ItemTemplate>
            </asp:TemplateField>
        </Columns>
    </asp:GridView>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
        ConflictDetection="CompareAllValues" 
        ConnectionString="<%$ ConnectionStrings:empdept %>" 
        DeleteCommand="DELETE FROM [Dept] WHERE [DeptName] = @original_DeptName" 
        InsertCommand="INSERT INTO [Dept] ([DeptName]) VALUES (@DeptName)" 
        OldValuesParameterFormatString="original_{0}" 
        SelectCommand="SELECT [DeptName] FROM [Dept]">
        <DeleteParameters>
            <asp:Parameter Name="original_DeptName" Type="String" />
        </DeleteParameters>
        <InsertParameters>
            <asp:Parameter Name="DeptName" Type="String" />
        </InsertParameters>
    </asp:SqlDataSource>
    </form>
</body>
</html>
