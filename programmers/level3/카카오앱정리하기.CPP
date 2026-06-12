/*
이동 못 시키는 commands는 없음.

struct APP
{
    int dir, move;
    int l ,u ,r ,d ;
}
  
현재 command id (dir,move 저장)-> queue에 저장
    반복
        q.top -> 이동 시키고
                    격자라면 반대편으로 이동.
        q.top에 영향가는 id(dir,move 저장) -> queue에 저장
            
        
주의점 
    a를 밀었더니
    b가 밀리고
    또 다시 a가 밀리는 현상
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0}; // 0은 오른쪽, 1는 아래쪽, 2은 왼쪽, 3는 위쪽
int dy[4] = {0, 1, 0, -1};
int h,w;

struct APP
{
    //좌상단, 우하단 좌표위치     // u < d
    int l, u, r, d;  
    int width, height;
    bool edgeWarp = false;
    int warpingDist;

    // mdir 방향으로 dist칸 이동. 격자 밖으로 나가면 앱 전체가 반대편 끝으로 (쪼개지지 않음)
    void shift(int mdir, int dist)
    {
        l += dx[mdir] * dist;  r += dx[mdir] * dist;
        u += dy[mdir] * dist;  d += dy[mdir] * dist;
        edgeWarp = false;
        if      (l < 0)  {edgeWarp = true;  warpingDist = 1;}  // 왼쪽 이탈 → 오른쪽 끝
        else if (r >= w) {edgeWarp = true;  warpingDist = 1;}  // 오른쪽 이탈 → 왼쪽 끝
        if      (u < 0)  {edgeWarp = true;  warpingDist = 1;}  // 위 이탈 → 아래 끝
        else if (d >= h) {edgeWarp = true;  warpingDist = 1;}  // 아래 이탈 → 위 끝
    }

    bool warping(int mdir)
    {
        if(mdir == 0) 
        {
            if(warpingDist == width) return false; // 워프 끝
            if(warpingDist == 1) l = r = 0;
            else ++r;

        }
        if(mdir == 2)
        {
            if(warpingDist == width) return false; // 워프 끝
            if(warpingDist == 1) l = r = w - 1;
            else --l;
        }
        if(mdir == 1) 
        {
            if(warpingDist == height)return false; // 워프 끝
            if(warpingDist == 1) u = d = 0; 
            else ++d;
        }
        if(mdir == 3)
        {
            if(warpingDist == height)return false; // 워프 끝
            if(warpingDist == 1)  u = d = h - 1;
            else --u;
        }

        ++warpingDist;
        return true;
    }

    // a = 방금 이동한 미는 앱(방향 mdir). 겹치면 "밀려나야 할 칸 수" 반환 (0 = 안 겹침)
    int pushDist(const APP& a, int mdir) const
    {
        if(l > a.r || r < a.l || u > a.d || d < a.u) return 0; // 사각형 안 겹침
        //if (!(a.l <= r && l <= a.r && a.u <= d && u <= a.d)) return 0;  // 사각형 안 겹침
        if (mdir == 0) return a.r - l + 1;   // 오른쪽
        if (mdir == 2) return r - a.l + 1;   // 왼쪽
        if (mdir == 1) return a.d - u + 1;   // 아래
        return d - a.u + 1;                  // 위                
    }
};

vector<APP> apps;
unordered_set<int> allApp;

void init(const vector<vector<int>>& board)
{
    h = board.size();
    w = board[0].size();

    apps.resize(101);

    for(int he = 0 ; he < h ; ++he)
    {
        for( int wi = 0 ; wi < w ; ++wi)
        {
            if(board[he][wi] == 0 || allApp.find(board[he][wi]) != allApp.end()) continue;

            allApp.emplace(board[he][wi]);

            APP app;
            app.l = wi;
            app.u = he;
            for(int tempH = he ; tempH < h ; ++tempH)
            {
                if(board[tempH][wi] == board[he][wi]) app.d = tempH;
            }
            for(int tempW = wi ; tempW < w ; ++tempW)
            {
                if(board[he][tempW] == board[he][wi]) app.r = tempW;
            }

            app.width = app.r - app.l + 1;
            app.height = app.d - app.u + 1;
            apps[board[he][wi]]=app;
        }
    }

    // for(auto it = allApp.begin(); it != allApp.end(); ++it)
    // {
    //     cout<< *it<< " ";
    // }
    // // for(const auto& a : apps)
    // {
    //     cout<<" : ["<< a.l <<","<<a.u<<"], ["<<a.r<<","<<a.d<<"]"<<endl;
    // }
}

vector<vector<int>> solution(vector<vector<int>> board, vector<vector<int>> commands) {
    init(board);
    vector<vector<int>> answer(h, vector<int>(w, 0));

    for(const auto& c : commands)
    {
        int id = c[0];
        int dir = c[1] - 1;

        queue<int> q;
        apps[id].shift(dir, 1);       // 명령받은 앱: 한 칸(밖이면 반대편 끝)
        q.emplace(id);

        // cout<<"--------------------"<<endl;
        // cout <<"현재 : "<<id<<"  -  "<<c[1]<<"방향으로 "<<1<<"칸 이동"<<" 위치 [l,u]=["<<apps[id].l<<","<<apps[id].u<<"]"<<" [r,d]=["<<apps[id].r<<","<<apps[id].d<<"]"<<endl;

        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            //cout <<"현재 : "<<cur<<endl;
            //cur가 새 위치에서 겹치는(밀어내는) 앱 찾아서 전부 밀기

            if(apps[cur].edgeWarp)
            {
                unordered_set<int> pushSet;
                while(apps[cur].warping(dir))
                {
                    for (int next : allApp)
                    {
                        if (next == cur) continue;
                        int dist = apps[next].pushDist(apps[cur], dir);
                        if (dist == 0) continue; // 안 겹치면 pass

                        apps[next].shift(dir, dist); // 겹친 만큼 밀려남
                        pushSet.emplace(next);
                        // cout<<"겹침 :"<< next<<" 이동 :"<<dist<<" 위치 [l,u]=["<<apps[next].l<<","<<apps[next].u<<"]"<<" [r,d]=["<<apps[next].r<<","<<apps[next].d<<"]"<<endl;
                    }
                }

                for(int s : pushSet) q.emplace(s);
            }
            else
            {
                for (int next : allApp)
                {
                    if (next == cur)
                        continue;
                    int dist = apps[next].pushDist(apps[cur], dir);
                    if (dist == 0)
                        continue; // 안 겹치면 pass

                    apps[next].shift(dir, dist); // 겹친 만큼 밀려남
                    q.emplace(next);
                    // cout<<"겹침 :"<< next<<" 이동 :"<<dist<<" 위치 [l,u]=["<<apps[next].l<<","<<apps[next].u<<"]"<<" [r,d]=["<<apps[next].r<<","<<apps[next].d<<"]"<<endl;
                }
            }
        }
    }

    // 그리기
    for (auto it = allApp.begin(); it != allApp.end(); ++it)
    {
        int cur = * it;

        for(int y = apps[cur].u ; y <= apps[cur].d ; ++y)
            for(int x = apps[cur].l ; x <= apps[cur].r ; ++x)
                answer[y][x] = cur; 
    }

    return answer;
}

// [5, 5, 5, 5, 6, 6]
// [5, 5, 5, 5, 6, 6],
// [5, 5, 5, 5, 12, 13],
// [5, 5, 5, 5, 3, 3],
// [10, 11, 2, 2, 3, 3],
// [1, 1, 2, 2, 14, 15],
// [1, 1, 4, 4, 4, 4],
// [8, 9, 4, 4, 4, 4],
// [7, 7, 4, 4, 4, 4],
// [7, 7, 4, 4, 4, 4]

// [6,6,5,5,5,5],
// [6,6,5,5,5,5],
// [12,13,5,5,5,5],
// [3,3,5,5,5,5],
// [3,3,2,2,10,11],
// [1,1,2,2,14,15],
// [1,1,4,4,4,4],
// [9,8,4,4,4,4],
// [7,7,4,4,4,4],
// [7,7,4,4,4,4]

// [5,5,5,5,6,6],
// [5,5,5,5,6,6],
// [5,5,5,5,12,13],
// [5,5,5,5,3,3],
// [10,11,2,2,3,3],
// [1,1,2,2,14,15],
// [1,1,4,4,4,4],
// [8,9,4,4,4,4],
// [7,7,4,4,4,4],
// [7,7,4,4,4,4]