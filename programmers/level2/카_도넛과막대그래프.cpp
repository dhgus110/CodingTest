#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> graph(1'000'001);
int entryGraph[1'000'001]; 
// bool visited[1'000'001];
int maxVertex = 0;

int check(int start){
    int next =start;
    while(!graph[next].empty()){
        if(graph[next].size() == 2) return 3;
        else if(graph[next].size() == 1 && graph[next][0] == start) return 1;
        else next = graph[next][0];
    }
    return 2;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    //init
    for (auto e : edges)
    {   
        graph[e[0]].push_back(e[1]);
        entryGraph[e[1]]++;
        maxVertex = maxVertex < e[0] ? (e[0] < e[1] ? e[1] : e[0]) : maxVertex;
    }

    // entryGraph[0]++;
    // auto index = find(begin(entryGraph),end(entryGraph),0);
    // int arbitraryVertex =distance(entryGraph,index); //임의의 정점

    int arbitraryVertex =0 ;
    for (int i = 1; i <= maxVertex; i++){
        if(graph[i].size()>=2 && entryGraph[i]== 0 ){
            arbitraryVertex = i;
        }
    }
    answer[0]= arbitraryVertex;

    for (auto g : graph[arbitraryVertex]){
        answer[check(g)]++;
    }

    return answer;
}