using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _3107
{
    public partial class Ex1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Label1.Text = ListBox1.Text + " appreciates your feedback of " + RadioButtonList1.Text;
        }
        protected void Button2_Click(object sender, EventArgs e)
        {
            if(Button2.BackColor == System.Drawing.Color.Green)
                Button2.BackColor = System.Drawing.Color.Yellow;
            else
                Button2.BackColor = System.Drawing.Color.Green;
        }
    }
}