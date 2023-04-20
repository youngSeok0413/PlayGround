package newlec.AOP.entity;

public class NewlecExam implements Exam{
	private int kor;
	private int math;
	private int eng;
	private int com;
	
	public NewlecExam() {}
	
	public NewlecExam(int kor, int math, int eng, int com) {
		this.kor = kor;
		this.math = math;
		this.eng = eng;
		this.com = com;
	}

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

	@Override // core concern
	public int total() {
		
		if(kor > 100)
			throw new IllegalArgumentException("유효하지 않은 국어점수");
		
		/* long start = System.currentTimeMillis(); */ //cross-cutting concern
		int result = kor + math + eng + com;
		/*
		 * try { Thread.sleep(200); } catch (InterruptedException e) { // TODO
		 * Auto-generated catch block e.printStackTrace(); } long end =
		 * System.currentTimeMillis();
		 * 
		 * System.out.println(end-start);
		 */
		return result;
	}

	@Override //core concern
	public float avg() {
		//proxy
		float result = total()/4;
		//proxy
		return result;
	}

}
