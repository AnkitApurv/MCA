using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _0708
{
    public partial class billing : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void displayImg(object sender, EventArgs e)
        {
            ListItem selectedItem = ((DropDownList)sender).SelectedItem;
            Image1.ImageUrl = "./Images/" + selectedItem.Text + ".png";
        }

        protected void total(object sender, EventArgs e)
        {
            ListItem selectedItem = DropDownList1.SelectedItem;
            Label1.Text = selectedItem.Value;
            TextBox1.Enabled = true;
        }
        protected void generateBill(object sender, EventArgs e)
        {
            ListItem selectedItem = DropDownList1.SelectedItem;
            TextBox tb1 = (TextBox)sender;
            int unitPrice = Int32.Parse(selectedItem.Value);
            int quantity = Int32.Parse(tb1.Text);
            int bill = unitPrice * quantity;
            Label2.Text = "Bill : " + bill.ToString() + "/-";
        }
    }
}