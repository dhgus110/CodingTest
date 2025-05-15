#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0 ; i < schedules.size() ;++i)
    {
        int safeTime = (schedules[i] +10) % 100 >= 60 ?  schedules[i] +50 : schedules[i] +10;
        int day = startday;
        bool flag = false;
        
        for(auto& log : timelogs[i])
        {
            day = day > 7 ? 1 : day;
            
            if( day >=6)
            {
                ++day;
                continue;
            }
            
            if( safeTime < log )
            {
                flag = true;
                break;
            }
             ++day;
        }
        if(!flag) ++answer;
    }
    
    
    return answer;
}
