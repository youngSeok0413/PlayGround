package newlec.AOP.ui;

import newlec.AOP.entity.Exam;

public class InlineConsole implements ExamConsole{

	private Exam exam;
	
	public InlineConsole() {}
	
	public InlineConsole(Exam exam) {
		this.exam = exam;
	}

	public Exam getExam() {
		return exam;
	}

	public void setExam(Exam exam) {
		this.exam = exam;
	}

	@Override
	public void print() {
		System.out.printf("total is %d, avg is %f", exam.total(), exam.avg());
	}

}
