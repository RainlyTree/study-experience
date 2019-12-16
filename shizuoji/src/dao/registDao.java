package dao;

import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javabean.Regist;

public class registDao {
	public static int regist(Regist regist){
	    PreparedStatement pstmt = null;
		Connection connection = null;
		int count = -1;
	  try {
	  Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
	  connection = DriverManager.getConnection("jdbc:sqlserver://127.0.0.1:1433;DatabaseName=shopcar","shopcar","chenlin118");
	  
	  String sql = "insert into zhanghao (username,pwd,sex)values(?,?,?)";
	  
	  //将获取的输入信息放入数据库
	  pstmt = connection.prepareStatement(sql);
	  pstmt.setString(1,regist.getUsername());
	  pstmt.setString(2,regist.getPwd());
	  pstmt.setString(3,regist.getSex());
	  System.out.print(regist.getUsername());
	  count = pstmt.executeUpdate();
	  
	  if(count>0) {
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
