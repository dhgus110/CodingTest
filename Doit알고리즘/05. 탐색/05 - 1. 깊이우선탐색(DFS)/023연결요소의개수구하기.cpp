//백준 11724번
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> graph;
vector<bool> visit;

void init(int size ,int cnt){
    graph.resize(size + 1);
    visit = vector<bool>(size + 1, false);
    for (int i = 0; i < cnt; i++){
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
    }
}

void dfs(int v){
    if (visit[v]) return;

    visit[v] =true;

    for(auto g :graph[v]){
        if(!visit[g])
            dfs(g);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, cnt; //노드개수, 에지 개수
    cin >> size >> cnt;

    init(size, cnt);

    int answer =0;
    for (int i = 1; i <= size; i++){
        if (!visit[i]){
            answer++;
            dfs(i);
        }
    }

    cout<<answer<<endl;
}