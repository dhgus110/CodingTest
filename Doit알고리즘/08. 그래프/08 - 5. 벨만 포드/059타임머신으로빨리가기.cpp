//백준 11657번
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <limits.h>
#define TIII tuple<int, int, int>

using namespace std;

vector<TIII> edges; // <출발,도착,가중치>
vector<long> d; // 가장 빠른 시간 기록
int nodeSize, edgeSize;

void init(){
    cin >> nodeSize >> edgeSize;

    d.resize(nodeSize + 1);
    fill_n(d, nodeSize + 1, LONG_MAX);

    for (int i = 0; i < edgeSize; i++){
        int start, end, time;
        cin >> start >> end >> time;
        edges.push_back(make_tuple(start, end, time));
    }
}

void bellmanford(int departure){
    d[departure] = 0 ;

    //노드의 수보다 1 적게 수행
    for (int i = 1; i < nodeSize; i++){

        for (int j = 0; j < edgeSize; j++){
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int time = get<2>(edges[j]);

            //더 가까운 최단거리가 있다면 갱신
            if (d[start] != LONG_MAX && d[start] + time < d[end])
                d[end] = d[start] + time;
        }
    }

    bool isCycle =false;

    //음수 사이클 존재를 확인하기 위해 한바퀴 더 돔
    for (int i = 0; i < edgeSize; i++){
        int start = get<0>(edges[i]);
        int end = get<1>(edges[i]);
        int time = get<2>(edges[i]);

        if (d[start] != LONG_MAX && d[start] + time < d[end])
            isCycle =true;
    }

    //print
    if(isCycle) cout<<"-1"<<endl;
    else{
        for (int i = 2; i <= nodeSize; i++){
            if (d[i] == LONG_MAX) cout<< "-1"<<endl;
            else cout<<d[i]<<endl;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    bellmanford(1);

}