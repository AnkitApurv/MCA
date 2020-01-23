<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Customer.aspx.cs" Inherits="L9_10.WebForm2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <h1>
        Customer Details</h1>
    <form id="form1" runat="server">
    <p>
        <asp:GridView ID="GridView1" runat="server" AllowPaging="True" 
            AutoGenerateColumns="False" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="cust_name" HeaderText="cust_name" 
                    SortExpression="cust_name" />
                <asp:BoundField DataField="cust_street" HeaderText="cust_street" 
                    SortExpression="cust_street" />
                <asp:BoundField DataField="cust_city" HeaderText="cust_city" 
                    SortExpression="cust_city" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
            SelectCommand="SELECT [cust_name], [cust_street], [cust_city] FROM [customer]">
        </asp:SqlDataSource>
    </p>
    <div>
    
    </div>
    <asp:LinkButton ID="LinkButton1" runat="server" onclick="LinkButton1_Click">Back</asp:LinkButton>
    </form>
</body>
</html>
