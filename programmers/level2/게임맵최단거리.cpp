#include<vector>
#include<queue>
using namespace std;

bool visited[100][100] ={false};
int cost[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int w,h;

bool limitArea(int x,int y){
    if (x >= 0 && y >= 0 && x < h && y < w)
        return true;
    return false;
}

// 0:벽 1:길 nm:적
int solution(vector<vector<int> > maps)
{
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0]= true;
    cost[0][0]=1;
    w=maps[0].size(); h=maps.size();
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i =0; i<4;i++){
            int mx = x+dx[i];
            int my = y+dy[i];
            if (!visited[mx][my] && limitArea(mx, my) && maps[mx][my]){
                q.push(make_pair(mx, my));
                visited[mx][my]=true;
                cost[mx][my] = cost[x][y] + 1;
            }
        }
    }

    return cost[h - 1][w - 1] == 0 ? -1 : cost[h - 1][w - 1];
}



// bool visited[100][100] = {false}; //�湮�ߴ���
// int dis[100][100] = { 0 }; //�Ÿ� ���
// int dx[4] = { 1,0,-1,0 };
// int dy[4] = { 0,1,0,-1 };

// int solution(vector<vector<int>> maps)
// {
//     int answer = 0;

//     int m = maps.size();
//     int n = maps[0].size();

//     queue<pair<int, int>> q;
//     q.push(make_pair(0, 0));
//     visited[0][0] = true;
//     dis[0][0] = 1;

//     while (!q.empty()) {
//         int x = q.front().first;
//         int y = q.front().second;
//         q.pop();

//         for (int i = 0; i < 4; i++) {
//             int nextX = x + dx[i];
//             int nextY = y + dy[i];

//             if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)continue; //������ ����� ���
//             if (visited[nextX][nextY]) continue; //�̹� ���� ��
//             if (maps[nextX][nextY] == 0)continue; //�� �� ���� ��

//             visited[nextX][nextY] = true;
//             q.push(make_pair(nextX, nextY));
//             dis[nextX][nextY] = dis[x][y] + 1;
//         }
//     }
//     if (!dis[m - 1][n - 1]) answer = -1;
//     else answer = dis[m - 1][n - 1];

//     return answer;
// }