#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

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
    vector<pair<int,int>> results;
    emoticonsSize = emoticons.size();
    numberOfCases({}, 0);

    for (int i = 0; i < cases.size(); i++) {
        int members = 0; //서비스 가입자 수
        int sales = 0; //판매액
        for (int user = 0; user < users.size(); user++) {
            int userMoneySpend = 0;
            bool checkSignup = false;
            for (int j = 0; j < emoticons.size(); j++) {
                int price = (emoticons[j] / 100) * (100 - cases[i][j]);
                //각 사용자들은 자신의 기준에 따라 일정 비율 이상 할인하는 이모티콘
                if (cases[i][j] >= users[user][0]) {
                    userMoneySpend += price;
                }
                //각 사용자들은 자신의 기준에 따라 이모티콘 구매 비용의 합이 일정 가격 이상
                if (users[user][1] <= userMoneySpend) {
                    checkSignup = true;
                    break;
                }
                /*if (cases[i][j] >= users[user][0]) 
                    cout << cases[i][j] << "%->" << price << " okay, ";
                else
                    cout << cases[i][j] << "%->" << price << " no, ";*/

            }
            //cout << " wallet :" << userMoneySpend << endl;
            if (checkSignup) members += 1;
            else sales += userMoneySpend;
        }

        results.push_back({ members,sales });
    }
    sort(results.begin(), results.end(),greater<>());

    answer.push_back(results[0].first);
    answer.push_back(results[0].second);

    return answer;
}



//할인율 10 20 30 40
//1<= 이모티콘(n) <=7    -> n^4
//유저 최대 100명 

//O(n^4 * 100 * n ) 
