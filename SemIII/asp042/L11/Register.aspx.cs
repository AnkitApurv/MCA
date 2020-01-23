using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;

namespace L11
{
    public partial class Register : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void createUser(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection(ConfigurationManager.ConnectionStrings["usersData"].ConnectionString);
            string query = "INSERT INTO [Users] ([Uid], [Passwd]) VALUES (@Uid, @Passwd)";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@Uid", tUid.Text);
            cmd.Parameters.AddWithValue("@Passwd", tPasswd.Text);
            con.Open();
            int isRegistered = cmd.ExecuteNonQuery();
            con.Close();
            if (isRegistered == 1)
                lStatus.Text = "User registered.";
            else
                lStatus.Text = "User not registered.";
        }
    }
}