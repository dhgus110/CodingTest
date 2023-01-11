#include <string>
#include <vector>
#include <iostream>
using namespace std;

int position[26] = { 0 };

vector<int> solution(string s) {
    vector<int> answer;
    for (int i = 0; i < s.length(); i++) {
        int now = s[i] - 97;
        if (position[now] == 0) {
            position[now] = i + 1;
            answer.push_back(-1);
        }
        else {
            answer.push_back(i + 1 - position[now]);
            position[now] = i + 1;
        }
    }
    return answer;
}