#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#define PII pair<int,int>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int xSize, ySize;
PII redPos, bluePos, redGoal, blueGoal;
vector<vector<int>> maze;

void init(vector<vector<int>>const& _maze){
    xSize = _maze[0].size();
    ySize = _maze.size();

    for (int y = 0; y < ySize; y++){
        for (int x = 0; x < xSize; x++){
            if(_maze[y][x] == 1) redPos = make_pair(y,x);
            else if(_maze[y][x] == 2) bluePos = make_pair(y,x);
            else if(_maze[y][x] == 3) redGoal = make_pair(y,x);
            else if(_maze[y][x] == 4) blueGoal = make_pair(y,x);
        }
    }
    maze = _maze;
}

//벽이랑 판 밖으로 움직일 수 없다.
bool safeArea(PII a){
    return a.second >= 0 && a.second < xSize && a.first >= 0 && a.first < ySize 
        && maze[a.first][a.second] != 5 ;
}

PII customPlus(PII a , int x, int y){
    return make_pair(a.first + y, a.second + x);
}

//1. 방문했던 칸으로 다시 못감.
//2. 도착한 수레는 움직이지 않는다.
//3. 빨간 수레와 파란 수레는 같은 칸에 위치할 수 없다.
//4. 서로 위치 변경 불가
int run(){
    vector<vector<int>> visitedRed(maze.size(), vector<int>(maze[0].size(), 0));
    vector<vector<int>> visitedBlue(maze.size(), vector<int>(maze[0].size(), 0));
    queue<vector<PII>> q; //수레들 위치 정보 {{redpos,bluepos}}
    queue<vector<vector<vector<int>>>> visitedStore;

    q.push({redPos,bluePos});
    visitedRed[redPos.first][redPos.second]=1;
    visitedBlue[bluePos.first][bluePos.second] =1;
    visitedStore.push({visitedRed,visitedBlue});

    vector<vector<int>> dummyRed,dummyBlue; // 방문처리를 위한 더미
    bool arriveRed = false, arriveBlue = false;

    while(!q.empty() && !visitedStore.empty()){

        arriveRed = false, arriveBlue = false;

        PII curRed = q.front()[0];
        PII curBlue = q.front()[1];
        dummyRed = visitedStore.front()[0];
        dummyBlue = visitedStore.front()[1];
        q.pop();
        visitedStore.pop();

        if(curRed == redGoal) arriveRed = true;
        if(curBlue == blueGoal) arriveBlue = true;

        //두 수레 다 도착
        if(arriveRed && arriveBlue) break;
        //두 수레 다 도착하지 못함  
        else if (!arriveRed && !arriveBlue ){
            for(int i = 0 ; i <4 ; i++){
                PII nextRed = customPlus(curRed, dx[i], dy[i]);
                if (!safeArea(nextRed))continue;
                if (dummyRed[nextRed.first][nextRed.second] != 0) continue;
                
                for(int j = 0 ; j <4 ; j++){
                    PII nextBlue = customPlus(curBlue,dx[j],dy[j]);
                    if (!safeArea(nextBlue)) continue;
                    if (dummyBlue[nextBlue.first][nextBlue.second] != 0) continue;
                    if (nextRed == nextBlue) continue;
                    if (nextRed == curBlue && nextBlue == curRed) continue;

                    q.push({nextRed,nextBlue});
                    dummyRed[nextRed.first][nextRed.second]= dummyRed[curRed.first][curRed.second] + 1;
                    dummyBlue[nextBlue.first][nextBlue.second]= dummyBlue[curBlue.first][curBlue.second] + 1;
                    visitedStore.push({dummyRed,dummyBlue});
                    dummyRed[nextRed.first][nextRed.second] =0;
                    dummyBlue[nextBlue.first][nextBlue.second]=0;
                }

            }
        }
        //파란 수레만 도착
        else if( !arriveRed){
             for(int i =0 ; i < 4 ; ++i){
                PII nextRed = customPlus(curRed,dx[i],dy[i]);

                if(!safeArea(nextRed)) continue;
                if(dummyRed[nextRed.first][nextRed.second] != 0) continue;
                if(nextRed == curBlue) continue;

                q.push({nextRed, curBlue});
                dummyRed[nextRed.first][nextRed.second]= dummyRed[curRed.first][curRed.second] + 1;
                visitedStore.push({dummyRed,dummyBlue});
                dummyRed[nextRed.first][nextRed.second] = 0;
             }
        }
        //빨간 수레만 도착
        else if (!arriveBlue){
            for (int i = 0; i < 4; ++i){
                PII nextBlue = customPlus(curBlue, dx[i], dy[i]);

                if (!safeArea(nextBlue))continue;
                if (dummyBlue[nextBlue.first][nextBlue.second] != 0) continue;
                if (nextBlue == curRed) continue;

                q.push({curRed, nextBlue});
                dummyBlue[nextBlue.first][nextBlue.second] = dummyBlue[curBlue.first][curBlue.second] + 1;
                visitedStore.push({dummyRed, dummyBlue});
                dummyBlue[nextBlue.first][nextBlue.second] = 0;
            }
        }
    }
    if (arriveRed && arriveBlue)
        return max(dummyRed[redGoal.first][redGoal.second], dummyBlue[blueGoal.first][blueGoal.second]) - 1;
    else
        return 0;
    
}

int solution(vector<vector<int>> _maze) {
    init(_maze);
    return run();
}