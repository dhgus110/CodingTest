#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int ArrowNum = 0;
int maxScore = 0; //가장 큰 점수 차
vector<int> Apeach;
vector<pair<int, vector<int>>> Results; //[점수차, 라이언이 맞춘 화살들]

void print(vector<int> vv) {
    for (auto v : vv) {
        cout << v << " ";
    }cout << endl;
}


void dfs(int order, int apeachScore, int ryanScore, int ryanArrows, vector<int> ryan) {
    if (order == 11 && ryanScore > apeachScore && ryanArrows <= ArrowNum) {
        ryan[10] += ArrowNum - ryanArrows;
        Results.push_back(make_pair((ryanScore - apeachScore), ryan));
    }

    if (order < 11) {
        //order에서 0개를 맞춤
        if (maxScore < ryanScore - apeachScore) maxScore = ryanScore - apeachScore;
        dfs(order + 1, apeachScore, ryanScore, ryanArrows, ryan);

        //order에서 (Info[order] + 1) 개를 맞춤
        if (Apeach[order] > 0) apeachScore -= (10 - order);
        ryanScore += (10 - order);
        ryan[order] = Apeach[order] + 1;
        ryanArrows += ryan[order];
        if (ryanArrows <= ArrowNum) {
            if (maxScore < ryanScore - apeachScore) maxScore = ryanScore - apeachScore;
            dfs(order + 1, apeachScore, ryanScore, ryanArrows, ryan);
        }
    }

}

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) {
    if (a.first == b.first) {
        for (int i = a.second.size(); i >= 0; i--) {
            if (a.second[i] == b.second[i]) continue;
            else return a.second[i] > b.second[i];
        }
    }
    else
        return a.first > b.first;
}

vector<int> solution(int n, vector<int> info) {
    int apeachScore = 0;
    ArrowNum = n;
    Apeach = info;

    for (int i = 0; i < info.size(); i++) {
        if (info[i] > 0) apeachScore += 10 - i;
    }

    vector<int> ryan(11);

    dfs(0, apeachScore, 0, 0, ryan);
    if (maxScore == 0) return{ -1 };

    sort(Results.begin(), Results.end(), cmp);
    
    return Results[0].second;
    
}
