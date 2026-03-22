#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    vector<int> dp(m + 1,INF);
    
    dp[0] = 0; //아무것도 훔치지 않음 
    
    for(const auto& i : info)
    {
        vector<int> nextDp(m + 1,INF);
        
        for(int b = 0 ; b < m ; ++b)
        {
            if(dp[b] == INF) continue;
            
            //a가 훔쳤을 때
            if(dp[b] + i[0] < n)
                nextDp[b] = min(nextDp[b] ,dp[b]+i[0]);
            
            //b가 훔쳤을 때
            if(b + i[1] < m)
                nextDp[b + i[1]] = min(nextDp[b + i[1]] ,dp[b]);  
        }
        
        dp = nextDp;
    }
    
    answer = INF;
    answer = *min_element(dp.begin(),dp.end());
    
    return (answer == INF ? -1 : answer);
}

/*
각 물건에는 [a,b]흔적 수치가 있음
물건 하나에 대해 a 또는 b 도둑이 훔쳐야함
a도둑이 남긴 흔적 누적 개수의 최솟값을 구해야함.

누적 -> 누적합 or dp (비교하여 최솟값을 찾으므로 dp gogo)
b기준 0~m 흔적에 대한 a 도둑의 최소 흔적을 갱신하기 
*/

