package servlet;

import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import dao.registDao;
import javabean.Regist;

public class registservlet extends HttpServlet {

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		req.setCharacterEncoding("utf-8");
		resp.setContentType("text/html;charset=utf-8");
		String username = req.getParameter("username");
		String pwd = req.getParameter("passwd");
		String sex = req.getParameter("sex");
		//新建对象，并且进行赋初值操作
		Regist regist = new Regist(username,pwd,sex);
		
		int result = registDao.regist(regist);
		
		if(result>0) {
			PrintWriter pw = resp.getWriter();
			pw.print(username);
			pw.print(pwd);
			pw.print(sex);
			resp.sendRedirect("login.jsp");
		}else {
			PrintWriter pw = resp.getWriter();
			pw.print("重新输入");
		}
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req,resp);
	}

}
