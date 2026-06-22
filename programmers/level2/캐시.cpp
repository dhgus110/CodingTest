#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if( cacheSize == 0) return 5 * cities.size();

    int answer = 0;
    
    for(size_t i = 0 ; i < cities.size() ;  ++i)
    {
        transform(cities[i].begin(), cities[i].end(),cities[i].begin(),[](unsigned char c) { return tolower(c);});
    }
    
    list<string> memory;
    unordered_map<string, list<string>::iterator> um;
    
    for(int i = 0 ; i < cities.size() ; ++i)
    {
        auto it = um.find(cities[i]);
        if(it != um.end())
        {
            answer += 1;
            memory.erase(it->second);
        }
        else
        {
            answer += 5;
            
            if(memory.size() == cacheSize)
            {
                string old = memory.front();
                memory.pop_front();
                um.erase(old);
            }
        }
        
        memory.push_back(cities[i]);
        um[cities[i]] = prev(memory.end());

    }
    
    return answer;
}

/*
가장 오랫동안 사용하지 않은 것을 삭제

히트 = 1
미스 = 5
*/