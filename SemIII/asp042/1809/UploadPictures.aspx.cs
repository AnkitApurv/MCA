using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Configuration;
using System.Data.SqlClient;

namespace _1809
{
    public partial class UploadPictures : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
            string query = "INSERT INTO [picPath] ([path]) VALUES (@path);";
            SqlCommand cmd = new SqlCommand(query, con);
            if (FileUpload1.HasFile) {
                HttpPostedFile f = FileUpload1.PostedFile;
                string extension = System.IO.Path.GetExtension(f.FileName);
                if (extension.Equals(".png") || extension.Equals(".jpg"))
                {
                    string savePath = "F:/ProjectsWorking/asp042/1809/Pics/" + f.FileName;
                    f.SaveAs(savePath);

                    cmd.Parameters.AddWithValue("@path", savePath);
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
        }
    }
}