package javabean;

public class Goods {
	//类成员 ： id  名字  价格  数量
      private int id;
      private int gname;
      private int price;
      private int num;
      private int he;
      public Goods(int id, int num) {
  		super();
  		this.id = id;
  		this.num = num;
  		
  	}
      public Goods() {
  		
  	}
	public int getGname() {
		return gname;
	}
	public void setGname(int gname) {
		this.gname = gname;
	}
	public int getPrice() {
		return price;
	}
	public void setPrice(int price) {
		this.price = price;
	}
	public int getHe() {
		return he;
	}
	
	public void setHe(int he) {
		this.he = he;
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	
}
