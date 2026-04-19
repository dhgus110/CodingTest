#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

constexpr int INF = 1e9;
int dx[4] = {0, 0, 1, -1};// 0  1   2 3
int dy[4] = {1, -1, 0, 0};// 위 아래 오 왼
int cost[25][25];
bool visited[25][25];
vector<int> dir[25][25];
int maxN;

bool checkArea(int x, int y)
{
    return x >= 0 && y >= 0 && x < maxN && y < maxN;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    fill(&cost[0][0], &cost[0][0] + 25 * 25, INF);
    // fill(&visited[0][0], &visited[0][0]+ 25 * 25 , false);
    maxN = board.size();

    queue<pair<int, int>> bfs;
    bfs.emplace(maxN-1, maxN-1);
    cost[maxN-1][maxN-1] = 0;
    dir[maxN-1][maxN-1].emplace_back(-1);

    while (!bfs.empty())
    {
        auto cur = bfs.front();
        bfs.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nextX = dx[i] + cur.first;
            int nextY = dy[i] + cur.second;
            if (!checkArea(nextX, nextY) || board[nextX][nextY] == 1)
                continue;

            int nextCost;
            bool straight = false;
            for(int d : dir[cur.first][cur.second])
            {
                if( d == -1 || d == i )
                {
                    straight = true;
                    break;
                }
            }
            
            nextCost = straight ? cost[cur.first][cur.second] + 100 :cost[cur.first][cur.second] + 600;

            if (cost[nextX][nextY] < nextCost)
                continue;
            else if (cost[nextX][nextY] == nextCost)
            {
                dir[nextX][nextY].emplace_back(i);
                continue;
            }
            else 
                dir[nextX][nextY].clear();

            bfs.emplace(nextX, nextY);
            dir[nextX][nextY].emplace_back(i);
            cost[nextX][nextY] = nextCost;
        }
    }

    return cost[0][0];
}