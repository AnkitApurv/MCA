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

        protected void validateImageType(object sender, ServerValidateEventArgs e) {
            HttpPostedFile photo = PhotoUpload.PostedFile;
            if (photo.ContentType != "image/jpeg" || photo.ContentType != "image/jpg" || photo.ContentType != "image/gif")
                e.IsValid = false;
            else
                e.IsValid = true;
            return;
        }

        protected void validateImageSize(object sender, ServerValidateEventArgs e) {
            HttpPostedFile photo = PhotoUpload.PostedFile;
            int maxFileSize = 100 * 1000;
            if (photo.ContentLength > maxFileSize)
                e.IsValid = false;
            else
                e.IsValid = true;
            return;
        }

        protected void validateResumeType(object sender, ServerValidateEventArgs e) {
            HttpPostedFile resume = ResumeUpload.PostedFile;
            if (resume.ContentType != "application/pdf")
                e.IsValid = false;
            else
                e.IsValid = true;
            return;
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Response.Redirect("HiringPolicies.aspx", true);
            return;
        }
    }
}