//백준 1197번
//간선이 많으므로 프림알고리즘 사용
//---------------------잘 못 품 ------ 다시 풀어야 함 ..
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #define PII pair<int,int>
// #define INF 1e9

// using namespace std;

// int nodeSize, edgeSize;
// vector<PII> ad[10'001]; //ad[출발] = {비용,도착};
// priority_queue<PII,vector<PII>,greater<PII>> dist; //최소비용
// // int dist[10'001]; //최소 비용
// bool visit[10'001];

// void init(){
//     cin >> nodeSize >> edgeSize;

//     for (int i = 0; i < edgeSize; i++){
//         int start, end, weight;
//         cin >> start >> end >> weight;
//         ad[start].push_back(make_pair(end, weight));
//         ad[end].push_back(make_pair(start, weight));
//     }
    
//     fill_n(&visit[0],10'001,false);
// }

// void add_edge(int n){
//     for (auto e : ad[n]){
//         dist.push(e);
//     }
// }

// long long prim(){
//     long long answer =0;

//     dist.push(make_pair(0,1));
//     for (int i = 1; i <= nodeSize; i++){
//         int now = -1, minDist = INF;
//         while(!dist.empty()){
//             now = dist.top().second;
//             if(!visit[now]){
//                 minDist = dist.top().first;
//                 break;
//             }
//             dist.pop();
//         }
//         if (minDist == INF) return -1; //연결 그래프가 아님 
//         answer += minDist;
//         visit[now] =true;
//         add_edge(now);
//     }

//     return answer;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL); 

//     init();
//     cout << prim() << endl;
// }