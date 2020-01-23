using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _0708
{
    public partial class CalendarSechdule : System.Web.UI.Page
    {
        Hashtable Scheduleddata;

        protected void Page_Load(object sender, EventArgs e)
        {
            Scheduleddata = getSchedule();
            Calendar1.Caption = "Personal Schedule ";
            Calendar1.NextPrevFormat = NextPrevFormat.ShortMonth;
            Calendar1.FirstDayOfWeek = FirstDayOfWeek.Monday;
            Calendar1.TitleFormat = TitleFormat.MonthYear;
            Calendar1.ShowGridLines = true;
            Calendar1.DayStyle.Height = new Unit(75);
            Calendar1.DayStyle.Width = new Unit(100);
            Calendar1.OtherMonthDayStyle.BackColor = System.Drawing.Color.BurlyWood;
            Calendar1.TodaysDate = new DateTime(2019, 8, 14);
            Calendar1.VisibleDate = Calendar1.TodaysDate;

        }
        protected void Calendar1_DayRender(object sender, DayRenderEventArgs e)
        {
            if (Scheduleddata[e.Day.Date.ToShortDateString()] != null)
            {
                Label lbl = new Label();
                lbl.ForeColor = System.Drawing.Color.Red;
                lbl.Text += "<br/>";
                lbl.Text += (String)Scheduleddata[e.Day.Date.ToShortDateString()];
                e.Cell.Controls.Add(lbl);
            }
        }
        protected void Calendar1_VisibleMonthChanged(object sender, MonthChangedEventArgs e)
        {
            Label1.Text = "<h1> Month Changed to : " + e.NewDate.ToShortDateString() + "</h1>";
        }
        protected void Calendar1_SelectionChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < Calendar1.SelectedDates.Count; i++)
            {
                Label1.Text = "<h1> Selection Changed to  : " + Calendar1.SelectedDates[i].ToShortDateString() + "</h1>";
            }
        }

        private Hashtable getSchedule()
        {
            Hashtable schedule = new Hashtable();
            schedule["10-08-2019"] = "Internals";
            schedule["11-08-2019"] = "Internals";
            schedule["12-08-2019"] = "Internals";
            return schedule;

        }
    }
}