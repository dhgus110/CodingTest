#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string timeToString(int h, int m) {
    string s="";
    if (h < 10) s += "0";
    s += to_string(h);
    s += ":";
    if (m < 10) s += "0";
    s += to_string(m);
    return s;
}

pair<int, int> add10Min(string s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    if (m >= 50) {
        m -= 50;
        h += 1;
    }
    else {
        m += 10;
    }
    return { h,m };
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<string> end_time;
    sort(book_time.begin(), book_time.end());
    
    for (auto bo : book_time) {
        bool check = false;
        for (int i = 0; i < end_time.size(); i++) {
            if (bo[0] >= end_time[i]) {
                pair<int, int> t = add10Min(bo[1]);
                end_time[i] = timeToString(t.first, t.second);
                check = true;
                break;
            }
        }
        if (!check) {
            pair<int, int> t = add10Min(bo[1]);
            end_time.push_back(timeToString(t.first, t.second));
        }
    }

    return end_time.size();
}