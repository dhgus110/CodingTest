#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a.size() > b.size())return a > b;
    else return a < b;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> tuple;

    string num ="";
    vector<int> dummy;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '}' && !num.empty()) { //°ýÈ£°¡ ´ÝÈú ¶§
            dummy.push_back(stoi(num));
            tuple.push_back(dummy);
            num = "";
            dummy.clear();
        }
        else if (isdigit(s[i]) != 0) {  //¼ýÀÚÀÌ¸é
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
            cout << t << " ";
        }
        cout<<"    "<<tu.size() << endl;
    }
    return answer;
}