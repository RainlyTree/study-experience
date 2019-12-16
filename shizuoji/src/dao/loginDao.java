package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javabean.Login;

public class loginDao {
      public static int login(Login login){
    	    PreparedStatement pstmt = null;
			Connection connection = null;
			ResultSet rs = null;
			int count = -1;
    	  try {
    	  Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
    	  connection = DriverManager.getConnection("jdbc:sqlserver://127.0.0.1:1433;DatabaseName=shopcar","shopcar","chenlin118");
    	  String sql = "select count(*) from zhanghao where username=? and pwd = ?";
		  pstmt = connection.prepareStatement(sql);
		  pstmt.setString(1,login.getUsername());
		  pstmt.setString(2,login.getPwd());
		  rs = pstmt.executeQuery();
		  if(rs.next()) {
			  count = rs.getInt(1);
		  }if(count>0) {
			  return 1;
		  }else {
			  return 0;
		  }
    	  }catch(ClassNotFoundException e) {
    		  e.printStackTrace();
    		  return -1;
    	  }catch(SQLException e) {
    		  e.printStackTrace();
    		  return -1;
    	  }catch(Exception e) {
    		  e.printStackTrace();
    		  return -1;
    	  }finally {
    		  try {
 				 if(rs!= null)rs.close();
 				 if(pstmt!= null)pstmt.close();
 				 if(connection!= null)connection.close();
 				 }catch(SQLException e) {
 					 e.printStackTrace();
 				 }catch(Exception e) {
 					 e.printStackTrace();
 				 }
 			
    	  }
      }
}
