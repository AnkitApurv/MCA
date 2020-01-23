<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Views.aspx.cs" Inherits="L7.WebForm1" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
            DataKeyNames="EID" DataSourceID="SqlDataSource1" CellPadding="4" 
            ForeColor="#333333" GridLines="None">
            <AlternatingRowStyle BackColor="White" />
            <Columns>
                <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" />
                <asp:BoundField DataField="EName" HeaderText="EName" SortExpression="EName" />
                <asp:BoundField DataField="Dept" HeaderText="Dept" SortExpression="Dept" />
            </Columns>
            <EditRowStyle BackColor="#7C6F57" />
            <FooterStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#666666" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#E3EAEB" />
            <SelectedRowStyle BackColor="#C5BBAF" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#F8FAFA" />
            <SortedAscendingHeaderStyle BackColor="#246B61" />
            <SortedDescendingCellStyle BackColor="#D4DFE1" />
            <SortedDescendingHeaderStyle BackColor="#15524A" />
        </asp:GridView>
        <br />
        <br />
        <asp:FormView ID="FormView1" runat="server" DataKeyNames="EID" 
            DataSourceID="SqlDataSource1" AllowPaging="True" CellPadding="4" 
            ForeColor="#333333">
            <EditItemTemplate>
                EID:
                <asp:Label ID="EIDLabel1" runat="server" Text='<%# Eval("EID") %>' />
                <br />
                EName:
                <asp:TextBox ID="ENameTextBox" runat="server" Text='<%# Bind("EName") %>' />
                <br />
                Dept:
                <asp:TextBox ID="DeptTextBox" runat="server" Text='<%# Bind("Dept") %>' />
                <br />
                <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" 
                    CommandName="Update" Text="Update" />
                &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" 
                    CausesValidation="False" CommandName="Cancel" Text="Cancel" />
            </EditItemTemplate>
            <EditRowStyle BackColor="#7C6F57" />
            <FooterStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <InsertItemTemplate>
                EName:
                <asp:TextBox ID="ENameTextBox" runat="server" Text='<%# Bind("EName") %>' />
                <br />
                Dept:
                <asp:TextBox ID="DeptTextBox" runat="server" Text='<%# Bind("Dept") %>' />
                <br />
                <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" 
                    CommandName="Insert" Text="Insert" />
                &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" 
                    CausesValidation="False" CommandName="Cancel" Text="Cancel" />
            </InsertItemTemplate>
            <ItemTemplate>
                EID:
                <asp:Label ID="EIDLabel" runat="server" Text='<%# Eval("EID") %>' />
                <br />
                EName:
                <asp:Label ID="ENameLabel" runat="server" Text='<%# Bind("EName") %>' />
                <br />
                Dept:
                <asp:Label ID="DeptLabel" runat="server" Text='<%# Bind("Dept") %>' />
                <br />
                <asp:LinkButton ID="EditButton" runat="server" CausesValidation="False" 
                    CommandName="Edit" Text="Edit" />
                &nbsp;<asp:LinkButton ID="DeleteButton" runat="server" CausesValidation="False" 
                    CommandName="Delete" Text="Delete" />
                &nbsp;<asp:LinkButton ID="NewButton" runat="server" CausesValidation="False" 
                    CommandName="New" Text="New" />
            </ItemTemplate>
            <PagerStyle BackColor="#666666" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#E3EAEB" />
        </asp:FormView>
        <br />
        <br />
        <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False" 
            DataKeyNames="EID" DataSourceID="SqlDataSource1" Height="50px" 
            Width="125px" CellPadding="4" ForeColor="#333333" GridLines="None">
            <AlternatingRowStyle BackColor="White" />
            <CommandRowStyle BackColor="#C5BBAF" Font-Bold="True" />
            <EditRowStyle BackColor="#7C6F57" />
            <FieldHeaderStyle BackColor="#D0D0D0" Font-Bold="True" />
            <Fields>
                <asp:BoundField DataField="EName" HeaderText="EName" SortExpression="EName" />
                <asp:BoundField DataField="Dept" HeaderText="Dept" SortExpression="Dept" />
                <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" />
            </Fields>
            <FooterStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#666666" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#E3EAEB" />
        </asp:DetailsView>
    
    </div>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
        DeleteCommand="DELETE FROM [emp] WHERE [EID] = @original_EID" 
        InsertCommand="INSERT INTO [emp] ([EName], [Dept]) VALUES (@EName, @Dept)" 
        OldValuesParameterFormatString="original_{0}" 
        SelectCommand="SELECT * FROM [emp] ORDER BY [EName]" 
        
        UpdateCommand="UPDATE [emp] SET [EName] = @EName, [Dept] = @Dept WHERE [EID] = @original_EID">
        <DeleteParameters>
            <asp:Parameter Name="original_EID" Type="Decimal" />
        </DeleteParameters>
        <InsertParameters>
            <asp:Parameter Name="EName" Type="String" />
            <asp:Parameter Name="Dept" Type="String" />
        </InsertParameters>
        <UpdateParameters>
            <asp:Parameter Name="EName" Type="String" />
            <asp:Parameter Name="Dept" Type="String" />
            <asp:Parameter Name="original_EID" Type="Decimal" />
        </UpdateParameters>
    </asp:SqlDataSource>
    </form>
</body>
</html>
