#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> s;

bool checkName(const string& user,const string& ban)
{
    if(user.size() != ban.size())
        return false;

    for(int i = 0 ; i < ban.size() && i < user.size() ; ++i)
    {
        if (ban[i] == '*')
            continue;
        else if (ban[i] != user[i])
        {
            return false;
        }
    }
    return true;
}

void dfs(int cur,int check ,const vector<string>& user_id,const vector<string>& banned_id)
{
    if(cur == banned_id.size())
    {
        s.emplace(check);
        return;
    }
    
    for(int i = 0 ; i < user_id.size(); ++i)
    {
        if(check & (1 << i)) continue;
        
        if(checkName(user_id[i], banned_id[cur]))
            dfs(cur + 1, check | (1<<i), user_id, banned_id);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(0,0,user_id,banned_id);
    return s.size();
}

/* dfs + 비트 패킹으로 각 분기별 방문처리(방문해야하는 곳이 적었음) */