package noobmail.domain;

import java.io.File;

public class Mail {
	public Long id;
	public String date;
	public String from;
	public String to;
	public String title;
	public String text;
	public File file;
	public Boolean toGarbage;
	public Boolean deleteConfirmed;
	
	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}
	
	public String getDate() {
		return date;
	}
	
	public void setDate(String date) {
		this.date = date;
	}
	
	public String getFrom() {
		return from;
	}
	
	public void setFrom(String from) {
		this.from = from;
	}
	
	public String getTo() {
		return to;
	}
	
	public void setTo(String to) {
		this.to = to;
	}
	
	public String getTitle() {
		return title;
	}
	
	public void setTitle(String title) {
		this.title = title;
	}
	
	public String getText() {
		return text;
	}
	
	public void setText(String text) {
		this.text = text;
	}
	
	public File getFile() {
		return file;
	}
	
	public void setFile(File file) {
		this.file = file;
	}
	
	public Boolean getToGarbage() {
		return toGarbage;
	}
	
	public void setToGarbage(Boolean toGarbage) {
		this.toGarbage = toGarbage;
	}
	
	public Boolean getDeleteConfirmed() {
		return deleteConfirmed;
	}
	
	public void setDeleteConfirmed(Boolean deleteConfirmed) {
		this.deleteConfirmed = deleteConfirmed;
	}
}
