package lec5.ui;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import lec5.entity.Exam;

@Component("console")
public class InlineExamConsole implements ExamConsole {
	private Exam exam;

	public Exam getExam() {
		return exam;
	}

	@Autowired
	@Override
	public void setExam(Exam exam) {
		this.exam = exam;
	}

	@Override
	public void print() {
		System.out.printf("total is %d, avg is %f\n", exam.total(), exam.avg());
	}
	
}
