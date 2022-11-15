#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[501][501][4];
vector<string> copy_grid;

//up,down,right,left
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int maxX, maxY;

int limitAreaCheck(int n, bool isX) {
    if (isX) {
        if (n < 0)return maxX - 1;
        else if (n == maxX) return 0;
        else return n;
    }
    else {
        if (n < 0)return maxY - 1;
        else if (n == maxY) return 0;
        else return n;
    }
}

int changeDir(char c, int dir) {
    if (c == 'L') {
        if (dir == 0)return 3;
        if (dir == 1)return 2;
        if (dir == 2)return 0;
        if (dir == 3)return 1;
    }
    if (dir == 0) return 2;
    if (dir == 1) return 3;
    if (dir == 2) return 1;
    if (dir == 3) return 0;
}

int search(int x, int y, int dir, int count) {
    if (visited[x][y][dir]) return count;
    visited[x][y][dir] = true;

    int nextDir = dir;
    if (copy_grid[x][y] != 'S') nextDir = changeDir(copy_grid[x][y], dir);
    int nextX = limitAreaCheck(x + dx[nextDir], true);
    int nextY = limitAreaCheck(y + dy[nextDir], false);

    return search(nextX, nextY, nextDir, count + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    //init
    copy_grid = grid;
    maxY = grid[0].size();
    maxX = grid.size();

    for (int x = 0; x < maxX; x++) {
        for (int y = 0; y < maxY; y++) {
            for (int i = 0; i < 4; i++) {
                int path = search(x, y, i, 0);
                if (path != 0)answer.push_back(path);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}