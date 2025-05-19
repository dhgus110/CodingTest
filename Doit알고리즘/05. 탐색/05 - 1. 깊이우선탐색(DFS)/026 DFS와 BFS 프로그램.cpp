//백준 1260
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int NodeSize{0}, EdgeSize{0}, startPoint{0};
bool visited[1001]={};
vector<int> Graph[1001];

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> NodeSize >> EdgeSize >> startPoint;

    int tempA {}, tempB{}; 

    for(int  i = 0; i<EdgeSize ; ++i)
    {
        cin >> tempA >> tempB;
        Graph[tempA].push_back(tempB);
        Graph[tempB].push_back(tempA);
    }

    for(int i = 1 ; i <= NodeSize ; ++i)
    {
        if(Graph[i].size() > 1)
            sort(Graph[i].begin(),Graph[i].end());
    }
    
}


void DFS(int curNode)
{
    visited[curNode] = true;
    cout<<curNode<<" ";

    for (int& nextNode : Graph[curNode])
    {
        if(!visited[nextNode])
        {
            DFS(nextNode);
        }
    }
}

void BFS()
{
    queue<int> q;

    q.push(startPoint);
    visited[startPoint] = true;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        cout << curNode << " ";

        for (int& nextNode : Graph[curNode])
        {
            if(!visited[nextNode])
            {
                q.push(nextNode);
                visited[nextNode] = true;
            }
        }
    }
}


int main()
{
    init();
    DFS(startPoint);

    cout<<'\n';
    fill(visited, visited + 1001, false);

    BFS();
}