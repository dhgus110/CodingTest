#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 1e9
using namespace std;

vector<pair<int,int>> Graph[201]; //graph[시작노드] = (도착노드, cost)
int ShareTaxiMinCost[201]; //구간 별 최소 합승 비용

// start지점부터 모든 구간 최소비용 구하기 (모든구간을 합승함)
void getShareTaxiAllCost(int start){
    queue<pair<int,int>> q;
    q.push(make_pair(0,start));
    ShareTaxiMinCost[start] = 0 ;

    while(!q.empty()){
        int cost = q.front().first;
        int node = q.front().second;
        q.pop();

        for(auto n : Graph[node]){
            int nextNode = n.first;
            int nextCost =n.second;
            if(ShareTaxiMinCost[nextNode]> nextCost + cost){
                ShareTaxiMinCost[nextNode] = nextCost + cost;
                q.push(make_pair(ShareTaxiMinCost[nextNode], nextNode));
            }   
        }
    }
}

//start지점에서 goal지점까지 최소비용 구하기
int dijksraPriorityQueue(int start, int goal, int n){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //거리, 현재노드 (가장 짧은 거리부터)
    int dist[n + 1];
    fill_n(dist, n + 1, INF);

    pq.push(make_pair(0,start));
    dist[start] = 0;

    while (!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(node == goal) break;

        for(auto next : Graph[node]){
            int nextNode = next.first;
            int nextCost = next.second;

            if(dist[nextNode]> cost + nextCost){
                dist[nextNode] = cost + nextCost;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }

    return dist[goal];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    //init
    for(auto f: fares){
        Graph[f[0]].push_back(make_pair(f[1], f[2]));
        Graph[f[1]].push_back(make_pair(f[0], f[2]));
    }
    fill_n(ShareTaxiMinCost, 201, INF);

    getShareTaxiAllCost(s);

    int minValue = INF;
    for (int i = 1; i < n + 1; i++){
        int cost = ShareTaxiMinCost[i];
        if(cost == INF) continue;  //길이 이어지지 않음

        int aCost = dijksraPriorityQueue(i,a,n);
        int bCost = dijksraPriorityQueue(i,b,n);
        minValue = min(minValue, cost + aCost + bCost);
    }

    return minValue;
}