#include <iostream>
#include <cmath>
#define INF 1e9
#define ll long long
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
	if (a == 1) {
		return 1;
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

ll solution(int w, int h) {
    ll answer = 1;
	ll maxBox = (ll)w * (ll)h;
	int gcd = gcdFunction(w, h);
	int gcdW = w / gcd, gcdH = h / gcd;
	//answer = maxBox - gcd* (gcdW + gcdH - 1); //대각선을 포함한 사각형: gcdW + gcdH - 1
	answer = maxBox - w - h + gcd;

    return answer;
}

