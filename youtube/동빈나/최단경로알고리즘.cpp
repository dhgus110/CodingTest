#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1e9 //무한의 값을 10억으로 설정

using namespace std;

/////////다익스트라 알고리즘 구현///////
//노드의 개수(n) 간선의 개수(m) 시작 노드 번호(start)
int n, m , start;
//각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int,int>> graph[100001];
//방문한적 있는지?
bool visited[100001];
//최단거리테이블 만들기
int d[100001];

int getSmallestNode(){
    int minValue= INF;
    int index =0; //가장 최단 거리가 짧은 노드
    for(int i = 0; i <n ; i++){
        if(d[i]<minValue && !visited[i]){
            minValue = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start){
    d[start] = 0;
    visited[start] = true;
    for(int i = 0 ; i<graph[start].size(); i++){
        d[graph[start][i].first] = graph[start][i].second;
    }
    //시작 노드르 제외한 n-1개의 노드를 반복
    for(int i = 0; i <n-1;i++){
        int now =getSmallestNode();
        visited[now]=true;
        //현재 노드와 다른 연결된 노드 확인
        for (int j = 0; j < graph[now].size(); j++){
            int cost = d[now] + graph[now][j].second;
            //현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][j].first]){
                d[graph[now][j].first] = cost;
            }
        }
    }
}
void solution0(vector<vector<pair<int,int>>>){ //0 번째 pair<a,b> : 0번째 노드가 a번 노드로 cost b 만큼
    //최단 거리 테이블을 모두 무한으로 초기화
    fill_n(d, 100001, INF);
    //todo..
    //n,m,start,graph 다 초기화 해줘야함
    dijkstra(start);
}


/////////우선순위를 이용한 다익스트라//////////
void dijkstraPriorityQueue(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    d[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first; //현재 노드까지의 비용, 최소힙을 사용하기 위해 (-)부호 사용
        int now = pq.top().second; //현재 노드
        pq.pop();
        if(d[now] <dist) continue; //현재 노드가 이미 처리가 된 노드라면
        for(int i = 0 ;i<graph[now].size();i++){
            int cost = dist +graph[now][i].second;
            //현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if(cost < d[graph[now][i].second]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first)); //이것도 마찬가지로 최소힙사용하기 위해
            }
        }
    }
}


///////////플로이드 워셜 알고리즘////////////////
int no,ma; //노드의 개수 no , 간선의 개수 ma
int table[501][501]; //2차원 테이블 노드의 개수가 최대 500개라면

int floydWarshall(int n , int m ,vector<vector<pair<int,int>>> map){
    no = n;
    ma = m;
    //테이블 INF 초기화
    for(int i = 0 ; i <501 ; i++){
        fill(table[i], table[i]+501,INF);
    }

    //자기 자신으로 가는 비용 0으로 초기화
    for(int i = 1 ;i<=n;i++){
        for(int j = 1; j<=n;j++){
            if (i == j) table[i][j] = 0;
        }
    }

    //간선에 대한 정보 table에 초기화해주기
    //a에서 b로 가는 비용이 c 
    //table[a][b] = c;

    //플로이드 워셜 알고리즘
    //거쳐가는 노드 k ,출발노드 a, 도착노드 b
    for (int k = 1; k <= n; k++)
        for (int a = 1; a <= n; a++)
            for (int b = 1; b <= n; b++)
                table[a][b] = min(table[a][b],table[a][k]+table[k][b]);


}

int main(){

}