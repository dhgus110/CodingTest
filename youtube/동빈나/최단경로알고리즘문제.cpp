#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1e9 //무한의 값을 10억으로 설정

using namespace std;

//문제 : 전보
//메세지를 받는 도시의 총 개수, 총 걸리는 시간 구하기
int n1, m1, start1;
vector<pair<int,int>> graph1[30001]; //노드간의 간선 정보
// bool visited1[100001]; //방문했는지?
int d1[30001]; //최단거리테이블 

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    d1[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d1[now]<dist) continue; //현재 저장되어 있는 최단 거리보다 dist가 더 크다면 무시
        for(int i = 0 ; i<=graph1[now].size() ; i++ ){
            int cost = dist + graph1[now][i].second;
            if (cost < d1[graph1[now][i].first]){
                d1[graph1[now][i].first]=cost;
                pq.push({-cost, graph1[now][i].first});
            }
        }
    }
}

vector<int> solution1(int n, int m, int start, vector<vector<int>> g){
    vector<int> answer;
    //초기화
    n1 = n;
    m1 = m;
    start1 = start;
    fill_n(d1,30001,INF);
    for(int i = 0; i<m; i++){
        graph1[g[i][0]].push_back({g[i][1], g[i][2]}); //graph1[시작노드].({도착노드, 간선})
    }

    dijkstra(start1);

    int big=0;
    int cnt =0;
    for(int i = 0 ; i< n;i++){
        if(d1[i] != INF){
            cnt++;
            if(d1[i]>big) big =d1[i];
        }
    }
    answer.push_back(cnt);
    answer.push_back(big);

    return answer;
}



//문제 : 미래도시
//1에서 k를 거쳐 x로 가는 최단 거리 구하기
//플로이드 워셜 알고리즘 (특정 노드)
//2차원 그래프, 점ㅁ화식
int n2,m2;
int table[100][100];

//전체 회사의 개수 n, 경로의 개수 m, 경유지 k ,도착지 x
int solution1(int n, int m, int k, int x, vector<vector<int>> map){
    //초기화
    n2 = n;
    m2 = m;
    for(int i =0; i <100 ; i++){
        fill(table[i],table[i]+100,INF);
    }
    for(int x = 0; x<n; x++){
        for(int y = 0 ; y<n ; y++){
            if(x==y) table[x][y] = 0;
        }
    }
    for(int i = 0; i<m;i++){
        table[map[i][0]][map[i][1]] = 1;
        table[map[i][1]][map[i][0]] = 1;
    }

    for(int z = 0 ; z< n ; z++){
        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                table[x][y]= min(table[x][y], table[x][k]+table[k][y]);
            }
        }
    }

    return table[0][k] + table[k][x];
}