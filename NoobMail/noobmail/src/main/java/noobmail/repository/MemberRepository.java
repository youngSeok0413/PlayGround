package noobmail.repository;

import java.util.List;

import noobmail.domain.Member;

public interface MemberRepository {
	//create account
	public void save(Member member);
	//find account
	public Member findById(Long id);
	public Member findByName(String name);
	public List<Member> findAll();
	//delete account
	public void secession();
}
