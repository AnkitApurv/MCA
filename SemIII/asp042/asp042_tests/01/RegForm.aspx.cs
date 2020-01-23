using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _01
{
    public partial class RegForm : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            
        }
        protected void clearPage(object sender, EventArgs e)
        {
            tbName.Text = tbDesig.Text = tbEmail.Text = tbMobile.Text = "";
            form1.DefaultFocus = "tbName";
            tbName.Focus();
            return;
        }
    }
}