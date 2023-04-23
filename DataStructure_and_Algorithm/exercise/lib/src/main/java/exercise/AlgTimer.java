package exercise;

public class AlgTimer {
	public static long start() {
		return System.currentTimeMillis();
	}
	
	public static long end() {
		return System.currentTimeMillis();
	}
	
	public static float time(long start, long end) {
		return (end-start)/1000.f;
	}
}

