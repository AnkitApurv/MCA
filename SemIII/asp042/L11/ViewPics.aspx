<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="ViewPics.aspx.cs" Inherits="L11.ViewPics" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <asp:SqlDataSource ID="picDS" runat="server" 
        ConnectionString="<%$ ConnectionStrings:usersData %>" 
        SelectCommand="SELECT * FROM [pics]"></asp:SqlDataSource>
    <asp:SqlDataSource ID="commentDS" runat="server" 
        ConnectionString="<%$ ConnectionStrings:usersData %>" 
        SelectCommand="SELECT * FROM [comments] WHERE ([picid] = @picid)">
        <SelectParameters>
            <asp:ControlParameter ControlID="FormView1" Name="picid" 
                PropertyName="SelectedValue" Type="Int32" />
        </SelectParameters>
    </asp:SqlDataSource>
    <asp:FormView ID="FormView1" runat="server" DataKeyNames="id" 
        DataSourceID="picDS" AllowPaging="True">
        <EditItemTemplate>
            id:
            <asp:Label ID="idLabel1" runat="server" Text='<%# Eval("id") %>' />
            <br />
            path:
            <asp:TextBox ID="pathTextBox" runat="server" Text='<%# Bind("path") %>' />
            <br />
            userid:
            <asp:TextBox ID="useridTextBox" runat="server" Text='<%# Bind("userid") %>' />
            <br />
            <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" 
                CommandName="Update" Text="Update" />
            &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" 
                CausesValidation="False" CommandName="Cancel" Text="Cancel" />
        </EditItemTemplate>
        <InsertItemTemplate>
            path:
            <asp:TextBox ID="pathTextBox" runat="server" Text='<%# Bind("path") %>' />
            <br />
            userid:
            <asp:TextBox ID="useridTextBox" runat="server" Text='<%# Bind("userid") %>' />
            <br />
            <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" 
                CommandName="Insert" Text="Insert" />
            &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" 
                CausesValidation="False" CommandName="Cancel" Text="Cancel" />
        </InsertItemTemplate>
        <ItemTemplate>
            <asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("path") %>' />
        </ItemTemplate>
    </asp:FormView>
    <br />
    <asp:ListView ID="ListView1" runat="server" DataKeyNames="id" 
        DataSourceID="commentDS">
        <AlternatingItemTemplate>
            <span style="">
            userid:
            <asp:Label ID="useridLabel" runat="server" Text='<%# Eval("userid") %>' />
            <br />
            comment:
            <asp:Label ID="commentLabel" runat="server" Text='<%# Eval("comment") %>' />
            <br />
            <br />
            </span>
        </AlternatingItemTemplate>
        <EditItemTemplate>
            <span style="">
            comment:
            <asp:TextBox ID="commentTextBox" runat="server" Text='<%# Bind("comment") %>' />
            <br />
            <asp:Button ID="UpdateButton" runat="server" CommandName="Update" 
                Text="Update" />
            <asp:Button ID="CancelButton" runat="server" CommandName="Cancel" 
                Text="Cancel" />
            <br />
            <br />
            </span>
        </EditItemTemplate>
        <EmptyDataTemplate>
            <span>No data was returned.</span>
        </EmptyDataTemplate>
        <InsertItemTemplate>
            <span style="">
            <asp:TextBox ID="commentTextBox" runat="server" Text='<%# Bind("comment") %>' TextMode="MultiLine" />
            <br />
            <asp:Button ID="InsertButton" runat="server" CommandName="Insert" 
                Text="Insert" />
            <asp:Button ID="CancelButton" runat="server" CommandName="Cancel" 
                Text="Clear" />
            <br />
            <br />
            </span>
        </InsertItemTemplate>
        <ItemTemplate>
            <span style="">
            userid:
            <asp:Label ID="useridLabel" runat="server" Text='<%# Eval("userid") %>' />
            <br />
            comment:
            <asp:Label ID="commentLabel" runat="server" Text='<%# Eval("comment") %>' />
            <br />
            <br />
            </span>
        </ItemTemplate>
        <LayoutTemplate>
            <div style="" ID="itemPlaceholderContainer" runat="server">
                <span runat="server" id="itemPlaceholder" />
            </div>
            <div style="">
                <asp:DataPager ID="DataPager1" runat="server">
                    <Fields>
                        <asp:NextPreviousPagerField ButtonType="Button" ShowFirstPageButton="True" 
                            ShowNextPageButton="False" ShowPreviousPageButton="False" />
                        <asp:NumericPagerField />
                        <asp:NextPreviousPagerField ButtonType="Button" ShowLastPageButton="True" 
                            ShowNextPageButton="False" ShowPreviousPageButton="False" />
                    </Fields>
                </asp:DataPager>
            </div>
        </LayoutTemplate>
        <SelectedItemTemplate>
            <span style="">
            userid:
            <asp:Label ID="useridLabel" runat="server" Text='<%# Eval("userid") %>' />
            <br />
            comment:
            <asp:Label ID="commentLabel" runat="server" Text='<%# Eval("comment") %>' />
            <br />
            <br />
            </span>
        </SelectedItemTemplate>
    </asp:ListView>
</asp:Content>
