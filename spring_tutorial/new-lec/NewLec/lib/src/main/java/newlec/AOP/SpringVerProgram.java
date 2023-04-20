package newlec.AOP;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import newlec.AOP.entity.Exam;

//Spring proxy version
public class SpringVerProgram {
	public static void main(String[] args) {
		ApplicationContext context = new ClassPathXmlApplicationContext("newlec/AOP/advice/setting.xml");
		
		Exam proxy = (Exam) context.getBean("proxy");
		
		System.out.printf("total is %d, avg is %f", proxy.total(), proxy.avg());
	}
}
