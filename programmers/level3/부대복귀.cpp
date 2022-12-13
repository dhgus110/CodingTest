#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 1e9

using namespace std;

//vector<vector<int>> ROADS(100'000);
vector<pair<int,int>> ROADS[100'001]; //노드간 간선 정보

int d[100'001]; //최단 거리 
//bool visited[100'001]; //방문 처리

void dijkstraPriorityQueue(int start)
{
    priority_queue<pair<int,int>> pq; //거리 , 노드 정보
    pq.push({0,start});
    d[start]=0;

    while (!pq.empty())
    {
        int dist = -pq.top().first; //현재 노드까지의 거리, 최소힙 사용(-)부호
        int now = pq.top().second;  //현재 노드
        pq.pop();
        if (d[now] < dist) continue; // 현재 노드의 최단 거리를 갱신할 수 없다면

        for (int i = 0; i < ROADS[now].size(); i++)
        {
            int cost = dist + ROADS[now][i].second;
            //현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (d[ROADS[now][i].first] > cost)
            {
                d[ROADS[now][i].first] = cost;
                pq.push({-cost, ROADS[now][i].first});
            }
        }
    }

}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    //초기화
    for(auto v : roads){
        ROADS[v[0]].push_back({v[1], 1}); //지역끼리 왕복 가능, ROADS[시작노드].({도착노드, 간선})
        ROADS[v[1]].push_back({v[0], 1});
    }
    fill_n(d, 100'001, INF);

    //최단거리그래프 만들기
    dijkstraPriorityQueue(destination);

    for(auto s :sources){
        if(d[s]==INF) answer.push_back(-1);
        else answer.push_back(d[s]);
    }
    
    return answer;
}
