package lec5.ui;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;

import lec5.entity.Exam;

public class GridExamConsole implements ExamConsole {
	
	Exam exam;
	
	public Exam getExam() {
		return exam;
	}
	
	@Autowired
	@Qualifier("exam")
	@Override
	public void setExam(Exam exam) {
		this.exam = exam;
	}

	@Override
	public void print() {
		System.out.println("┌─────────┬─────────┐");
		System.out.println("│  total  │   avg   │");
		System.out.println("├─────────┼─────────┤");
		 System.out.printf("│   %3d   │  %3.2f   │\n",exam.total(),exam.avg());
		System.out.println("└─────────┴─────────┘");
	}

	
}
