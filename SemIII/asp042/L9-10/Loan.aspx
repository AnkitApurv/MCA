<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Loan.aspx.cs" Inherits="L9_10.WebForm3" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .style1
        {
            text-align: left;
        }
    </style>
</head>
<body>
    <h1>
        Loan Records</h1>
    <p>
        &nbsp;</p>
    <form id="form1" runat="server">
    <div class="style1">
    <asp:GridView ID="GridView1" runat="server" AllowSorting="True" 
        AutoGenerateColumns="False" DataKeyNames="loan_number" 
        DataSourceID="SqlDataSource1">
        <Columns>
            <asp:BoundField DataField="loan_number" HeaderText="loan_number" 
                InsertVisible="False" ReadOnly="True" SortExpression="loan_number" />
            <asp:BoundField DataField="amount" HeaderText="amount" 
                SortExpression="amount" />
            <asp:BoundField DataField="branch_name" HeaderText="branch_name" 
                SortExpression="branch_name" />
        </Columns>
    </asp:GridView>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
        SelectCommand="SELECT * FROM [loan]"></asp:SqlDataSource>
        <br />
    <asp:LinkButton ID="LinkButton1" runat="server" onclick="LinkButton1_Click">Back</asp:LinkButton>
    </div>
    </form>
</body>
</html>
