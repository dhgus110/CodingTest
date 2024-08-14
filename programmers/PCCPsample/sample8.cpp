#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 1e9

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N,M;
int minAns = INF;
int graph[1001][1001]; //최단거리테이블, 장애물 : 0

bool safeArea(int y, int x){
    if (y >= 1 && y <= N && x >= 1 && x <= M && graph[y][x] != 0)
        return true;
    return false;
}

// 재귀 풀이 시간초과
void run(int y, int x, int moveCnt, bool jump ,vector<vector<bool>> visit){
    if (y == N && x == M){
        minAns = min(minAns, moveCnt);
        return;
    }
    if(visit[y][x]) return;
    if(minAns <= moveCnt) return;

    for(int i = 0 ; i<4; i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        int jumpY = y + dy[i] * 2;
        int jumpX = x + dx[i] * 2;
        visit[y][x] = true;
        //일반 이동
        if(safeArea(nextY,nextX)){
            run(nextY, nextX, moveCnt + 1, jump, visit);
        }

        //이중 점프
        if (!jump && safeArea(jumpY, jumpX)){
            run(jumpY, jumpX, moveCnt + 1, true, visit);
        }
    }
}

// BFS 풀이
int d[1001][1001][2];
int minRet = INF;

struct Point{
    int col; //n
    int row; //m
    int jump; 
};

void move1(queue<Point>& q, int dist){
    Point cur = q.front();
    for(int i =0 ;i<4;i++){
        int nc = cur.col + dx[i];
        int nr = cur.row + dy[i];
        int nj = cur.jump;

        if(!safeArea(nc,nr)) continue;
        if(d[nc][nr][nj]) continue;

        q.push({nc,nr,nj});
        d[nc][nr][nj] = dist + 1;
    }
}
void move2(queue<Point>& q, int dist){
    Point cur = q.front();
    for(int i =0 ;i<4;i++){
        int nc = cur.col + dx[i] * 2;
        int nr = cur.row + dy[i] * 2;
        int nj = cur.jump + 1;

        if (!safeArea(nc, nr))
            continue;
        if (nj > 1 || d[nc][nr][nj])
            continue;

        q.push({nc, nr, nj});
        d[nc][nr][nj] = dist + 1;
    }
}

void run2(){
    queue<Point> q;
    q.push({1,1,0});
    d[1][1][0]=0;
    d[1][1][1]=0;

    while(!q.empty()){
        Point cur = q.front();
        int dist = d[cur.col][cur.row][cur.jump];
        if (cur.col == N && cur.row == M){
            minRet = min(minRet, dist);
        }
        else if (minRet > dist){
            move1(q, dist);
            move2(q, dist);
        }

        q.pop();
    }

}

int solution(int n, int m, vector<vector<int>> hole) {
    //init
    vector<vector<bool>> visit(n + 1, vector<bool>(m + 1, false));
    N = n;
    M = m;
    fill_n(&graph[0][0],1001*1001,INF);
    for(auto h : hole){
        graph[h[0]][h[1]] = 0;
    }

    //run
    // run(1,1,0,false,visit);
    run2();

    // if (minAns == INF)
    //     minAns = -1;
    if (minRet == INF)
        minRet = -1;

    return minRet;
}