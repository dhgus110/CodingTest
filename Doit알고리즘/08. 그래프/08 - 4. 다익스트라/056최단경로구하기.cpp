//백준 1753번
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int,int>> graph[20'001]; //[출발]= {가중치,도착},{,}
bool visit[20'001];
int d[20'001];


void init(int edgeSize){
    for (int i = 0; i < edgeSize; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
    }
    fill_n(&visit[0], 20'001, false);
    fill_n(&d[0], 20'001, INF);
}

void dijkstra(int start){
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    visit[start] = true;
    d[start] = 0;

    while(!pq.empty()){
        int weight = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for(auto next : graph[now]){
            int nextWeight = next.first;
            int nextNode = next.second;
            if(visit[nextNode]) continue;

            pq.push(make_pair(nextWeight, nextNode));
            d[nextNode] = min(d[nextNode], weight + nextWeight);
            visit[nextNode] = true;
        }
    }
}

void print(int nodeSize){
    for (int i = 1; i <= nodeSize; i++){
        if (d[i] == INF)
            cout << "INF" << endl;
        else
            cout << d[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodeSize, edgeSize, start;
    cin >> nodeSize >> edgeSize >> start;

    init(edgeSize);
    dijkstra(start);

    print(nodeSize);

}