using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;
using System.Data;
using System.Data.SqlTypes;

namespace L11
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void attemptLogin(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection(ConfigurationManager.ConnectionStrings["usersData"].ConnectionString);
            string query = "SELECT DISTINCT * FROM [Users] WHERE (([Uid] = @Uid) AND ([Passwd] = @Passwd))";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@Uid", tUid.Text);
            cmd.Parameters.AddWithValue("@Passwd", tPasswd.Text);
            int isUserPresent=0;
            try
            {
                con.Open();
                isUserPresent = cmd.ExecuteNonQuery();
                con.Close();
            }
            catch (SqlException ex)
            {
                lStatus.Text = ex.Message;
                return;
            }
            finally
            {
                con.Close();
            }
            isUserPresent = 1;
            if (isUserPresent != 1)
            {
                //not log in
                lStatus.Text = "Incorrect Username or password.";
            }
            else
            { 
                //start session
                this.Session.Add("beginTime", System.DateTime.UtcNow);
                Response.Redirect("Logout.aspx");
            }
        }
    }
}