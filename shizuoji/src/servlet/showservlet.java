package servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.goodsDao;
import dao.loginDao;
import dao.registDao;
import javabean.Goods;
import javabean.Regist;

public class showservlet extends HttpServlet {

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		req.setCharacterEncoding("utf-8");
		resp.setContentType("text/html;charset=utf-8");
		String id = req.getParameter("id");
		String num = req.getParameter("num");
		Goods goods = new Goods(Integer.parseInt(id),Integer.parseInt(num));
		
		int result = goodsDao.goods(goods);
		//if(result>0) {
			resp.sendRedirect("add.jsp");
		//}
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req,resp);
	}

}
