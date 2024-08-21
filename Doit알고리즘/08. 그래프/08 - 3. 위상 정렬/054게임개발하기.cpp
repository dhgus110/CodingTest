//백준 1516번
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
int inDegree[501]; //진입차수
int buildingTime[501]; //각 건물마다의 건설 시간
int result[501]; // 자기걸 짓기 위한 먼저 지어야하는 건물들의 건설 시간

void init(int size){
    graph.resize(size + 1);

    for (int i = 1; i <= size; i++){
        cin>> buildingTime[i];

        while(true){
            int a;
            cin >> a;
            if(a == -1 ) break;

            graph[i].push_back(a);
            inDegree[a]++;
        }
    }
}

void run(int size){
    queue<int> q; //위상 정렬 실행 
    for (int i = 1; i <= size; i++){
        if (inDegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(auto next : graph[now]){
            inDegree[next]--;
            result[next] = max(result[next], result[now] + buildingTime[now]);
            if (inDegree[next] == 0)
                q.push(next);
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size ;
    cin >> size;

    init(size);
    run(size);

    for (int i = 1; i <= size; i++){
        cout << result[i] + buildingTime[i] << endl;
    }
}