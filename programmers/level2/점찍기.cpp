#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
	long double powD = (long double)d *d;
	for (int x = 0; x <= d; x+=k) {
		long double maxY = sqrt(powD - (long double)x * x);
		answer += maxY / k + 1;
    }

    return answer;
}