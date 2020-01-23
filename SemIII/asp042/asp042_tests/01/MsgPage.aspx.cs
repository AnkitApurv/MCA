using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _01
{
    public partial class MsgPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            TextBox tb = (TextBox)PreviousPage.FindControl("tbName");
            Label1.Text = "Name : " + tb.Text;
            tb = (TextBox)PreviousPage.FindControl("tbDesig");
            Label1.Text += "\nDesignation : " + tb.Text;
            tb = (TextBox)PreviousPage.FindControl("tbEmail");
            Label1.Text += "\nEmail : " + tb.Text;
            tb = (TextBox)PreviousPage.FindControl("tbMobile");
            Label1.Text += "\nMobile : " + tb.Text;
        }
    }
}