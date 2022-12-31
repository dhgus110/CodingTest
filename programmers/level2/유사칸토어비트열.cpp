#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

using namespace std;

int f(int n, long long x) {
    if (n == 1) {
        return x % 5 != 2;
    }
    else {
        if (!f(n - 1, x / 5)) {
            return 0;
        }
        else {
            return x % 5 != 2;
        }
    }

    return n == 1 ? x % 5 != 3 : !f(n - 1, x / 5) ? 0 : x % 5 != 3;
}
int solution(int n, long long l, long long r) {
    int answer = 0;
    for (long long i = l - 1; i < r; i++) {
        answer += f(n, i);
    }
    return answer;
}
