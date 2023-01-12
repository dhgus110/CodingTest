#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    if (n % 2 == 1)return 2;
    for (int i = 2; i < n; i++) {
        int remainder = n - i * (n / i);
        if (remainder == 1)return i;
    }
    return answer;
}
