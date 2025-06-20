#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define INF     1e9

using namespace std;

bool visited[101][101] = {};
int graph[101][101] = {};
int minDistance[101][101] = {};

int n{}, m{};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init()
{
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> m;
    string temp = {};
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        for (int j = 1; j <= m; ++j)
        {
            graph[i][j] = temp[j - 1] - '0';
        }
    }

    fill(&minDistance[0][0], &minDistance[0][0] + 101 * 101, INF);
}

void dijkstraPriorityQueue(int _startX, int _startY)
{
    priority_queue < pair<int, pair<int, int>>> pq;

    pq.push({-1, {_startY, _startX}}); // 최소힙 이용
    visited[_startY][_startX] = true;
    minDistance[_startY][_startX] = 1;

    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int curY = pq.top().second.first;
        int curX = pq.top().second.second;
        pq.pop();

        if(minDistance[curY][curX] < dist) continue; //이미 처리된 지점

        for (int i = 0; i < 4; ++i)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (nextX < 0 || nextY < 0 || nextX > m || nextY > n || graph[nextY][nextX] == 0)
                continue;

            int cost = dist + graph[nextY][nextX];
            
            //현재 지점이 더 짧은 거리라면 
            if( cost < minDistance[nextY][nextX])
            {
                minDistance[nextY][nextX] = cost;
                pq.push({-cost, {nextY, nextX}});
            }
        }

    }
}

int main()
{
    init();
    dijkstraPriorityQueue(1, 1);

    cout<<minDistance[n][m];

}