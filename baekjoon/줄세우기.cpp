/* 백준 2252. 줄세우기 */
/* 위상정렬 */
/* 1 <= N <= 32'000 , 1 <= M  <= 100'000 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
constexpr int MAX = 32'001;

int N,M;
int inDegree[MAX];
vector<int> v[MAX];

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    
    for(int i = 0 ; i < M ; ++i)
    {
        int start, arri;
        cin >> start >> arri;
        v[start].emplace_back(arri);
        ++inDegree[arri];
    }
}

void solution()
{
    vector<int> result;

    queue<int> q;

    for(int i = 1 ; i <= N ; ++i)
    {
        if(inDegree[i] == 0)
            q.emplace(i);
    }

    while(!q.empty())
    {
        int fr = q.front(); q.pop();
        
        result.emplace_back(fr);

        for(int n : v[fr])
            if(--inDegree[n] == 0) 
                q.emplace(n);
    }

    //output
    for(int r : result)
        cout<< r <<" ";
}

int main()
{
    init();
    solution();
}