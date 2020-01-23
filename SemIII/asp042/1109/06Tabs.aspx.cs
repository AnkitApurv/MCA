using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _1109
{
    public partial class _06Tabs : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
        }

        protected void changeView(object sender, EventArgs e)
        {
            MenuItem currentMenuItem = ((Menu)sender).SelectedItem;
            View viewToSet = (View)this.FindControl(currentMenuItem.Text);
            MultiView1.SetActiveView(viewToSet);
            return;
        }
    }
}