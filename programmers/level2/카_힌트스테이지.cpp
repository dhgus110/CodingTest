#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
constexpr int INF = 1e9;

int minCost;
vector<bool> usedHint;

void Run(int curStage, int curCost, const vector<vector<int>>& cost, const vector<vector<int>>& hint, vector<bool> hints)
{
    if(curCost > minCost)
        return;

    if(curStage == cost.size())
        return;

    int curHintCnt = 0 ; 

    for(int i = 0 ; i < hints.size() ; ++i)
    {
        if(!hints[i]) continue;

        for(int j = 1 ; j < hint[0].size() ; ++j)
        {
            if(hint[i][j] == curStage + 1)
                ++curHintCnt;
        }
    }
    curHintCnt = min(curHintCnt, (int)cost.size() - 1 );
    curCost += cost[curStage][curHintCnt];

    if(curStage == cost.size() -1)
    {
        minCost = minCost > curCost ? curCost : minCost;
        return;
    }

    Run(curStage + 1 ,curCost , cost, hint, hints);
    hints[curStage] = true;
    Run(curStage + 1 ,curCost + hint[curStage][0], cost, hint, hints);
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    vector<bool> hints(17,false);
    minCost = INF; 
    Run(1,cost[0][0], cost, hint, hints);
    
    hints[0] = true;
    Run(1,cost[0][0] + hint[0][0], cost, hint, hints);

    return minCost;
}




/* 
dp 문제가 아님!!!!!!! 
    i 번째마다 최적의 결과가 쌓여야하는데 
    이 문제는 현재 스테이지에서 어떤 선택을 했을 때
    여러 미래의 스테이지에 동시에 영향을 줌
    그래서 아래 dp로 풀려했던건 실패함!
*/

int dp[17][2];
int hints[17][17]; // [각 스테이지][각 스테이지 힌트 누적 갯수];


void init(const vector<vector<int>>& cost, const vector<vector<int>>& hint)
{
    fill(&dp[0][0], &dp[0][0] + 17 * 2, INF);
    fill(&hints[0][0], &hints[0][0] + 17 * 17, 0);
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][0] + hint[0][0];
    
    for(int i = 1 ; i < hint[0].size(); ++i)
        for(int j = 1 ; j < hint.size() ; ++j)
            ++hints[j][ hint[0][i] ] ;
    
    cout<<"1 : " <<dp[0][0] << " , "<< -1 <<endl;
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int answer = 0;
    init(cost, hint);
    
    for(int i = 1 ; i < cost.size() ; ++i)
    {
        /*
        현재 스테이지 
        - 현재 스테이지에서 힌트 번들을 안 살 때
            - 힌트 미사용 시 : 현재 값 + 이전 스테이지 힌트 미사용 최소 비용
            - 힌트 사용 시   : 현재 값(힌트 가지고 있는 대로) + 이전 스테이지 힌트 사용 최소 비용
            -> 2개 비교해서 최솟값 저장
        - 현재 스테이지에서 힌트 번들을 살 때
            - 힌트 미사용 시 : 현재 값 + 이전 스테이지 힌트 미사용 최소 비용 + 현재 스테이지 힌트비용
            - 힌트 사용 시   : 현재 값(힌트 가지고 있는 대로) + 이전 스테이지 힌트 사용 최소 비용 +현재 스테이지 힌트비용
            -> 2개 비교해서 최솟값 저장
        */
        int curHintCnt = min(hints[i][i], (int)cost.size() - 1 );
        dp[i][0] = min(cost[i][0] + dp[i - 1][0],
                       cost[i][curHintCnt] + dp[i - 1][1]);
        if( i != cost.size() -1)
        dp[i][1] = min(cost[i][0] + dp[i - 1][0] + hint[i][0],
                       cost[i][curHintCnt] + dp[i - 1][1] + hint[i][0] );
        
        for(int h = 1 ; h < hint[0].size(); ++h) //현재 스테이지의 힌트 번호들
            for(int stage = i + 1 ; stage < hint.size() ; ++stage) //i + 1 ~ n 스테이지
                ++hints[stage][ hint[i][h] ] ; //누적합 
        
        int temp = dp[i][1] == INF ? -1 : dp[i][1];
        cout<< i + 1 <<" : " <<dp[i][0] << " , "<< temp <<endl;
    }
    
    
    return dp[cost.size() - 1][0];
}

