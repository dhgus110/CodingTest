#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int pLen = p.length();
    for (int i = 0; i <= t.length() - pLen; i++) {
        string tSub = t.substr(i, pLen);
        if (tSub <= p) answer += 1;
    }
    return answer;
}