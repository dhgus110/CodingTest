#include<vector>
#include<queue>

using namespace std;

bool visited[100][100] = {false}; //방문했는지
int dis[100][100] = { 0 }; //거리 계산
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    int m = maps.size();
    int n = maps[0].size();

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    dis[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)continue; //범위를 벗어났을 경우
            if (visited[nextX][nextY]) continue; //이미 갔던 곳
            if (maps[nextX][nextY] == 0)continue; //갈 수 없는 곳

            visited[nextX][nextY] = true;
            q.push(make_pair(nextX, nextY));
            dis[nextX][nextY] = dis[x][y] + 1;
        }
    }
    if (!dis[m - 1][n - 1]) answer = -1;
    else answer = dis[m - 1][n - 1];

    return answer;
}