using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;

namespace Test2
{
    public partial class addStudent : System.Web.UI.Page
    {
        string name, address;
        int stream, semester = 1;
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string picPath = "";
            FileUpload pic = (FileUpload)DetailsView1.FindControl("FileUpload1");
            if(pic.FileName.

            SqlConnection con = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
            string cmd = "INSERT INTO [student_info] ([name], [stream], [semester], [address], [photo]) VALUES (@name, @stream, @semester, @address, @photo)";
            SqlCommand cd = new SqlCommand(cmd, con);
            cd.Parameters.AddWithValue("@name", name);
            cd.Parameters.AddWithValue("@stream", stream);
            cd.Parameters.AddWithValue("@semester", semester);
            cd.Parameters.AddWithValue("@address", address);
            cd.Parameters.AddWithValue("@photo", picPath);
            con.Open();
            cd.ExecuteNonQuery();
            con.Close();
        }

        protected void txtName_TextChanged(object sender, EventArgs e)
        {
            name = ((TextBox)sender).Text;
        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {
            stream = Int32.Parse(((DropDownList)sender).SelectedValue);
        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {
            address = ((TextBox)sender).Text;
        }
    }
}