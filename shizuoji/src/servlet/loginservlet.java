package servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.loginDao;
import javabean.Login;

public class loginservlet extends HttpServlet {

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		req.setCharacterEncoding("utf-8");
		resp.setContentType("text/html;charset=utf-8");
		String username = req.getParameter("username");
		String pwd = req.getParameter("passwd");
		String mdl = req.getParameter("freeLogin");
		if("fastway".equals(mdl)) {
			Cookie cookie = new Cookie("username","user");
			cookie.setMaxAge(3600*24*14);
			
			
			
		}
		Login login = new Login(username,pwd);
		
		int result = loginDao.login(login);
		if(result>0) {
			if("fastway".equals(mdl)) {
				Cookie cookie = new Cookie("username","user");
				cookie.setMaxAge(3600*24*14);
				resp.addCookie(cookie);
			}
			resp.sendRedirect("add.jsp");
			
		}else {
			resp.sendRedirect("login.jsp");
		}
		
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req,resp);
	}

}
