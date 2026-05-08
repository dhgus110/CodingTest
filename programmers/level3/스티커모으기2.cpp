#include <iostream>
#include <vector>
using namespace std;

int dp[100'001][2];

int solution(vector<int> sticker)
{
    if(sticker.size() == 1) return sticker[0];
    
    fill(&dp[0][0], &dp[0][0] + 100'001 * 2, 0);
    
    dp[0][0] = sticker[0];
    dp[1][0] = dp[0][0];
    dp[1][1] = sticker[1];

    for( int i = 2 ; i < sticker.size() ; ++i)
    {
        if(i < sticker.size() -1 )
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + sticker[i]);
        
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + sticker[i]);
        
    }

    return max(dp[sticker.size()-2][0],dp[sticker.size()-1][1]);
}