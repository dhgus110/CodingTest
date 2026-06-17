#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 방향: 1오른, 2아래, 3왼, 4위
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
int H, W;

struct APP
{
    int l, u, width, height;   // 좌상단(l,u) + 크기. 항상 격자 안에 온전히(분할 없이) 존재
};

vector<APP> apps;          // apps[id]
unordered_set<int> ids;    // 존재하는 앱 id

void init(const vector<vector<int>>& board)
{
    H = board.size();
    W = board[0].size();
    apps.assign(101, {});
    ids.clear();
 
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
        {
            int id = board[i][j];
            if (id == 0 || ids.count(id)) continue;
            ids.insert(id);

            int d = i, r = j;
            while (d + 1 < H && board[d + 1][j] == id) ++d;
            while (r + 1 < W && board[i][r + 1] == id) ++r;

            apps[id] = { j, i, r - j + 1, d - i + 1 };
        }
}

// dir로 한 칸 이동. 격자 밖으로 나가면 앱 전체가 반대편 끝에 붙는다(teleport, 분할 없음)
void move1(APP& a, int dir)
{
    if (dir == 1) { a.l++; if (a.l + a.width  > W) a.l = 0; }          // 오른쪽
    if (dir == 3) { a.l--; if (a.l < 0)            a.l = W - a.width;  } // 왼쪽
    if (dir == 2) { a.u++; if (a.u + a.height > H) a.u = 0; }          // 아래
    if (dir == 4) { a.u--; if (a.u < 0)            a.u = H - a.height; } // 위
}

// 두 사각형이 겹치는가 (둘 다 분할 없는 온전한 사각형)
bool overlap(const APP& a, const APP& b)
{
    return a.l <= b.l + b.width  - 1 && b.l <= a.l + a.width  - 1 &&
           a.u <= b.u + b.height - 1 && b.u <= a.u + a.height - 1;
}

// Y가 cur(미는 앱)에서 벗어나려면 dir로 몇 칸 가야 하나 (= 겹친 칸 수)
int clearDist(const APP& cur, const APP& Y, int dir)
{
    if (dir == 1) return (cur.l + cur.width  - 1) - Y.l + 1;             // 오른쪽
    if (dir == 3) return (Y.l + Y.width  - 1) - cur.l + 1;              // 왼쪽
    if (dir == 2) return (cur.u + cur.height - 1) - Y.u + 1;            // 아래
    return            (Y.u + Y.height - 1) - cur.u + 1;                // 위
}

void buildGrid(vector<vector<int>>& grid)
{
    for (auto& row : grid) fill(row.begin(), row.end(), 0);
    for (int id : ids)
        for (int i = 0; i < apps[id].height; ++i)
            for (int j = 0; j < apps[id].width; ++j)
                grid[apps[id].u + i][apps[id].l + j] = id;
}

void run(const vector<vector<int>>& commands)
{
    for (const auto& cmd : commands)
    {
        int id = cmd[0], dir = cmd[1];

        // 빈칸이 하나도 없으면 밀 공간이 없어 아무것도 못 움직임
        int filled = 0;
        for (int x : ids) filled += apps[x].width * apps[x].height;
        if (filled >= H * W) continue;

        vector<APP> saved = apps;

        move1(apps[id], dir);                  // 명령 앱 한 칸 이동
        queue<int> q; q.push(id);
        bool blocked = false;
        long iter = 0;

        // 밀린 앱이 또 다른 앱과 겹치면 그만큼 또 밀어내는 연쇄
        while (!q.empty() && !blocked)
        {
            int cur = q.front(); q.pop();
            for (int Y : ids)
            {
                if (Y == cur || !overlap(apps[cur], apps[Y])) continue;
                int d = clearDist(apps[cur], apps[Y], dir);
                for (int i = 0; i < d; ++i) move1(apps[Y], dir);   // 겹친 만큼(teleport 포함) 밀림
                q.push(Y);
            }
            if (++iter > 100000) blocked = true;   // 빈칸 없이 무한히 도는(막힌) 경우 방어
        }

        // 끝났는데도 겹침이 남으면 해소 불가 → 명령 취소
        if (!blocked)
            for (int a : ids) { for (int b : ids) if (a < b && overlap(apps[a], apps[b])) { blocked = true; break; } if (blocked) break; }

        if (blocked) apps = saved;
    }
}

vector<vector<int>> solution(vector<vector<int>> board, vector<vector<int>> commands)
{
    init(board);
    run(commands);

    vector<vector<int>> answer(H, vector<int>(W, 0));
    buildGrid(answer);
    return answer;
}
