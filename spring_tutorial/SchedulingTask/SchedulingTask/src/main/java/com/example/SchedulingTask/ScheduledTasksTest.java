package com.example.SchedulingTask;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.scheduling.config.ScheduledTask;
import org.springframework.stereotype.Component;

import java.text.SimpleDateFormat;
import java.util.Date;

@Component
public class ScheduledTasksTest {

    private static final Logger log = LoggerFactory.getLogger(ScheduledTask.class);
    private static final SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm:ss");

    @Scheduled(fixedRate = 5000)
    public void reportCurrentTime(){
        log.info("The time is now {}", dateFormat.format(new Date()));
    }
}

/*This is for meme
need to add awaitility lib(using gradle it is very easy to add lib!!)
@Scheduled : annotaion that marks a method to be scheduled. Exactly one of the cron(), fixdeDelay(), fixedRate()
    attribute must be used. The method would have void type return. can be used as a repeatable annotation.

doc : https://docs.spring.io/spring-framework/docs/current/javadoc-api/org/springframework/scheduling/annotation/Scheduled.html

* */
