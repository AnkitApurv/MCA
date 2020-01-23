using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _1109
{
    public partial class _06Dept : System.Web.UI.Page
    {
        protected string td;
        protected void Page_Load(object sender, EventArgs e)
        {
            GridView1.ShowFooter = true;
        }
        protected void tDept_TextChanged(object sender, EventArgs e)
        {
            SqlDataSource1.InsertParameters.Add("@DeptName", ((TextBox)sender).Text);
            SqlDataSource1.Insert();
        }
    }
}