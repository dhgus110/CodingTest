#include <string>
#include <vector>
#include <queue>

using namespace std;
//S: 시작 지점
//E : 출구
//L : 레버
//O : 통로
//X : 벽

bool** visited;
int graphStoL[101][101];
int graphLtoE[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void init(vector<string>const& maps) {
    int x = maps[0].size();
    int y = maps.size();
    visited = new bool* [y];
    for (int i = 0; i < y; i++)visited[i] = new bool[x];

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (maps[i][j] == 'X') visited[i][j] = true; //갈 수 없는 곳 or 방문한 곳 = true
            else visited[i][j] = false; //갈 수 있는 곳임 = false 
        }
    }
}

void bfs(pair<int, int> start, bool isStoL,vector<string>const& maps) {
    init(maps);
    queue <pair<int, int>> q;
    q.push(start); 
    visited[start.first][start.second] = true; //방문처리
    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size()) continue; //지도 밖에 벗어나면
            if (!visited[nx][ny]) {
                q.push({ nx,ny });
                visited[nx][ny] = true;
                if(isStoL)
                    graphStoL[nx][ny] = graphStoL[curX][curY] + 1;
                else
                    graphLtoE[nx][ny] = graphLtoE[curX][curY] + 1;

            }
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> sPos,ePos,lPos;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'S')sPos = { i,j };
            else if (maps[i][j] == 'E')ePos = { i,j };
            else if (maps[i][j] == 'L')lPos = { i,j };
        }
    }
    bfs(sPos, true, maps);
    bfs(lPos, false, maps);

    if (graphStoL[lPos.first][lPos.second] == 0 || graphLtoE[ePos.first][ePos.second] == 0)
        return -1;

    return graphStoL[lPos.first][lPos.second] + graphLtoE[ePos.first][ePos.second];
}
