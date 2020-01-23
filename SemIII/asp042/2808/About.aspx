<%@ Page Title="About Us" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeBehind="About.aspx.cs" Inherits="_2808.About" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <asp:AdRotator ID="AdRotator1" runat="server" DataSourceID="XmlDataSource1"/>
    <asp:XmlDataSource ID="XmlDataSource1" runat="server" 
        DataFile="~/App_Data/Ad1.xml"></asp:XmlDataSource>

    <asp:AdRotator ID="AdRotator2" runat="server" DataSourceID="SqlDataSource1"/>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
        ConnectionString="<%$ ConnectionStrings:EmployeeDB %>" 
        SelectCommand="SELECT * FROM [AdList]"></asp:SqlDataSource>

    <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
        ConnectionString="<%$ ConnectionStrings:EmployeeDB %>" 
        DeleteCommand="DELETE FROM [AdStats] WHERE [Id] = @Id" 
        InsertCommand="INSERT INTO [AdStats] ([AdId], [EntryDate], [Type]) VALUES (@AdId, @EntryDate, @Type)" 
        SelectCommand="SELECT * FROM [AdStats]" 
        UpdateCommand="UPDATE [AdStats] SET [AdId] = @AdId, [EntryDate] = @EntryDate, [Type] = @Type WHERE [Id] = @Id">
        <DeleteParameters>
            <asp:Parameter Name="Id" Type="Int32" />
        </DeleteParameters>
        <InsertParameters>
            <asp:Parameter Name="AdId" Type="Int32" />
            <asp:Parameter Name="EntryDate" Type="DateTime" />
            <asp:Parameter Name="Type" Type="Int32" />
        </InsertParameters>
        <UpdateParameters>
            <asp:Parameter Name="AdId" Type="Int32" />
            <asp:Parameter Name="EntryDate" Type="DateTime" />
            <asp:Parameter Name="Type" Type="Int32" />
            <asp:Parameter Name="Id" Type="Int32" />
        </UpdateParameters>
    </asp:SqlDataSource>
</asp:Content>
