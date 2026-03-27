#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 1e9;

vector<pair<int,int>> graph[51]; //graph[a마을].({b 마을, cost})
int d[51]; // 최단거리테이블

void init(const vector<vector<int>>& road)
{
    for(const auto& ro : road)
    {
        graph[ro[0]].emplace_back(ro[1],ro[2]);
        graph[ro[1]].emplace_back(ro[0],ro[2]);
    }
    
    fill(d, d + 51, INF);
}

void run(int start)
{
    priority_queue<pair<int,int>> pq;
    pq.emplace(0, start);
    d[start] = 0 ;
    
    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(d[now] < dist) continue;
        
        for(int i = 0 ; i < graph[now].size(); ++i)
        {
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first])
            {
                d[graph[now][i].first]  = cost;
                pq.emplace(-cost,graph[now][i].first);
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    init(road);
    run(1);
    for(int i = 1; i <51 ; ++i)
        if(d[i] <= K) ++answer;
    
    return answer;
}