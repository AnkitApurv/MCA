using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _0708
{
    public partial class Registration : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Calendar1DOB_Selected(object sender, EventArgs e)
        {
            Calendar c1 = ((Calendar)sender);
            TextBox7.Text = c1.SelectedDate.Date.ToShortDateString();
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            HttpPostedFile photo = PhotoUpload.PostedFile;
            HttpPostedFile resume = ResumeUpload.PostedFile;
            int maxFileSize = 100 * 1000;
            bool areUploadsValid = true;
            if (photo.ContentType != "image/jpeg" || photo.ContentType != "image/jpg" || photo.ContentType != "image/gif")
            {
                areUploadsValid = false;
                PhotoUploadErrors.Text = "File provided for photo is not an image.";
            }
            if (photo.ContentLength > maxFileSize)
            {
                areUploadsValid = false;
                PhotoUploadErrors.Text += "Photo is larger than 100KB.";
            }
            if (resume.ContentType != "application/pdf")
            {
                areUploadsValid = false;
                ResumeUploadErrors.Text = "File provided for resume is not a pdf.";
            }
            if (areUploadsValid)
            {
                Response.Redirect("HiringPolicies.aspx", true);
            }
            return;
        }
    }
}