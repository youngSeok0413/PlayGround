package lec5.entity;

public class NewlecExam implements Exam{
	private int kor;
	public int getKor() {
		return kor;
	}

	public void setKor(int kor) {
		this.kor = kor;
	}

	public int getMath() {
		return math;
	}

	public void setMath(int math) {
		this.math = math;
	}

	public int getEng() {
		return eng;
	}

	public void setEng(int eng) {
		this.eng = eng;
	}

	public int getCom() {
		return com;
	}

	public void setCom(int com) {
		this.com = com;
	}

	private int math;
	private int eng;
	private int com;
	
	
	
	public NewlecExam() {
	}

	public NewlecExam(int kor, int math, int eng, int com) {
		this.kor = kor;
		this.math = math;
		this.eng = eng;
		this.com = com;
	}

	@Override
	public int total() {
		return kor+math+eng+com;
	}

	@Override
	public float avg() {
		return total()/4.0f;
	}
	
	@Override
	public String toString() {
		return "kor : " + kor
				+", math : " + math
				+", eng : " + eng
				+", com : " + com;
	}
	
}
