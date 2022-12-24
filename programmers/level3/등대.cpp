#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include<iostream>

using namespace std;

vector<vector<int>> board;


bool cmp(vector<int> const& a, vector<int> const& b) {
    return a.size() > b.size();
}

int search(int maxNum) {
	int checkLight = 0; //켜진 등대 수 확인
    int visit[100'001] = { 0 }; //방문했는지?
	vector<pair<int, int>> turnOnLight; //<켜진등대번호, <-의 board 번호>

    // 가장 많이 연결되어있는 등대 넣기
    turnOnLight.push_back({ board[0][0],0 });
    for (auto b : board[0]) {
        visit[b]++;
        checkLight += 1;
    }

    // 그 후 비교 분석
    for (int i = 1; i < maxNum; i++) {
        if (checkLight == maxNum) break;

        int curBoardSize = board[i].size();
        int isVisited = 0;
        vector<pair<int, int>>::iterator it;
        for (int a = 0; a < curBoardSize; a++) {
            if (!visit[board[i][a]]) {
                /*  visit[board[i][a]] = true;
                  checkLight += 1;*/
                it = find_if(turnOnLight.begin(), turnOnLight.end(),
                    [=](const pair<int, int>& elem) {return elem.first == board[i][a]; });
                if (turnOnLight.end() == it) isVisited = 1; //turnOnLight 에서 board[i][a]가 없으면 1
                else isVisited = 2;

            }
        }

        if (isVisited != 0) {
            for (int a = 0; a < curBoardSize; a++) {
                if (visit[board[i][a]] == 0)checkLight += 1;
                visit[board[i][a]]++;
            }

            if (isVisited == 2) {
                int checkBoardNum = it->second;
                for (auto b : board[checkBoardNum]) {
                    if (visit[b] - 1 == 0) isVisited == 3;
                }
                if (isVisited != 3) {
                    for (auto b : board[checkBoardNum]) {
                        visit[b]--;
                    }
                    turnOnLight.erase(it);
                }
            }
            turnOnLight.push_back({ board[i][0],i });
        }
    }

    return turnOnLight.size();
}

int solution(int n, vector<vector<int>> lighthouse) {
    board.assign(n + 1, vector<int>());
    for (int i = 0; i < n + 1; i++) {
        board[i].push_back(i);
    }
    for (auto li : lighthouse) {
        board[li[0]].push_back(li[1]);
        board[li[1]].push_back(li[0]);
    }
    sort(board.begin(), board.end(),cmp);


    for (int i = 0; i < n; i++) {
        cout << i << " : ";
        for (auto b : board[i]) cout << b << " ";
        cout << endl;
    }
    return search(n);
}