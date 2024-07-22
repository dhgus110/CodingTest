#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxValue = -1;
vector<vector<int>> graph;

void dfs(int cur, int curK, int sum, vector<int> v){
    if (v[cur] != 0 || curK <= 0 || sum == v.size() || graph[cur][0]> curK){
        if( curK < 0)
            maxValue = max(maxValue, sum - 1);
        else
            maxValue = max(maxValue, sum);
        return;
    }

    v[cur]++;
    sum++;
    curK -= graph[cur][1];

    for (int i = 0 ; i < v.size() ; i++){
        dfs(i, curK, sum, v);
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    graph = dungeons;
    vector<int> v(dungeons.size(), 0);

    for(int i = 0 ; i<dungeons.size(); i++){
        dfs(i, k, 0, v);
    }

    return maxValue;
}