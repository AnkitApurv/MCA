<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ViewLoans.aspx.cs" Inherits="_2509.ViewLoans" %>

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
            SelectCommand="SELECT [loan_number], [amount], [loan_branch] FROM [loan]"></asp:SqlDataSource>
        <asp:GridView ID="GridView1" runat="server" AllowSorting="True" 
            AutoGenerateColumns="False" DataKeyNames="loan_number" 
            DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="loan_number" HeaderText="loan_number" 
                    InsertVisible="False" ReadOnly="True" SortExpression="loan_number" />
                <asp:BoundField DataField="amount" HeaderText="amount" 
                    SortExpression="loan_number" />
                <asp:BoundField DataField="loan_branch" HeaderText="loan_branch" 
                    SortExpression="loan_number" />
            </Columns>
        </asp:GridView>
    </div>
    </form>
</body>
</html>
