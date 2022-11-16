#include <string>
#include <vector>
#include <cstdlib> //abs for int

using namespace std;

int dx[] = { 0,0,0,0,1,-1,2,-2 };
int dy[] = { 1,-1,2,-2,0,0,0,0 };
int dCornerX[] = { 1,1,-1,-1 };
int dCornerY[] = { 1,-1,1,-1 };
int maxline;

bool limitArea(int x, int y) {
    if (x<0 || x>maxline-1 || y<0 || y>maxline-1) return false;
    else return true;
}

bool search(int x, int y, vector<string>const& place) {
   
    for (int n = 0; n < 8; n++) {
        int curX = x + dx[n];
        int curY = y + dy[n];
        if (!limitArea(curX, curY)) continue; 
        if (place[curX][curY] != 'P') continue;

        if (dx[n] == 2 && place[curX - 1][curY] == 'X') continue;
        else if (dy[n] == 2 && place[curX][curY - 1] == 'X') continue;
        else if (dx[n] == -2 && place[curX + 1][curY] == 'X') continue;
        else if (dy[n] == -2 && place[curX][curY + 1] == 'X') continue;
        return false;

    }
    for (int n = 0; n < 4; n++) {
        int curX = x + dCornerX[n];
        int curY = y + dCornerY[n];
        if (!limitArea(curX, curY)) continue;
        if (place[curX][curY] == 'P') {
            if (place[curX][y] != 'X' || place[x][curY] != 'X') { 
                return false; 
            }
        }
    }
    return true;

}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    maxline = places[0][0].length();

    for (auto place : places) {
        bool check = true;
        for (int i = 0; i < place.size(); i++) {
            for(int j = 0; j< place[i].size();j++){
                if (place[i][j]=='P' && !search(i, j, place)) {
                    check = false;  //지키고있는 사람이 없으면 false
                    break;
                }
            }
            if (!check) break;
        }
        if (check)answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}
