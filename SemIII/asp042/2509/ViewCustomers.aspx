<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ViewCustomers.aspx.cs" Inherits="_2509.ViewCustomers" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
            SelectCommand="SELECT [customer_id], [customer_name], [customer_street], [customer_city] FROM [customer]"></asp:SqlDataSource>
        <asp:GridView ID="GridView1" runat="server" AllowPaging="True" 
            AutoGenerateColumns="False" DataKeyNames="customer_id" 
            DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="customer_id" HeaderText="customer_id" 
                    InsertVisible="False" ReadOnly="True" SortExpression="customer_id" />
                <asp:BoundField DataField="customer_name" HeaderText="customer_name" 
                    SortExpression="customer_name" />
                <asp:BoundField DataField="customer_street" HeaderText="customer_street" 
                    SortExpression="customer_street" />
                <asp:BoundField DataField="customer_city" HeaderText="customer_city" 
                    SortExpression="customer_city" />
            </Columns>
        </asp:GridView>
    </div>
    </form>
</body>
</html>
