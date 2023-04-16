package lec6;

import java.util.List;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import lec5.entity.Exam;
import lec5.entity.NewlecExam;
import lec5.ui.ExamConsole;

public class Program {
	
	/*
	 * public static void main(String args[]) { ApplicationContext context = new
	 * ClassPathXmlApplicationContext("lec6/setting.xml"); List<Exam> exams =
	 * (List<Exam>) context.getBean("exams"); //exams.add(new for(Exam e : exams)
	 * System.out.println(e); ExamConsole console =
	 * context.getBean(ExamConsole.class); //prefered console.print(); }
	 */
}


//reused ui, entity classes 
//using Maven or Gradle makes managing dependency much easier