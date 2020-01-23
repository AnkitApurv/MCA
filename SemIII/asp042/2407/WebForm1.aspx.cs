using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApp1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e) {

        }

        protected void Bt1_Click(object sender, EventArgs e) {
            if(TextBox1.Text != "")
                Label1.Text = TextBox1.Text;
            else
                Label1.Text = "SomethingSomething";
            Label2.Text = TextBox1.Text + TextBox2.Text;
            return;
        }
        protected void Btn3_Click(object sender, EventArgs e) {
            if (rdlMagazine.Checked)
                Label3.Text = rdlMagazine.Text;
            else if(rdlTelevision.Checked)
                Label3.Text = rdlTelevision.Text;
            else if (rdlOther.Checked)
                Label3.Text = rdlOther.Text;
            return;
        }
        protected void Button1_Click(object sender, EventArgs e) {
            Label4.Text = DateTime.Now.ToLongTimeString();
        }
        protected void lnkBtn1_Click(object sender, EventArgs e) {
            Label4.Text = DateTime.Now.ToShortTimeString();
        }
        protected void Button2_Click(object sender, EventArgs e) {
            Label5.Text = (Int32.Parse(Label5.Text) + 1).ToString();
        }
        protected void Button3_Click(object sender, EventArgs e) {
            ((Button)sender).Text = (Int32.Parse(((Button)sender).Text) + 1).ToString();
        }
        protected void igBt2_Click(object sender, ImageClickEventArgs e) {
            Label7.Text = "X : " + e.X.ToString() + " | Y : " + e.Y.ToString(); 
        }
    }
}