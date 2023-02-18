package noobmail.repository;

import java.util.List;

import noobmail.domain.Mail;

public interface MailBoxRepository {
	//save
	public void save(Mail mail);
	//find
	public Mail findById(Long id);
	public List<Mail> findByDate(String date);
	public List<Mail> findByWhomWrote(String from);
	public List<Mail> findByWhomSendTo(String to);
	public List<Mail> findByTitle(String title);
	//delete
	public void moveToGarbage();
	public void confirmToDelete();
}
