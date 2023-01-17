#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

//문자열에서 "110" 삭제하기
int deletePack(string& s) {
    int cnt = 0;
    /*  find(),erase()사용 시간초과
    while (true)
    {
        auto sfind = s.find("110");
        if (sfind == string::npos) break;
        s.erase(sfind, 3);
        cnt += 1;
    }*/

    //스택사용으로 시간 줄이기
    stack<char> st;
    int i = 0;
    int len = s.length();
    while (i != len)
    {
        if (s[i] == '0'&& st.size()>=2) {
            char c = st.top();
            st.pop();
            if (st.top() == '1' && c == '1') {
                st.pop();
                cnt += 1;
            }
            else {
                st.push(c);
                st.push(s[i]);
            }
        }
        else {
            st.push(s[i]);
        }
        i += 1;
    }
    string temp;
    stringstream ss;
    while (!st.empty())
    {
        ss << st.top();
        st.pop();
    }
    ss >> temp;
    reverse(temp.begin(), temp.end());
    s = temp;
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
        auto sfind1 = s.find("11");
        if (sfind1 != string::npos) {
            string temp;
            for (int i = 0; i < cnt; i++)temp += pack;
            s.insert(sfind1, temp);
            break;
        }
        auto sfind2 = s.rfind("0");
        if (sfind2 != string::npos) {
            if (sfind2 == s.length() - 1)
                s += pack;
            else
                s.insert(sfind2 + 1, pack);
            cnt -= 1;
            continue;
        }
        auto sfind3 = s.find("1");
        if (sfind3 != string::npos) {
            s.insert(sfind3, pack);
            cnt -= 1;
            continue;
        }
    }
    return s;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (auto ss : s) {
        string temp = ss;
        int cnt = deletePack(temp);
        answer.push_back(convert(temp,cnt));
    }

    return answer;
}
