#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

vector<string> subString(string s) {
    vector<string> split;

    int curPos = 0;
    int nextPos;
    while ((nextPos =s.find(' ', curPos)) != string::npos) {
        int len = nextPos - curPos;
        if(s.substr(curPos, len) !="and")
            split.push_back(s.substr(curPos, len));
        curPos = nextPos + 1;
    }
    split.push_back(s.substr(curPos)); //마지막 남아있는 문자열 저장

    return split;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string way[16] = { "0000","0001","0010","0100","1000","0011","0101","1001","0110","1010","1100",
    "0111","1011","1101","1110","1111" }; //2^4 경우 존재

    map<string, vector<int>> cases; //모든 경우의 수 저장
    for (auto i : info) {
        vector<string> s = subString(i);
        for (int j = 0; j < 16; j++) {
            string key = "";
            key += (way[j][0] == '0') ? "-" : s[0];
            key += (way[j][1] == '0') ? "-" : s[1];
            key += (way[j][2] == '0') ? "-" : s[2];
            key += (way[j][3] == '0') ? "-" : s[3];
            if (cases.find(key) != cases.end()) //존재할 때
                cases[key].push_back(stoi(s[4]));
            else
                cases[key] = vector<int>{stoi(s[4])};
        }
    }

    for (auto que : query) {
        int satisfy = 0;
        vector<string> q = subString(que);
        string condition = q[0] + q[1] + q[2] + q[3]; //조건
        int score = stoi(q[4]); //점수
        if (cases.find(condition) != cases.end()) { //cases안에 조건이 있을 때
            for (auto c : cases[condition]) {
                if (c >= score)satisfy++;
            }
        }
        answer.push_back(satisfy);
    }

    return answer;
}

//---------------------좀 더 정리한 방법-------------------//
const string ALL = "-";
map<string, vector<int>> cases;

void insert(string* key, int mask, int point) {
    string s = "";
    for (int i = 0; i < 4; i++) {
        s += (mask & (1 << i)) ? ALL : key[i]; //위에서 string way[16]를 대신하는 방법
        cases[s].push_back(point);
    }
}

vector<int> solution1(vector<string> info, vector<string> query) {
    vector<int> answer;
    string key[4], tmp;
    int point;

    for (auto& inf : info) {
        istringstream iss(inf);
        iss >> key[0] >> key[1] >> key[2] >> key[3] >> point;
        for (int i = 0; i < 16; i++) insert(key, i, point);
    }

    for (auto& m : cases) sort(m.second.begin(), m.second.end());

    for (auto& que : query) {
        istringstream iss(que);
        iss >> key[0] >> tmp >> key[1] >> tmp >> key[2] >> tmp >> key[3] >>
            point;
        string s = key[0] + key[1] + key[2] + key[3];
        vector<int>& v = cases[s];
        answer.push_back(v.end() - lower_bound(v.begin(), v.end(), point));
    }

    return answer;
}
