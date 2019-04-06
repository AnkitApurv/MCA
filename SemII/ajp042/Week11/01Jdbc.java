/*
@desc JDBC
Testing for database connectivity and displaying the result set from a database table.

@name Ankit Apurv
@roll 180970042
@date 02/04/19
*/

import java.sql.*;

class JdbcTest {
	public static void main(String ... args) {
		String driver = "sun.jdbc.odbc.JdbcOdbcDriver";
		String dataSourceName = "Ajp042Jdbc";
		String dbUri = "jdbc:odbc:" + dataSourceName;
		String username = "";
		String passwd = "";
		try {
			Class.forName(driver);
			Connection conn = DriverManager.getConnection(dbUri, username, passwd);
			Statement st = conn.createStatement();
			String query = "SELECT RegNo, Sname FROM Student ORDER BY RegNo;";
			ResultSet rs = st.executeQuery(query);
			while(rs.next()) {
				System.out.println(rs.getInt("RegNo") + " " + rs.getString("Sname"));
			}
		}
		catch(Exception e) {
			System.out.println(e.toString());
		}
		return;
	}
}