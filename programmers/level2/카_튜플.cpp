#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> tuple;

    string num ="";
    vector<int> dummy;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '}' && !num.empty()) { //괄호가 닫힐 때
            dummy.push_back(stoi(num));
            tuple.push_back(dummy);
            num = "";
            dummy.clear();
        }
        else if (isdigit(s[i]) != 0) {  //숫자이면
            num += s[i];
        }
        else if (s[i] == ',' && !num.empty()) {
            dummy.push_back(stoi(num));
            num = "";
        }
    }
    sort(tuple.begin(), tuple.end(), cmp);

    for (auto tu : tuple) {
        for (auto t : tu) {
            bool check = false;
            int s;
            for (auto a : answer) {
                if (t == a) { 
                    check = true; 
                    break;
                }
            }
            if (!check) answer.push_back(t);
        }
    }

    return answer;
}
