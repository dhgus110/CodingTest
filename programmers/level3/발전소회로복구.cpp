
/*
전처리1 : 패널~엘레베이터 이동 비용 그래프 BFS
전처리2 : 패널 간 이동 비용 그래프 BFS

1. 엘레베이터 위치 파악 , 각 패널 (층,r,c) 저장
2. BFS(엘레베이터 -> 모든 칸)로 elevDist[r][c] 계산
    → 각 패널 p에 대해: dist(엘레베이터, p) = elevDist[p.r][p.c]
3. 같은 층의 패널 쌍 (p,q)에 대해
    BFS (p → q) 로 직접 이동 비용 계산 후 그래프에 저장
4. 다른 층 이동 비용은 직접 저장하지 않고 나중에 거리 계산할 때 계산:
   cost(p→q) = dist(p, 엘리베이터) + |floor(p) - floor(q)| + dist(엘리베이터, q)

우선순위 다익스트라 + 선행조건

상태 정의:
  d[cur][mask] = cur 패널에 있고, mask에 해당하는 패널들이 활성화된 상태에서의 최소 비용

초기 상태 :
    항상 1번 패널 위치에서 출발
    1번 패널의 선행 조건 충족 여부에 따라 mask = (1<<1) or mask = 0 으로 시작

전이:
    현재 상태 (cur, mask) -> 다음 패널 next 선택시 :
        조건1 : mask에 next가 없어야 함 (미방문)
        조건2 : next의 선행조건이 전부 충족돼야 함.
        비용 : 같은 층 / 다른 층 나눠서 비용 계산
종료 :
    mask = FULL  ->  (1 << (k+1)) -2 이면 최소 비용 반환
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int>> minDistPanels[16]; // minDistPanels[현재 패널] = {다음 패널, cost}  ,[0]= 엘레베이터
vector<vector<int>> panelsCoor[11];       // panelsCoor[해당 층수] = { 패널 번호, r , c };
int panelsFloor[16];                      // 패널이 몇 층에 있는지
pair<int, int> elev;                      // 엘레베이터 좌표
int elevatorMinTable[41][41];             // 엘레베이터 기준 모든 좌표에대한 최소 거리
vector<int> sequenceGraph[16];            // sequenceGraph[b] = { a,a,a,...}
int panelCnt = 0;

constexpr int dx[4] = {0, 0, 1, -1};
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int INF = 1e9;

void init(int h, const vector<string> &grid, const vector<vector<int>> &panels, const vector<vector<int>> &seqs)
{
    int panelIndex = 1;
    for (const auto &p : panels)
    {
        panelsCoor[p[0]].push_back({panelIndex, p[1] - 1, p[2] - 1});
        panelsFloor[panelIndex] = p[0];
        ++panelIndex;
    }

    for (int r = 0; r < grid.size(); ++r)
    {
        bool flag = false;
        for (int c = 0; c < grid[0].size(); ++c)
        {
            if (grid[r][c] == '@')
            {
                flag = true;
                elev = {r, c};
                break;
            }
        }
        if (flag)
            break;
    }

    for (const auto &s : seqs)
        sequenceGraph[s[1]].emplace_back(s[0]);

    panelCnt = (int)panels.size();

    fill(&elevatorMinTable[0][0], &elevatorMinTable[0][0] + 41 * 41, INF);
}

bool checkArea(const vector<string> &grid, int r, int c)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '#')
        return false;
    return true;
}

void ComputeElevatorAndGrid(const vector<string> &grid)
{
    queue<pair<int, int>> q;
    q.emplace(elev.first, elev.second);
    elevatorMinTable[elev.first][elev.second] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!checkArea(grid, nx, ny))
                continue;

            if (elevatorMinTable[nx][ny] > elevatorMinTable[x][y] + 1)
            {
                elevatorMinTable[nx][ny] = elevatorMinTable[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int ComputePanelAndPanel(const vector<string> &grid, int cx, int cy, int gx, int gy)
{
    int d[41][41];
    fill(&d[0][0], &d[0][0] + 41 * 41, INF);
    queue<pair<int, int>> q;
    q.emplace(cx, cy);
    d[cx][cy] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!checkArea(grid, nx, ny))
                continue;

            if (d[nx][ny] > d[x][y] + 1)
            {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return d[gx][gy];
}

void ComputeFloorDistances(int h, const vector<string> &grid)
{
    // 엘레베이터 <-> 모든 좌표 최단 거리
    ComputeElevatorAndGrid(grid);

    for (int i = 1; i <= h; ++i)
    {
        // 해당 층수에 없으면 continue
        if (panelsCoor[i].empty())
            continue;

        for (int j = 0; j < panelsCoor[i].size(); ++j)
        {
            int cidx = panelsCoor[i][j][0];
            int cr = panelsCoor[i][j][1];
            int cc = panelsCoor[i][j][2];
            // 엘레베이터 <-> 패널 최단 거리 저장
            minDistPanels[0].emplace_back(cidx, elevatorMinTable[cr][cc]);
            minDistPanels[cidx].emplace_back(0, elevatorMinTable[cr][cc]);

            // 패널 <-> 패널 최단 거리 저장
            for (int k = j + 1; k < panelsCoor[i].size(); ++k)
            {
                int nidx = panelsCoor[i][k][0];
                int nr = panelsCoor[i][k][1];
                int nc = panelsCoor[i][k][2];
                int cost = ComputePanelAndPanel(grid, cr, cc, nr, nc);
                minDistPanels[cidx].emplace_back(nidx, cost);
                minDistPanels[nidx].emplace_back(cidx, cost);
            }
        }
    }
}

int FindMinimumTraversalCost()
{
    const int FULL = (1 << (panelCnt + 1)) - 2; // 1~panelCnt 사용

    int d[16][1 << 16]; // d[해당 패널][활성화된 패널]
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < (1 << 16); j++)
            d[i][j] = INF;

    // {cost, cur, mask}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    int start = 1;
    int startMask = 1 << 1;
    if (sequenceGraph[1].empty()) //시작 위치에 선행 조건이 없으면
    {
        d[start][startMask] = 0;   
        pq.emplace(0, start, startMask);
    }
    else
    {
        d[start][0] = 0;
        pq.emplace(0, start, 0);
    }

    while (!pq.empty())
    {
        auto [cost, cur, mask] = pq.top();
        pq.pop();

        //cost 초과
        if (d[cur][mask] < cost) 
            continue;

        // 모든 패널 방문 했으면 return
        if (mask == FULL)
            return cost;

        //다음 패널 추가하기
        for (int next = 1; next <= panelCnt; next++)
        {
            // 이미 방문
            if (mask & (1 << next))
                continue;

            // 선행 조건 체크
            bool complete = true;
            for (int panel : sequenceGraph[next])
            {
                if (!(mask & (1 << panel)))
                {
                    complete = false;
                    break;
                }
            }
            if (!complete) continue;


            // 같은 층 이동 가능한지 체크
            bool isSamefloor = false;
            int nextCost = INF;
            for (const auto &panel : minDistPanels[cur])
            {
                if (panel.first == next)
                {
                    nextCost = panel.second;
                    isSamefloor = true;
                    break;
                }
            }

            //엘레베이터 경유할 경우의 cost 
            if (!isSamefloor)
            {
                int toElev = INF;
                int fromElev = INF;
                int moveElev = abs(panelsFloor[cur] - panelsFloor[next]);
                for (auto &p : minDistPanels[cur])
                    if (p.first == 0)
                        toElev = p.second;

                for (auto &p : minDistPanels[next])
                    if (p.first == 0)
                        fromElev = p.second;

                nextCost = toElev + fromElev + moveElev;
            }

            //  기존 활성화된 패널 + next 패널 활성화
            int newMask = mask | (1 << next);

            if (d[next][newMask] > cost + nextCost)
            {
                d[next][newMask] = cost + nextCost;
                pq.emplace(d[next][newMask], next, newMask);
            }
        }
    }

    return -1;
}

void DebugPrintAll(int h, const const vector<string> &grid)
{
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (elevatorMinTable[i][j] == INF)
                cout << "x ";
            else
                cout << elevatorMinTable[i][j] << " ";
        }
        cout << endl;
    }

    cout << "===== Elevator =====\n";
    cout << "Elevator Position: (" << elev.first << ", " << elev.second << ")\n\n";

    cout << "===== Panels by Floor =====\n";
    for (int i = 1; i <= h; i++)
    {
        cout << "Floor " << i << ":\n";
        for (const auto &p : panelsCoor[i])
        {
            cout << "  Panel " << p[0] << " -> (" << p[1] << ", " << p[2] << ")\n";
        }
        cout << "\n";
    }

    cout << "===== minDistPanels =====\n";
    for (int i = 0; i < 16; i++)
    {
        if (minDistPanels[i].empty())
            continue;

        if (i == 0)
            cout << "[Elevator]\n";
        else
            cout << "[Panel " << i << "]\n";

        for (const auto &p : minDistPanels[i])
        {
            if (p.first == 0)
                cout << "  -> Elevator : " << p.second << "\n";
            else
                cout << "  -> Panel " << p.first << " : " << p.second << "\n";
        }
        cout << "\n";
    }

    cout << "===== sequenceGraph =====\n";
    for (int i = 1; i < 16; i++)
    {
        if (sequenceGraph[i].empty())
            continue;

        cout << "Panel " << i << " needs: ";
        for (int x : sequenceGraph[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    cout << "=========================\n";
}

int solution(int h, vector<string> grid, vector<vector<int>> panels, vector<vector<int>> seqs)
{
    init(h, grid, panels, seqs);
    ComputeFloorDistances(h, grid);
    int minCost = FindMinimumTraversalCost();
    DebugPrintAll(h, grid);
    return minCost;
}
