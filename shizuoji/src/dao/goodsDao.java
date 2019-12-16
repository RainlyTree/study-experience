package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javabean.Goods;


public class goodsDao {
	public static int goods(Goods goods){
	    PreparedStatement pstmt = null;
		Connection connection = null;
		
		int count = -1;
	  try {
	  Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
	  connection = DriverManager.getConnection("jdbc:sqlserver://127.0.0.1:1433;DatabaseName=shopcar","shopcar","chenlin118");
	  String sql = "update goods set num=? where id=?";
	  pstmt = connection.prepareStatement(sql);
      
      pstmt.setInt(1,goods.getNum());
      pstmt.setInt(2,goods.getId());
      count = pstmt.executeUpdate();
      if(count>0) {
		  return 1;
	  }else {
		  return 0;
	  }  
	  }catch(ClassNotFoundException e) {
		  e.printStackTrace();
		  
	  }catch(SQLException e) {
		  e.printStackTrace();
		  
	  }catch(Exception e) {
		  e.printStackTrace();
		  
	  }finally {
		  try {
			 
			 if(pstmt!= null)pstmt.close();
			 if(connection!= null)connection.close();
			 }catch(SQLException e) {
				 e.printStackTrace();
			 }catch(Exception e) {
				 e.printStackTrace();
			 }
		
	  }
	return count;

	}
}
