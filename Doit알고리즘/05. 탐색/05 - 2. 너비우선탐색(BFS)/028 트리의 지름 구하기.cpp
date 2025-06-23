//백준 1167
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int,int>> Graph[100'001];
int Dist[100'001];
bool Visited[100'001];
int NodeSize = {0};

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>NodeSize;

    for(int  i = 0 ; i <NodeSize ; ++i)
    {    
        int start;
        cin>>start;
        while(true)
        {
            int node,edge;
            cin>>node;
            if(node == -1) break;
            cin>>edge;

            Graph[start].push_back({node, edge});
        }
    }

    fill(Dist, Dist + 100'001 , 0);
    fill(Visited, Visited + 100'001 , false);

}

//최장거리 구하기
void run(int start)
{
    queue<int> q; 
    q.push(start);
    Visited[start] = true; 

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto next : Graph[cur])
        {
           
            int nextNode = next.first;
            int nextCost = next.second;

            if(Visited[nextNode]) continue;
            
            Visited[nextNode] =true;
            q.push(nextNode);
            Dist[nextNode]=  Dist[cur] + nextCost;
        }

    }
}

int main()
{

    init();
    run(1);
    int max = 1;
    for(int i = 2;  i <=NodeSize; ++i)
    {
        if(Dist[max]<Dist[i]) max = i;
    }

    
    fill(Dist, Dist + 100'001 , 0);
    fill(Visited, Visited + 100'001 , false);
    
    run(max);
    
    int maxValue = 0;
    for(int i = 1 ; i <=NodeSize ;++i)
    {
        maxValue = Dist[i]< maxValue ? maxValue :  Dist[i];
    }

    cout<<maxValue;
}