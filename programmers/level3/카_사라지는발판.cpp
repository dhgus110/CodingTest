#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#define PII pair<int,int>
#define INF 1e9

using namespace std;

PII moveB(vector<vector<int>>& board, PII posA, PII posB);

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int maxX ,maxY;

bool safeArea(vector<vector<int>>const& board ,PII const pos){
    if (pos.first < 0 || pos.first >= maxY || pos.second < 0 || pos.second >= maxX)
        return false;
    if (board[pos.first][pos.second]== 0)
        return false;
    return true;
}

PII moveA(vector<vector<int>>& board, PII posA, PII posB){
    //내 발판이 사라졌을 경우 (패배)
    if(board[posA.first][posA.second] == 0) return make_pair(0,false);

    int maxCnt = -1;
    int minCnt = INF;
    bool flag =true;
    int check = 0;

    for (int i = 0; i < 4; i++){
        PII nextA = make_pair(posA.first + dy[i], posA.second + dx[i]);

        if (!safeArea(board, nextA))
            continue;

        board[posA.first][posA.second] = 0;
        PII ret = moveB(board, nextA, posB);
        if (ret.second)
            maxCnt = max(maxCnt, ret.first);
        else
            minCnt = min(minCnt, ret.first);
        board[posA.first][posA.second] = 1;

        flag &= ret.second;
        check++;
    }
    //주변 발판이 모두 0일 경우 (패배)
    if(check == 0) return make_pair(0 , false);
    //내가 졌을 경우 (최대한 늦게 지기)
    if(flag) return make_pair(maxCnt + 1, false);
    //내가 이겼을 경우 (최대한 일찍 이기기)
    else return make_pair(minCnt + 1, true);
}

PII moveB(vector<vector<int>>& board, PII posA, PII posB){
    if(board[posB.first][posB.second] == 0) return make_pair(0,false);

    int maxCnt = -1;
    int minCnt = INF;
    bool flag =true;
    int check = 0;
    for (int i = 0; i < 4; i++){
        PII nextB = make_pair(posB.first + dy[i], posB.second + dx[i]);

        if (!safeArea(board, nextB))
            continue;

        board[posB.first][posB.second] = 0;
        PII ret = moveA(board, posA, nextB);
        if (ret.second)
            maxCnt = max(maxCnt, ret.first);
        else
            minCnt = min(minCnt, ret.first);
        board[posB.first][posB.second] = 1;

        flag &= ret.second;
        check++;
    }
    if(check == 0) return make_pair(0 , false);
    if(flag) return make_pair(maxCnt + 1, false);
    else return make_pair(minCnt + 1, true);
}


int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    maxX = board[0].size();
    maxY = board.size();

    PII posA = make_pair(aloc[0], aloc[1]);
    PII posB = make_pair(bloc[0], bloc[1]);

    //A run
    PII ans = moveA(board, posA, posB);

    return ans.first;
}