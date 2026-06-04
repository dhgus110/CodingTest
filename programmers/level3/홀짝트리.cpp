#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*   방법 1 : 

1 ≤ nodes의 길이 ≤ 400,000
1 ≤ edges의 길이 ≤ 1,000,000

포레스트 : 사이클이 없는 트리의 집합

현재 노드가 루트 노드일 때 자식의 갯수는 == size()   <- 사실 이건 필요없다.
현재 노드가 자식 노드일 때 자식의 갯수는 == size() - 1   -> childNodeTreeInfo 

각 노드에 대한 관계 그래프를 그리고
각 트리마다 임의의 루트 노드를 잡고 childNodeTreeInfo의 수를 계산.
홀짝 트리이면
    루트 노드에 해당하는 노드는 원래 홀짝 노드 성질에 해당하지만. 만약 자식 노드를 하나 빼면 역홀짝 트리가 됨.
    그리고 나머지 노드들은 홀짝 노드를 만족해야함.
    즉, 역홀짝count = 1 , 홀짝count =? 가 만족해야함.
역홀짝 트리는
    반대.    
    즉, 홀짝count = 1 , 역홀짝count =? 가 만족해야함.

-> bfs 각 노드 한번씩 돌려서 해결 가능 
*/

struct NODEDATA
{
    vector<int> node;
    int childNodeTreeInfo = 0;   // 1:홀짝, 2:역홀짝 (자식일 때, 자식수 = degree-1)

    void UpdateTreeInfo(int curNode)
    {
        int childCnt = (int)node.size() - 1;   // 자식일 때 자식 수
        // 번호 홀짝 == 자식수 홀짝 → 홀짝(1), 다르면 역홀짝(2)
        childNodeTreeInfo = (curNode % 2 == ((childCnt % 2) + 2) % 2) ? 1 : 2;
    }
};

NODEDATA graph[1'000'001];

int init(const vector<int>& nodes, const vector<vector<int>>& edges)
{
    int maxId = 0;
    // for(int n : nodes) maxId = max(maxId, n);
    // graph.assign(maxId + 1, NODEDATA());

    for(auto const& edge : edges)
    {
        graph[edge[0]].node.emplace_back(edge[1]);
        graph[edge[1]].node.emplace_back(edge[0]);
    }

    for(int n : nodes){
        maxId = max(maxId, n);
        graph[n].UpdateTreeInfo(n);
    } 

    return maxId;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2,0);
    int maxId = init(nodes, edges);
    vector<bool> visited(maxId + 1, false); 

    for(int start : nodes)
    {
        if(visited[start]) continue;

        int count1 = 0, count2 = 0;  //start가 루트노드일 때 총 childNodeTreeInfo  홀짝/역홀짝 개수
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty())      
        {
            int cur = q.front(); q.pop();
            (graph[cur].childNodeTreeInfo == 1) ? ++count1 : ++count2;

            for(int nxt : graph[cur].node)
                if(!visited[nxt])
                {
                    visited[nxt] = true;
                    q.push(nxt);
                }
        }

        if(count2 == 1) ++answer[0];  // 홀짝 트리 (루트노드의 childNodeTreeInfo만 역홀짝이고 나머지 다 홀짝이면 홀짝트리.)
        if(count1 == 1) ++answer[1];  // 역홀짝 트리
    }

    return answer;
}




//-------------------------union-find 풀이--------------------
/*
    트리에서 간선의 수만으로 홀짝/ 역홀짝인지 알 수 있음.

*/
int parent[1'000'001];
int degree[1'000'001];

int findParent(int x)
{
    while(parent[x] != x)
    {
        int next = parent[x];
        parent[x] = parent[parent[x]];
        x = next;
    }
   return x; 
}

void unionParent(int a, int b)
{
    parent[findParent(a)] = findParent(b);
}

int init2(const vector<int>& nodes, const vector<vector<int>>& edges)
{
    int maxValue = 0;
    for(int node : nodes){
       parent[node] = node;
       maxValue = max(maxValue, node);
    } 

    for(const auto& edge :edges) 
    {
        unionParent(edge[0], edge[1]);
        ++degree[edge[0]];
        ++degree[edge[1]];
    }
    return maxValue;
}

vector<int> solution2(vector<int> nodes, vector<vector<int>> edges) 
{
    vector<int> answer(2,0);
    int maxValue = init2(nodes, edges);
    vector<int> cnt1(maxValue + 1, 0);
    vector<int> cnt2(maxValue + 1, 0);

    //run
    for(int node : nodes)
    {
        int root = findParent(node);
        if((node % 2) == (degree[node] % 2)) ++cnt1[root];
        else ++cnt2[root];
    }

    for(int node : nodes)
    {
        if(findParent(node) == node)
        {
            if(cnt2[node] == 1) ++answer[0];  // 홀짝트리
            if(cnt1[node] == 1) ++answer[1];  // 역홀짝트리
        }
    }

    return answer;
}
