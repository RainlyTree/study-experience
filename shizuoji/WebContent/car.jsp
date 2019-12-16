<%@page import="java.sql.*"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
Connection con= null;
Statement st=null;
ResultSet rs=null;
ResultSet rs1=null;
PreparedStatement pstmt = null;
try{
	Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
}catch(ClassNotFoundException e){
	e.printStackTrace();
}
try{
	con=DriverManager.getConnection("jdbc:sqlserver://127.0.0.1:1433;DatabaseName=shopcar","shopcar","chenlin118");
	st=con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_READ_ONLY);
	rs=st.executeQuery("select* from car");
	rs.last();
	
	
	out.print("<table border=1>");
	out.print("<tr>");
	out.print("<th>商品编号</th>");
	out.print("<th>商品名称</th>");
	out.print("<th>商品价格</th>");
	out.print("<th>商品数量</th>");
	
    out.println("</tr>");
    rs.afterLast();
    
    int row=0;
    float sum=0;
    while (rs.previous()){
    	row++;
    	
    	out.print("<tr>");
    	out.print("<td>"+rs.getString(1)+"</td>");
    	out.print("<td>"+rs.getString(2)+"</td>");
    	out.print("<td>"+rs.getString(3)+"</td>");
    	out.print("<td>"+rs.getString(4)+"</td>");
    	out.print("</tr>");
    	sum = sum + (float)rs.getInt(5);
    	
    }
    out.print("</table>");
    out.print("商品总计" +sum+ "元");
    st.executeQuery("truncate table car");
    
   
}catch(SQLException e){
	e.printStackTrace();
}
%>
<br><a href='add.jsp'>返回购物车</a>
</body>
</html>