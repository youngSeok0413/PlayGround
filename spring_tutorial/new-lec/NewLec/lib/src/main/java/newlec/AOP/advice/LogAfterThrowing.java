package newlec.AOP.advice;

import org.springframework.aop.AfterReturningAdvice;
import org.springframework.aop.ThrowsAdvice;

public class LogAfterThrowing implements ThrowsAdvice{
	//딱히 인자가 정해진 것이 없어서 오버라이드할 메서드가 없다.
	public void afterThrowing(IllegalArgumentException e) throws Throwable{
		System.out.println("뀨뀨 오류 " + e.getMessage());
	}
}
