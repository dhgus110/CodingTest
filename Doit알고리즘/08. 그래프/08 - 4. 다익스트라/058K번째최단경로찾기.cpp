//백준 1854번
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1e9
#define PII pair<int,int>

using namespace std;

// vector<PII> graph[1001];
int graph[1001][1001];  //[출발][도착]= 가중치
priority_queue<int> d[1001];
bool visit[1001];
int ns, es, k;

void init(int nodeSize, int edgeSize , int kk){
    for (int i = 0; i < edgeSize; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    fill_n(&visit[0], 1001, false);

    ns = nodeSize;
    es = edgeSize;
    k = kk;
}

void dijkstra(int start){
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push(make_pair(0, 1));
    d[1].push(0);
    visit[1] = true;

    while(!pq.empty()){
        int weight = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        //모든 도시 탐색
        for (int next = 1; next <= ns; next++){
            int nextWeight = weight + graph[now][next];
            // 도로가 존재 하면 
            if(graph[now][next] != 0){
                //k보다 적게 저장 되어 있으면 저장
                if(d[next].size() < k){
                    d[next].push(nextWeight);
                    pq.push(make_pair(nextWeight, next));
                }
                //저장된 경로의 수가 k개이면 가장 큰 값과 현재 값 비교해서 저장
                else if(d[next].top() > nextWeight){
                    d[next].pop();
                    d[next].push(nextWeight);
                    pq.push(make_pair(nextWeight, next));
                }
            }
        }
    }
}

void print(){
    for (int i = 1; i <= ns; i++){
        if (d[i].size() == k) cout << d[i].top() << endl;
        else cout << "-1" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodeSize, edgeSize, kk;
    cin >> nodeSize >> edgeSize >> kk;

    init(nodeSize,edgeSize,kk);
    dijkstra(1);

    print();
}