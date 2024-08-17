//백준 1260번
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visit;

//벡터에 삽입시 정렬
void insert_sorted(vector<int>& v, const int& index)
{
    const auto insert_pos(lower_bound(v.begin(), v.end(), index));
    v.insert(insert_pos, index);
}

void init(int size ,int cnt){
    visit = vector<bool>(size + 1, false);
    graph.resize(size + 1);
    for(int i = 0 ; i<cnt ; i++){
        int n1 , n2;
        cin >> n1 >> n2;
        insert_sorted(graph[n1], n2);
        insert_sorted(graph[n2], n1);
    }
}

void dfs(int start){
    if(visit[start]) return;

    //방문한 노드 출력
    cout<< start<<' ';

    visit[start] =true;
    for(auto g : graph[start]){
        dfs(g);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(!visit[now]){
            // 방문한 노드 출력
            cout << now << ' ';

            visit[now] = true;
            for (auto g : graph[now]){
                q.push(g);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, cnt, start;
    cin >> size >> cnt >> start;

    init(size, cnt);

    dfs(start);
    cout<<endl;

    fill_n(&visit[0], size + 1, false);

    bfs(start);
    cout<<endl;

}