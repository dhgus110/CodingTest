#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<int, int, greater<int>> results;
vector<vector<int>> cases;
int emoticonsSize;

void numberOfCases(vector<int> dummy, int cur) {
    if (cur == emoticonsSize) {
        cases.push_back(dummy);
        return;
    }
    for (int i = 1; i <= 4; i++) {
        vector<int> dummy1(dummy);
        dummy1.push_back(i * 10);
        if (cur < emoticonsSize)numberOfCases(dummy1, cur + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    emoticonsSize = emoticons.size();
    numberOfCases({}, 0);
    for (int i = 0; i < cases.size(); i++) {
        int members = 0;
        int sales = 0;

        for (int j = 0; j < emoticons.size(); j++) {
            int price = (emoticons[j] / 100) * (100 - cases[i][j]);

        }
    }
    return answer;
}



//할인율 10 20 30 40
//1<= 이모티<=7    -> n^4
//유저 최대 100명 