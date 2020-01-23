<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="06Emp.aspx.cs" Inherits="_1109._06Emp" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:GridView ID="GridView1" runat="server" AllowPaging="True" 
            AllowSorting="True" AutoGenerateColumns="False" DataKeyNames="EmpId" 
            DataSourceID="SqlDataSource1" ShowFooter="True">
            <Columns>
                <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" />
                <asp:TemplateField HeaderText="EmpId" InsertVisible="False" 
                    SortExpression="EmpId">
                    <EditItemTemplate>
                        <asp:Label ID="Label1" runat="server" Text='<%# Eval("EmpId") %>'></asp:Label>
                    </EditItemTemplate>
                    <FooterTemplate>
                        <asp:LinkButton ID="LinkButton1" runat="server" oncommand="LinkButton1_Command">Insert</asp:LinkButton>
                    </FooterTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label3" runat="server" Text='<%# Bind("EmpId") %>'></asp:Label>
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Name" SortExpression="Name">
                    <EditItemTemplate>
                        <asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("Name") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <FooterTemplate>
                        <asp:TextBox ID="TextBox3" runat="server" ontextchanged="TextBox3_TextChanged"></asp:TextBox>
                    </FooterTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label1" runat="server" Text='<%# Bind("Name") %>'></asp:Label>
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="DeptName" SortExpression="DeptName">
                    <EditItemTemplate>
                        <asp:DropDownList ID="DropDownList2" runat="server" 
                            DataSourceID="SqlDataSource2" DataTextField="DeptName" 
                            DataValueField="DeptName" SelectedValue='<%# Bind("DeptName") %>'>
                        </asp:DropDownList>
                    </EditItemTemplate>
                    <FooterTemplate>
                        <asp:DropDownList ID="DropDownList1" runat="server" 
                            DataSourceID="SqlDataSource2" DataTextField="DeptName" 
                            DataValueField="DeptName" 
                            onselectedindexchanged="DropDownList1_SelectedIndexChanged">
                        </asp:DropDownList>
                    </FooterTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label2" runat="server" Text='<%# Bind("DeptName") %>'></asp:Label>
                    </ItemTemplate>
                </asp:TemplateField>
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConflictDetection="CompareAllValues" 
            ConnectionString="<%$ ConnectionStrings:empdept %>" 
            DeleteCommand="DELETE FROM [Emp] WHERE [EmpId] = @original_EmpId AND [Name] = @original_Name AND [DeptName] = @original_DeptName" 
            InsertCommand="INSERT INTO [Emp] ([Name], [DeptName]) VALUES (@Name, @DeptName)" 
            OldValuesParameterFormatString="original_{0}" 
            SelectCommand="SELECT * FROM [Emp]" 
            UpdateCommand="UPDATE [Emp] SET [Name] = @Name, [DeptName] = @DeptName WHERE [EmpId] = @original_EmpId AND [Name] = @original_Name AND [DeptName] = @original_DeptName">
            <DeleteParameters>
                <asp:Parameter Name="original_EmpId" Type="Int32" />
                <asp:Parameter Name="original_Name" Type="String" />
                <asp:Parameter Name="original_DeptName" Type="String" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="Name" Type="String" />
                <asp:Parameter Name="DeptName" Type="String" />
            </InsertParameters>
            <UpdateParameters>
                <asp:Parameter Name="Name" Type="String" />
                <asp:Parameter Name="DeptName" Type="String" />
                <asp:Parameter Name="original_EmpId" Type="Int32" />
                <asp:Parameter Name="original_Name" Type="String" />
                <asp:Parameter Name="original_DeptName" Type="String" />
            </UpdateParameters>
        </asp:SqlDataSource>
    </div>
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
        ConnectionString="<%$ ConnectionStrings:empdept %>" 
        SelectCommand="SELECT [DeptName] FROM [Dept]"></asp:SqlDataSource>
    </form>
</body>
</html>
