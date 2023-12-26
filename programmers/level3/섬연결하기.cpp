#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define INF 1e9
#define PII pair<int,int>

using namespace std;
//주의 : 문제 조건에 섬 번호가 0부터 시작한다는 말이 없음 섬번호가 : 2, 6 ,12, 95 일 수도?

//-------------- p r i m --------------
vector<PII> *map; //map[i] i가 출발지인 노드, {first = 비용 ,second =도착 노드}
priority_queue<PII,vector<PII>,greater<PII>> dist; //한 번 접근했던 노드들의 인접 간선들과 인접 노드들 집합
bool *isVisited;

void add_edge(int node){
    for(auto m : map[node]){
        dist.push(m);
    }
}

int prim(int n, int startNode){
    int result =0;
    dist.push({0,startNode}); // 비용 0, 시작노드 0을 넣음
    for(int i = 0 ; i<n ; i++){
        int nowNode= startNode;
        int minDist =INF;

        //T 에 있는 노드와 T 에 없는 노드 사이의 간선 중 가중치가 최소인 간선을 찾는다.
        while(!dist.empty()){
            nowNode = dist.top().second;
            if(!isVisited[nowNode]){
                minDist =dist.top().first;
                break;
            }
            dist.pop();
        }

        //if(minDist == INF) return -1  //연결그래프가 아님
        if(minDist != INF){
            result += minDist;
            isVisited[nowNode] = true;
            add_edge(nowNode);
        }
    }
    return result;
}

//------------- K r u s k a l ---------------
//노드의 최종 부모를 가르킨다.
int check[101];

//최상위 부모노드 찾기
int getParent(int node){
    if(check[node]==node)return node;
    return getParent(check[node]);
}
//두 노드를 작은 값 기준으로 연결
void unionParent(int n1, int n2){
    n1 = getParent(n1);
    n2 = getParent(n2);
    if (n1 < n2)
        check[n2] = n1;
    else
        check[n1] = n2;
}

//싸이클이 존재하면 true ,아니면 false 
bool isCycle(int n1, int n2){
    n1 = getParent(n1);
    n2 = getParent(n2);
    if(n1==n2)return true;
    else return false;   
}

bool cmp(vector<int> a, vector<int> b) {
    return a[2]<b[2];
}

//------------- s o l u t i o n -------------------
int solution(int n, vector<vector<int>> costs) {
    int result = 0 ;

    //Prim
    int startNode = costs[0][0];
    int maxNode =-1; //최대값 노드
    map = new vector<PII>[101]; //n의 범위는 0 ~ 100이고 0부터 시작한다는 말이 없으니 101을 박는다
    isVisited = new bool[101];
    for(int i = 0 ;i <101 ; i++){
        isVisited[i] =false;
    }
    for(auto c : costs){
        map[c[0]].push_back({c[2],c[1]});
        map[c[1]].push_back({c[2],c[0]});
        maxNode = maxNode < c[0] ? (c[0] < c[1] ? c[1] : c[0]) : (maxNode < c[1] ? c[1] : maxNode);

    }
    result = prim(maxNode + 1,startNode);

    //kruskal
    //간선을 오름차순으로 정렬
    sort(costs.begin(),costs.end(),cmp);
    //각 노드는 자기 자신이 부모로 초기화
    for(int i = 0 ; i<n ;i++){
        check[i]=i;
    }

    int sum =0;
    for(int i = 0 ; i<costs.size();i++){
        if(!isCycle(costs[i][0],costs[i][1])){
            sum += costs[i][2];
            unionParent(costs[i][0],costs[i][1]);
        }
    }
    result =sum;
    


    return result;
}   