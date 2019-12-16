package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javabean.Goods;

public class carDao {
	public static void car(){
		Connection con= null;
		Statement st=null;
		ResultSet rs=null;
		
		try{
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
		}catch(ClassNotFoundException e){
			e.printStackTrace();
		}
		try{
			con=DriverManager.getConnection("jdbc:sqlserver://127.0.0.1:1433;DatabaseName=shopcar","shopcar","chenlin118");
			st=con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_READ_ONLY);
			int num = st.executeUpdate("insert into car(id,qname,price,num) select * from goods where num != '0'");
			if(num > 0)
			{
				System.out.println("≤Â»Î≥…π¶");
			}
			st.executeUpdate("update car set he = price * num where id = id");
			
	  }catch(SQLException e){
			e.printStackTrace();
	  }
	}
}
