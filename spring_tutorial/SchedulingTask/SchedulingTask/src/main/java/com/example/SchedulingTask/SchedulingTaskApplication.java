package com.example.SchedulingTask;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.scheduling.annotation.EnableScheduling;

@SpringBootApplication
@EnableScheduling
public class SchedulingTaskApplication {

	public static void main(String[] args) {
		SpringApplication.run(SchedulingTaskApplication.class, args);
	}

}

//memo : if you made project using spring initz, you need to check
// project sdk version, gradle sdk version settings()
