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


//¿≠ ¡Ÿ∏∏ 4^n ¡∂¿€ »ƒ ∆€¡Ò «ÿ∞·
void Handler(int cy, vector<vector<int>>& clockHands) {
    vector<vector<int>> temp(clockHands);
    vector<vector<int>> temp2(temp);
    for (int i = 0; i < 4; i++) {
        turnClocks(0, cy, temp);

        int runNumber = 0;

        if (cy == 0 && i == 3) {
            for (auto cl : temp) {
                for (auto c : cl) {
                    cout << c << " ";
                }
                cout << endl;
            }
        }

        for (int x = 0; x < maxSize - 1; x++) {
            for (int y = 0; y < maxSize; y++) {
                if (temp[x][y] != 0) {
                    while (temp[x][y] % 4 != 0) {
                        turnClocks(x + 1, y, temp);
                        runNumber++;
                    }
                }
            }
        }
        if (checkRightClocks(temp))
            minRun = minRun > runNumber ? runNumber : minRun;

        if(cy+1 < maxSize)
            Handler(cy + 1, temp2);

        temp = temp2;
    }
}

int solution(vector<vector<int>> clockHands) {
    maxSize = clockHands.size();
    Handler(0, clockHands);
    return minRun;
}


//[[0, 1, 3, 0], [1, 2, 0, 0], [3, 0, 2, 2], [0, 2, 0, 0]] 8