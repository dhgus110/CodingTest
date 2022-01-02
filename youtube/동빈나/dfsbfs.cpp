#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

//문제 : 음료수 얼려 먹기 
// int ice[1000][1000];
// bool visit[1000][1000];
bool **visit;
int dx[4],dy[4];
int maxX,maxY;

bool check(int y, int x){
    if(x<0 || x>=maxX || y<0 || y>=maxY) return false;
    else return true;
}

void init(int n, int m, vector<vector<int>> v){
    visit = new bool*[n];
    for(int i = 0 ; i <n ; i++) visit[i] = new bool[m];

    for(int  i = 0; i <n;i++){
        for(int j = 0 ; j<m;j++){
            visit[i][j] = v[i][j];
        }
    }

    dx[0] = 0; dy[0] = 1; 
    dx[1] = 0; dy[1] = -1;
    dx[2] = 1; dy[2] = 0;
    dx[3] = -1; dy[3] = 0;

    maxX = m;  maxY = n;
}
int dfs(){
    stack<pair<int,int>> s;
    int cnt = 0;

    for(int y = 0 ; y <maxY; y++){
        for(int x = 0 ; x<maxX ;x++){
            if(visit[y][x]){
                s.push(make_pair(y, x));
                visit[y][x] = false;
                cnt++; 

                while (!s.empty()) {
                    int curX = s.top().second;
                    int curY = s.top().first;
                    s.pop();
                    for(int i = 0 ; i <4; i++){
                        if (check( curY+ dy[i], curX + dx[i]) && visit[curY + dy[i]][curX + dx[i]]){
                            s.push(make_pair(curY + dy[i], curX+ dx[i]));
                            visit[curY+ dy[i]][curX + dx[i]] = false;
                      
                        }
                    }
                   
                }
            }
        }

    }
    return cnt;
}

int solution1(int n, int m, vector<vector<int>> v){
    init(n,m,v);
    for(int i = 0 ; i <n ; i++){
        for(int j =0; j<m ; j++){
            cout<<visit[i][j];
        }
        cout<<endl;
    }
    return dfs();
}


//문제 :  미로 탈출 BFS
bool **visit2; //방문했으면 트루
int graph[200][200];
int dx2[4],dy2[4];

void init2(int x, int y, vector<vector<int>> v){
    visit2 = new bool*[x];
    for(int i = 0; i <x;i++) visit2[i] = new bool[y];
    
    for(int i=0; i<x ; i++){
        for(int j =0; j<y ; j++){
            if(v[i][j]==0) visit2[i][j] =true; //갈 수 없는 곳 = true
            else visit2[i][j] =false; //갈 수 있는 곳임 = false 
        }
    }

    dx2[0] = 0; dy2[0] = 1; 
    dx2[1] = 0; dy2[1] = -1;
    dx2[2] = 1; dy2[2] = 0;
    dx2[3] = -1; dy2[3] = 0;

    graph[0][0] = 1;
}

int solution2(int x, int y, vector<vector<int>> v){
    init2(x,y,v); 
    queue <pair<int,int>> q;
    q.push({0,0}); //시작위치

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        visit2[curX][curY] =true;
        q.pop();
        for(int i = 0 ; i <4 ;i++){
            int nx = curX + dx2[i];
            int ny = curY + dy2[i];
            if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue; //지도 밖에 벗어나면
            if (!visit2[nx][ny]){ //갈 수 있는 곳이면
                q.push({nx,ny});
                visit2[nx][ny] = true;
                graph[nx][ny] = graph[curX][curY]+1;
                cout<<nx<<" : "<<ny<<" : "<<graph[nx][ny]<<endl;
            }

        }
    }

    for(int i = 0 ; i <x ; i++){
        for(int j = 0 ; j<y ; j++){
            cout<<graph[i][j];
        }cout<<endl;
    }

    return graph[x-1][y-1];

}

int main(){
    cout<< solution1(2,4,{{1,0,1,1},{0,1,0,0}})<<endl;
    cout<<"!!!"<<endl;
    cout<< solution2(4,4,{{1,1,1,1},{1,1,0,1},{1,1,0,1},{1,1,1,1}});
}