package newlec.AOP;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

import newlec.AOP.entity.Exam;
import newlec.AOP.entity.NewlecExam;

//pure proxy version
public class Program {

	public static void main(String[] args) {
		/*
		Exam exam = new NewlecExam(1, 1, 1, 1);
		//기능적으로는 동일하나 곁다리 업무를 가지고 있다.
		Exam proxy = (Exam)Proxy.newProxyInstance(NewlecExam.class.getClassLoader(), 
				new Class[] {Exam.class}, 
				new InvocationHandler() {
					
					@Override
					public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
						long start = System.currentTimeMillis();
						
						Object obj = method.invoke(exam, args); //실제 업무 담당 객체(클래스 내 메서드 호출)
						
						try {
							Thread.sleep(200);
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
						long end = System.currentTimeMillis();
						
						System.out.println(end-start);
						return obj;
					}
				}); //실제 클래스 정보, 클래스가 속한 인터페이스 정보(들) 
		
		System.out.printf("total is %d, avg is %f", proxy.total(), proxy.avg());*/
	}

}
