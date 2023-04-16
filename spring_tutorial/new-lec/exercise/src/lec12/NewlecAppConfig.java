package lec12;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

import lec5.entity.Exam;
import lec5.entity.NewlecExam;

//exactly same with xml file
@ComponentScan({"le5.entity", "lec5.ui"}) // = <context:component-scan base-package=""/>
@Configuration
public class NewlecAppConfig {
	
	@Bean
	public Exam exam() { //method name = id name
		return new NewlecExam();
	}
}
