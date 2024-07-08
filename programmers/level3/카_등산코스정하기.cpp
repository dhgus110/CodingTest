#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#define INF 1e9

using namespace std;

vector<pair<int,int>>Graph[50'001]; //graph[시작노드] = {도착노드, 간선거리}
unordered_set<int> SearchGates; //검색용 출발점
unordered_set<int> SearchSummits; //검색용 도착점

int MinIntensity; //해당 코스 중에서 두개의 노드 사이의 가장 큰 비용
int MinSummit; 

void init(vector<vector<int>>const& paths, vector<int>const& gates, vector<int>const& summits){
    for (auto p : paths){
        Graph[p[0]].push_back(make_pair(p[1],p[2]));  //graph[시작노드].push({도착노드, 간선거리})
        Graph[p[1]].push_back(make_pair(p[0],p[2]));
    }

    for(auto g : gates){
        SearchGates.insert(g);
    }

    for(auto s : summits){
        SearchSummits.insert(s);
    }

    MinIntensity = INF;
    MinSummit = INF;
}

void dijksraPriorityQueue(int start, int n){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //거리, 현재노드 (가장 짧은 거리부터)
    vector<int> dist(n + 1, INF); 
    vector<int> maxValue(n + 1, INF); //intensity 저장용

    pq.push({0, start});
    dist[start] = 0;
    maxValue[start] = 0;

    while(!pq.empty()){
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for(auto next : Graph[curNode]){
            int nextDist = next.second;
            int nextNode = next.first;
            
            //출발지로 이동 금지
            if(SearchGates.find(nextNode) != SearchGates.end()) continue;
            
            if(dist[nextNode]>nextDist){
                dist[nextNode] = nextDist;
                maxValue[nextNode] = max(maxValue[curNode],nextDist);
                pq.push({nextDist, nextNode});
            }

        }

        //최소 거리로만 산봉우리에 도착했으므로 break
        if (SearchSummits.find(curNode) != SearchSummits.end()){
            if(MinIntensity > maxValue[curNode]){
                MinIntensity = maxValue[curNode];
                MinSummit = curNode;
            }
            else if (MinIntensity == maxValue[curNode] && MinSummit > curNode){
                MinSummit = curNode;
            }
            break;
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    init(paths, gates, summits);
    for(auto g : gates){
        dijksraPriorityQueue(g, n);
    }
    answer.push_back(MinSummit);
    answer.push_back(MinIntensity);

    return answer;
}