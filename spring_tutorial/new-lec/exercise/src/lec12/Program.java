package lec12;

import java.util.List;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import lec5.entity.Exam;
import lec5.ui.ExamConsole;

public class Program {

	public static void main(String[] args) {
		ApplicationContext context = 
				new AnnotationConfigApplicationContext(NewlecAppConfig.class);
		ExamConsole console = context.getBean(ExamConsole.class); //prefered
		console.print(); 
	}

}
 