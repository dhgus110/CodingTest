// 늑대가 계속 따라오는 줄 모르고 우선순위 큐를 사용.. 당연히 다음 노드의 상태들을 모르니 실패
// 이미 지나간 노드를 다시 되돌아가야 할 수도 있는 문제이다. 물론 다시 지나간다해서 변하는건 없다.
// -> for문으로 이동가능한 정점들을 탐색하면서, 하나씩 해당 정점을 새로운 이동가능한 정점에서 제거하여, 다음 재귀호출을 진행
// dfs로 완전탐색
/*
struct Info{
    int animal; //양:0, 늑대:1
    int cnt; //늑대 몇 마리? (양의 수는 여기서 관리하지 않는다.)
    int node; //해당 노드
    Info(int _animal, int _cnt, int _node) : animal(_animal), cnt(_cnt), node(_node) {}
};

struct InfoCompare {
    bool operator()(const Info& a, const Info& b) {
         if(a.animal== b.animal) return a.cnt > b.cnt;
         return a.animal > b.animal;
     }
};
priority_queue<Info, vector<Info>, InfoCompare> pq;
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> Graph[18]; //graph[부모노드] = { 자식노드,.. }
vector<int> Info;
int maxSheepCnt = 0;

//next= {(양:0 or 늑대:1) , nextNode}
void dfs(int sheepCnt, int wolfCnt, vector<pair<int,int>> next){
    if (next.empty() || sheepCnt <= wolfCnt){
        maxSheepCnt = max(maxSheepCnt, sheepCnt);
        return;
    }

    for (int i = 0; i < next.size(); i++){
        vector<pair<int,int>> dummy = next;

        //부모노드 삭제
        dummy.erase(dummy.begin() + i);  
        //자식노드 삽입
        for(auto g : Graph[next[i].second]){
            dummy.push_back(make_pair(Info[g], g));
        }

        if(next[i].first == 0 ) dfs(sheepCnt + 1, wolfCnt, dummy);
        else dfs(sheepCnt, wolfCnt + 1 ,dummy);
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {
    //init
    for(auto e :edges){
        Graph[e[0]].push_back(e[1]);
    }
    Info = info;

    vector<pair<int,int>> dummy;
    for(auto g : Graph[0]){
        dummy.push_back(make_pair(info[g], g));
    }

    dfs(1, 0, dummy);

    return maxSheepCnt;
}