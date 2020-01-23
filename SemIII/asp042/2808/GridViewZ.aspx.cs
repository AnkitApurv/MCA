using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _2808
{
    public partial class GridViewZ : System.Web.UI.Page
    {
        public string connectionString = ConfigurationManager.ConnectionStrings["EmployeeDB"].ToString();
        protected void Page_Load(object sender, EventArgs e)
        {
            SqlConnection employeeTableConn = new SqlConnection(connectionString);
            SqlCommand fetchAll = new SqlCommand("SELECT * FROM [Employee];", employeeTableConn);
            SqlDataReader employeeDS = fetchAll.ExecuteReader(CommandBehavior.CloseConnection);
            GridView1.DataSource = employeeDS;
            GridView1.DataBind();
        }
    }
}