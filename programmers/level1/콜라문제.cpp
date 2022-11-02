#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = n / a * b;
    int cur = n;
    while (true) {
        cur = (cur / a * b + cur % a);
        answer += (cur / a * b);
        cout << cur << "  " << answer << endl;
        if (cur<= a)break;

    }
    return answer;
}

//´õ °£´Ü
int solution2(int a, int b, int n) {
    return (n > b ? (n - b) / (a - b) * b : 0);
}

int main() {
    solution(3, 1, 20);
}