#include <iostream>
#define INF 1e9
using namespace std;

//최대 공약수 구하기
int gcdFunction(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

//제일 작은 약수 구하기
int factor(int a) {
	int num= INF;
	if (a <= 0) {
		return INF;
	}

	for (int i = 2; i * i <= a; i++) {

		if (i * i == a) {
			if (num > i) {
				num = i; break;
			}
		}
		else if (a % i == 0) {
			if (num > i) {
				num = i; break;
			}
		}
	}
	return num;
}

int f(int w, int h) {
	int n = 0;

	for (float i = 1; i <= h; i+=1) {
		float sectionH = i / h;
	}

	return n;
}

long long solution(int w, int h) {
    long long answer = 1;

	int divi = 0;
	int minW = 0, minH = 0;

	if (w == h) {
		divi = factor(w) != INF ? factor(w) : w ;
	}
	else {
		divi = gcdFunction(w, h);
		minW = w / divi;
		minH = h / divi;

	}
	


    return answer;
}