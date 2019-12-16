package javabean;

public class Regist {
	
	      private String username;
	      private String pwd;
	      private String sex;
		public String getUsername() {
			return username;
		}
		public void setUsername(String username) {
			this.username = username;
		}
		public String getPwd() {
			return pwd;
		}
		public void setPwd(String pwd) {
			this.pwd = pwd;
		}
		public String getSex() {
			return sex;
		}
		public void setSex(String sex) {
			this.sex = sex;
		}
		
		
		public Regist(String username, String pwd, String sex) {
			super();
			this.username = username;
			this.pwd = pwd;
			this.sex = sex;
		}
		
		
		public Regist() {
			
		}
	

}
