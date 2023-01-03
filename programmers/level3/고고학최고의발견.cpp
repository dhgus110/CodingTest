#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxSize;
int minRun = 1e9;
int dx[5] = { 1,-1,0,0,0 };
int dy[5] = { 0,0,1,-1,0 };

bool limitLine(int x, int y) {
    if (x < 0 || y < 0 || x >= maxSize || y >= maxSize) return false;
    return true;
}
void turnClocks(int x, int y, vector<vector<int>>& clockHands) {
    for (int i = 0; i < 5; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if (limitLine(mx, my))
            clockHands[mx][my] = (clockHands[mx][my] + 1 == 4) ? 0 : clockHands[mx][my] + 1;
    }
}

bool checkRightClocks(vector<vector<int>>& clockHands) {
    for (auto cl : clockHands)
        for (auto c : cl)
            if (c != 0) return false;
    return true;
}


//기본 행렬에서 윗 줄만 4^n 조작 후
//[x][y]를 0으로 만들기위해 [x+1][y]를 움직임.
void Handler(int cy, int n, vector<vector<int>>& clockHands) {
    vector<vector<int>> temp(clockHands);
    for (int i = 0; i < 4; i++) {
        turnClocks(0, cy, temp);
        vector<vector<int>> temp2(temp);
        int initNum = ((i + 1) % 4 ==0 ? 0 : i + 1) +n;
        int runNum = 0;

        for (int x = 0; x < maxSize - 1; x++) {
            for (int y = 0; y < maxSize; y++) {
                if (temp[x][y] != 0) {
                    while (temp[x][y] % 4 != 0) {
                        turnClocks(x + 1, y, temp);
                        runNum++;
                    }
                }
            }
        }
        runNum += initNum;
        if (checkRightClocks(temp)) {
            minRun = minRun > runNum ? runNum : minRun;
        }

        if(cy+1 < maxSize)
            Handler(cy + 1, initNum, temp2);

        temp.assign(temp2.begin(),temp2.end()); //다시 temp를 temp2로 변경 
    }
}

int solution(vector<vector<int>> clockHands) {
    maxSize = clockHands.size();
    Handler(0,0, clockHands);
    return minRun;
}
