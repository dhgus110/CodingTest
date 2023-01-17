#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

int deletePack(string& s) {
    int cnt = 0;
    //for (int i = 0; i < s.length()-2; i++) {
    //    string dummy;
    //    stringstream ss;
    //    ss << s[i] << s[i + 1] << s[i + 2];
    //    ss >> dummy;  // or dummy = ss.str();
    //    
    //}
    while (s.find("110") != string::npos)
    {
        s.erase(s.find("110"), 3);
        cnt += 1;
    }
    return cnt;
}

string convert(string s, int cnt) {
    string pack = "110";
    if (s.empty()) {
        for (int i = 0; i < cnt; i++) {
            s += pack;
        }
        return s;
    }
    while (cnt != 0) {
        if (s.find("11") != string::npos) {
            s.insert(s.find("11"), pack);
            cnt -= 1;
            continue;
        }
        else if (s.rfind("0") != string::npos) {
            if (s.rfind("0") == s.length() - 1)
                s += pack;
            else
                s.insert(s.rfind("0") + 1, pack);
            cnt -= 1;
            continue;
        }
        else if (s.find("1") != string::npos) {
            s.insert(s.find("1"), pack);
            cnt -= 1;
            continue;
        }
    }
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    deletePack(s[0]);


    return answer;
}