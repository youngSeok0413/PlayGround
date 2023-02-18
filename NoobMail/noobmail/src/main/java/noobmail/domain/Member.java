package noobmail.domain;

public class Member {
	private Long id;
	private String userId;
	private String username;
	private String toPost;
	private String toGet;
	private Boolean secession_confirmed;
	
	public Long getId() {
		return id;
	}
	
	public void setId(Long id) {
		this.id = id;
	}
	
	public String getUserId() {
		return userId;
	}

	public void setUserId(String userId) {
		this.userId = userId;
	}
	
	public String getUsername() {
		return username;
	}
	
	public void setUsername(String username) {
		this.username = username;
	}
	
	public String getToPost() {
		return toPost;
	}
	
	public void setToPost(String toPost) {
		this.toPost = toPost;
	}
	
	public String getToGet() {
		return toGet;
	}
	
	public void setToGet(String toGet) {
		this.toGet = toGet;
	}
	
	public Boolean getSecession_confirmed() {
		return secession_confirmed;
	}
	
	public void setSecession_confirmed(Boolean secession_confirmed) {
		this.secession_confirmed = secession_confirmed;
	}
}


