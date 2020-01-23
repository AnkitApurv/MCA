using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _3107
{
    public partial class Ex2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void ImgBtn_OnClick(object sender, EventArgs e)
        {
            if (((ImageButton)sender).ID != "ImageButton5")
                ImageButton5.ImageUrl = ((ImageButton)sender).ImageUrl;
            else
                ((ImageButton)sender).ImageUrl = "~/blank.png";
        }

    }
}