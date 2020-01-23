using System;
using System.Configuration;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace _0409
{
    public partial class _05Placements : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void save(object sender, EventArgs e)
        {
            SqlConnection c = new SqlConnection(ConfigurationManager.ConnectionStrings["plc"].ConnectionString);
            string tsql = "INSERT INTO [student] ([name], [address], [dob], [x], [xii], [ug], [pg], [achievements], [ref1], [ref2], [ref3], [gender]) VALUES (@name, @address, @dob, @x, @xii, @ug, @pg, @achievements, @ref1, @ref2, @ref3, @gender);";
            SqlCommand cmd = new SqlCommand(tsql, c);
            try
            {
                cmd.Parameters.AddWithValue("@name", tName.Text);
                cmd.Parameters.AddWithValue("@address", tAddress.Text);
                cmd.Parameters.AddWithValue("@dob", DateTime.Parse(tDOB.Text));
                cmd.Parameters.AddWithValue("@x", float.Parse(tX.Text));
                cmd.Parameters.AddWithValue("@xii", float.Parse(tXII.Text));
                cmd.Parameters.AddWithValue("@ug", float.Parse(tUG.Text));
                cmd.Parameters.AddWithValue("@pg", float.Parse(tPG.Text));
                cmd.Parameters.AddWithValue("@achievements", tAchievements.Text);
                cmd.Parameters.AddWithValue("@ref1", tRef1.Text);
                cmd.Parameters.AddWithValue("@ref2", tRef2.Text);
                cmd.Parameters.AddWithValue("@ref3", tRef3.Text);
                cmd.Parameters.AddWithValue("@gender", rlGender.SelectedItem.Value);
            }
            catch (SqlException se1) { }
            try
            {
                c.Open();
                int isSuccess = cmd.ExecuteNonQuery();
                c.Close();
            }
            catch (SqlException se2) { }
            c.Dispose();
            cmd.Dispose();
            return;
        }
    }
}