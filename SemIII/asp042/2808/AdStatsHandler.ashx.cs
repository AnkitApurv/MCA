using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace _2808
{
    /// <summary>
    /// Summary description for AdStatsHandler
    /// </summary>
    public class AdStatsHandler : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            
        }

        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}