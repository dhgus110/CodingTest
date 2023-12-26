#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

bool visited[101][101];
int map[101][101]; //갈 수 없으면 0, 갈 수 있으면 2, 장애물 1, 목표위치 3
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int gx=0,gy=0;//목표위치
int sx=0,sy=0; //스타트 위치

int bfs(){
    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy]=true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0 ; i<4;i++){
            int n = 1;
            if (map[cx + dx[i] * n][cy + dy[i] * n]<2 ) //장애물을 만나거나 벽을 만나면
        }
    }

}

int solution(vector<string> board) {
    int answer = 0;
    int h = board.size()-1;

    //init
    for(auto bo : board){
        int curx = 0;
        for(auto b: bo){
            if(b=='.')
                map[h][curx]=2;
            else if(b=='D')
                map[h][curx]=1;
            else if(b=='G'){
                map[h][curx]=3;
                gx=curx;
                gy=h;
            }else if(b=='R'){
                map[h][curx]=1;
                sx=curx;sy=h;
            }
            curx++;
        }
        h--;
    }

    //목표위치에서 상하좌우에 장애물이 없으면 실패
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        if (gx + dx[i] > 0 || gy + dy[i] > 0)
        {
            if (map[gx + dx[i]][gy + dy[i]] == 1)
                cnt++;
        }
    }
    if(cnt==4)return -1;



    return answer;
}