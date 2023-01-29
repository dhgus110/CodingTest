#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

bool visited[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<vector<int>> graph;

int search(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    int res = graph[x][y];

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if (nextX >= graph.size() || nextX < 0 || nextY >= graph[0].size() || nextY < 0) continue;
            if (graph[nextX][nextY] == 0 || visited[nextX][nextY])continue;

            q.push(make_pair(nextX, nextY));
            visited[nextX][nextY] = true;
            res += graph[nextX][nextY];
        }
    }
    return res;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    //init
    for (auto map : maps) {
        vector<int> dummy;
        for (auto m : map) {
            if (m == 'X')dummy.push_back(0);
            else dummy.push_back(m - '0');
        }
        graph.push_back(dummy);
    }
    //search
    for (int x = 0; x < graph.size(); x++) {
        for (int y = 0; y < graph[x].size(); y++) {
            if (graph[x][y] == 0 || visited[x][y])continue;
            answer.push_back(search(x, y));
        }
    }
    if (answer.empty())answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}