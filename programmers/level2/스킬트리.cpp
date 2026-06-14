#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char,int> um;
    
    for(int i = 0 ; i < skill.size(); ++i)
        um[skill[i]] = i;
    
    for(const string& skill : skill_trees)
    {
        int index = 0;
        bool flag = true;
        
        for(char sk : skill)
        {
            auto it = um.find(sk);
            if(it != um.end())
            {
                if(it->second != index)
                {
                    flag = false;
                    break;
                }
                ++index;
            }
        }
        if(flag) ++answer;
    }
    
    return answer;
}