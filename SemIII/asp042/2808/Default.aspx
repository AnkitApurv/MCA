<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeBehind="Default.aspx.cs" Inherits="_2808._Default" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
        DataKeyNames="employeeId" DataSourceID="SqlDataSource1" AllowPaging="True" 
        style="font-family: Arial, Helvetica, sans-serif" CellPadding="4" 
        ForeColor="#333333" GridLines="None">
        <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
        <Columns>
            <asp:CommandField AccessibleHeaderText="Options" HeaderText="Options" 
                ShowDeleteButton="True" ShowEditButton="True" ShowHeader="True" 
                ShowInsertButton="True" />
            <asp:BoundField DataField="employeeId" HeaderText="employeeId" 
                InsertVisible="False" ReadOnly="True" SortExpression="employeeId" />
            <asp:BoundField DataField="name" HeaderText="name" SortExpression="name" />
            <asp:BoundField DataField="designation" HeaderText="designation" 
                SortExpression="designation" />
            <asp:BoundField DataField="city" HeaderText="city" SortExpression="city" />
        </Columns>
        <EditRowStyle BackColor="#999999" />
        <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
        <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
        <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
        <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
        <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
        <SortedAscendingCellStyle BackColor="#E9E7E2" />
        <SortedAscendingHeaderStyle BackColor="#506C8C" />
        <SortedDescendingCellStyle BackColor="#FFFDF8" />
        <SortedDescendingHeaderStyle BackColor="#6F8DAE" />
    </asp:GridView>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
        ConnectionString="<%$ ConnectionStrings:EmployeeDB %>" 
        
        SelectCommand="SELECT * FROM [Employee]" 
        DeleteCommand="DELETE FROM [Employee] WHERE [employeeId] = @employeeId" 
        InsertCommand="INSERT INTO [Employee] ([name], [designation], [city]) VALUES (@name, @designation, @city)" 
    UpdateCommand="UPDATE [Employee] SET [name] = @name, [designation] = @designation, [city] = @city WHERE [employeeId] = @employeeId">
        <DeleteParameters>
            <asp:Parameter Name="employeeId" Type="Int32" />
        </DeleteParameters>
        <InsertParameters>
            <asp:Parameter Name="name" Type="String" />
            <asp:Parameter Name="designation" Type="String" />
            <asp:Parameter Name="city" Type="String" />
        </InsertParameters>
        <UpdateParameters>
            <asp:Parameter Name="name" Type="String" />
            <asp:Parameter Name="designation" Type="String" />
            <asp:Parameter Name="city" Type="String" />
            <asp:Parameter Name="employeeId" Type="Int32" />
        </UpdateParameters>
    </asp:SqlDataSource>
</asp:Content>
