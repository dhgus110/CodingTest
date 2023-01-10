#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int sLen = s.length();
    int cur = 0;

    while (cur<sLen) {
        char x = s[cur];
        int xCnt = 1;
        int yCnt = 0;
        for (int i = cur + 1; i < sLen; i++) {
            if (s[i] == x)xCnt++;
            else if (s[i] != x)yCnt++;
            if (i == sLen - 1 || xCnt == yCnt) {
                answer += 1;
                cur = i + 1;
                break;
            }
        }
        if (cur == sLen - 1) { 
            answer += 1; break;
        }
    }

    return answer;
}