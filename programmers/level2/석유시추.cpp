#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[501][501];
int oilSum[502];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int verSize, colSize;

void init(vector<vector<int>>const& land){
    fill_n(&visited[0][0], 501 * 501, false);
    fill_n(oilSum, 501, 0);
    verSize = land.size();
    colSize = land[0].size();
}

bool safeArea(int ver,int col){
    return ver >= 0 && ver < verSize && col >= 0 && col < colSize;
}

void bfs(vector<vector<int>>const& land){
    for (int y = 0; y < verSize; y++)
    {
        for (int x = 0; x < colSize; x++)
        {
            if (visited[y][x] || land[y][x] == 0) continue;

            queue<pair<int, int>> q;
            q.push(make_pair(y, x));
            visited[y][x] = true;
            int xPostions[502]={0,};
            xPostions[x]++;
            int oil = 1;

            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int i = 0; i < 4; i++){
                    int nextY = cur.first + dy[i];
                    int nextX = cur.second + dx[i];

                    if (safeArea(nextY, nextX) && land[nextY][nextX] == 1 && !visited[nextY][nextX]){
                        q.push(make_pair(nextY, nextX));
                        visited[nextY][nextX] = true;
                        xPostions[nextX]++;
                        oil++;
                    }
                }
            }

            for (int x = 0 ; x<colSize ;x++)
            {
               if(xPostions[x]>0) oilSum[x + 1] += oil;
            }
        }
    }
}

int calculateMostOil(){
    int mostOil=0;
    for (int i = 0 ; i<=colSize ; i++ ){
        if(mostOil < oilSum[i]) mostOil = oilSum[i];
    }
    return mostOil;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    init(land);
    bfs(land);
    answer = calculateMostOil();
    return answer;
}