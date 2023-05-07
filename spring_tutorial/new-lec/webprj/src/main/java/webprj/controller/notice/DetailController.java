package webprj.controller.notice;

import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.Controller;

import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class DetailController implements Controller{

	@Override
	public ModelAndView handleRequest(HttpServletRequest request, HttpServletResponse response) throws Exception {
		ModelAndView mv = new ModelAndView("notice/detail");
		//mv.setViewName("index"); // 이것도 하나의 요청임 url은 상대경로에 영향을 준다, 파일을 찾을 때 현재 위치와 같은 곳에 있다 생각한다. 그냥 절대 경로를 사용해라

		return mv;
	}

}
