//#include <iostream>
//#include <cstdio>
//#include <thread>
//#include <vector>
//#include <time.h>
//using std::thread;
//using std::vector;
//
//typedef long long LL;
//
//LL fibo_recur(int x) {
//
//	if (x <= 2)
//		return 1;
//
//	LL	res = fibo_recur(x - 1) + fibo_recur(x - 2);
//	return res;
//}
//
//LL fibo_recur2(int x, LL* result) {
//
//	if (x <= 2) {
//		*result = 1;
//		return 1;
//	}
//
//	*result = fibo_recur(x - 1) + fibo_recur(x - 2);
//	return *result;
//}
//
//int main() {
//
//	// clock_t start, end;
//	time_t start, end;
//	int x;
//	LL result;
//
//	x = 40;
//
//	// single thread
//	start = clock();
//
//	result = fibo_recur(x);
//
//	end = clock();
//
//	std::cout << "Result of fibo in single thread (" << x << ") : " << result << " / Time elapsed : " << (double)(end - start) << std::endl;
//
//
//	// multi thread
//	LL res1, res2;
//	start = clock();
//
//	thread f1(fibo_recur2, x - 2, &res1);
//	thread f2(fibo_recur2, x - 1, &res2);
//	f1.join();
//	f2.join();
//	result = res1 + res2;
//
//	end = clock();
//
//
//	std::cout << "Result of fibo in multi thread (" << x << ") : " << result << " / Time elapsed : " << (double)(end - start) << std::endl;
//	
//	return 0;
//}