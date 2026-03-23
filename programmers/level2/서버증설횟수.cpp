#include <string>
#include <vector>
#include <queue>

using namespace std;

int RunTime(queue<pair<int,int>>& servers,int k)
{
    int discardServers = 0 ;
    queue<pair<int,int>> tempServer;
    
    while(!servers.empty())
    {
        pair<int,int> s = servers.front();
        servers.pop();
        
        if(s.second == k) 
        {
            discardServers += s.first;
            continue;
        }
        
        tempServer.push({s.first, s.second + 1 });
    }
    servers.swap(tempServer);
    return discardServers;
}

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    queue<pair<int,int>> servers;
    int activeServer = 0;
    
    for(auto player : players)
    {
        activeServer -= RunTime(servers, k);

        int required = player / m;
        int need = max(0, required - activeServer);

        if(need > 0)
        {
            answer += need;
            activeServer += need;
            servers.push({need, 1});
        }       
    }
    
    
    return answer;
}