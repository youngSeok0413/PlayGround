package com.example.tutorial;

import java.util.concurrent.atomic.AtomicLong;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class GreetingController {

    private static final String template = "Hello, %s!";
    private final AtomicLong counter = new AtomicLong();

    @GetMapping("/greeting")
    public Greeting greeting(@RequestParam(value = "name", defaultValue = "World") String name) {
        return new Greeting(counter.incrementAndGet(), String.format(template, name));
    }
}

/*This is for memo
To make Spring project, it is very easy if you use https://start.spring.io/.
It will takes time if it is first time to make Spring project(It takes time to download modules for project!!)
Spring does everything for you!!

json : kind of data form, basic dto(if there is no specific def)
record : new type of class easy to create immutable data instance
    implicitly cannot be inherited, but able to be implemented

@RestController = @Controller + @ResponseBody
@GetMapping : ensure Http GET request <=> @PostMapping : ensure Http POST request
@RequestParam : binds the value of the query string parameter into function parameter, defaultValue is default value

A key difference between a traditional MVC controller
and the RESTful web service controller shown earlier is the way that the HTTP response body is created.
The object data will be written directly to the HTTP response as JSON.(rest-api)

Thanks to Jackson 2(default Springs json converter), easy to get json form data

@SpringBootApplication = @Configuration + @EnableAutoConfiguration + @ComponentScan

The main() method uses Spring Boot’s SpringApplication.run() method to launch an application.

Alternatively, you can build the JAR file by using ./gradlew build
and then run the JAR file, as follows:java -jar build/libs/gs-rest-service-0.1.0.jar
* */