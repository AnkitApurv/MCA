using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace L11
{
    public partial class Logout : System.Web.UI.Page
    {
        protected void Page_Init(object sender, EventArgs e)
        {
            lUid.Text = this.Session.SessionID;
        }
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void logoutUser(object sender, EventArgs e)
        {
            this.Session.Abandon();
            Response.Redirect("Login.aspx");
        }
    }
}