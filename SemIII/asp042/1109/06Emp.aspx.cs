using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;

namespace _1109
{
    public partial class _06Emp : System.Web.UI.Page
    {
        string name, dept = "asdf";
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void LinkButton1_Command(object sender, CommandEventArgs e)
        {
            SqlConnection c = new SqlConnection(ConfigurationManager.ConnectionStrings["empdept"].ConnectionString);
            string sql = "INSERT INTO [Emp] ([Name], [DeptName]) VALUES (@Name, @DeptName);";
            SqlCommand cmd = new SqlCommand(sql, c);
            cmd.Parameters.AddWithValue("@Name", name);
            cmd.Parameters.AddWithValue("@DeptName", dept);
            c.Open();
            int countOfRowsUpdate = cmd.ExecuteNonQuery();
            c.Close();
            if(countOfRowsUpdate == 1)
                GridView1.DataBind();
        }

        protected void TextBox3_TextChanged(object sender, EventArgs e)
        {
            name = ((TextBox)sender).Text;
        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {
            dept = ((DropDownList)sender).SelectedValue;
        }
    }
}