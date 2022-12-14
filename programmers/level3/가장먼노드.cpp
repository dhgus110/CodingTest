#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 1e9

using namespace std;

vector<pair<int,int>> graph[20'001]; //그래프 
int d[20'001]; //최단 거리
int maxCost;
vector<int> maxNode;

void dijkstraPriorityQueue(int start)
{
    priority_queue<pair<int, int>> pq; //거리, 노드정보
    pq.push({0, start});
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(maxCost<dist){
            maxCost = dist;
            maxNode.clear();
            maxNode.push_back(now);
        }else if(maxCost == dist){
            maxNode.push_back(now);
        }

        if (d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = dist + graph[now][i].second;
            if (cost < d[graph[now][i].first])
            {
                d[graph[now][i].first] =cost;
                pq.push({-cost,graph[now][i].first});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    //그래프 그리기
    for(auto e :edge){
        graph[e[0]].push_back({e[1],1}); // graph[시작노드].push({도착노드, 간선거리})
        graph[e[1]].push_back({e[0],1});
    }

    //초기화
    fill_n(d,20'001,INF);

    //알고리즘 실행 
    dijkstraPriorityQueue(1);
    answer = maxNode.size();
    
    return answer;
}