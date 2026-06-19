/*
입력값은 선형 연결 순서를 보장함.
행렬의 특성을 기본 베이스로 깔고 언급을 안한거 같음.

곱의 최소 연산 횟수를 구하는 문제. -> 구간 dp 이용
즉,  a부터 b까지의 곱의 최소 연산 횟수 구하기

dp[a][b]   // a < b
행렬이 1개일 때 물론 연산 횟수는 0 이다.
dp[1][1] = 0 , [2][2] , [3][3]  ... 이런식으로 채워 나갈 수 있다.

행렬이 2개일 때
[1][2] , [2][3], [3][4] ...

행렬이 3개일 때
min(1~3) , min (2~4) ...

식을 세워보면
dp[a][b] = min(dp[a][b] , dp[a][k] + dp[k + 1][b] + m[a][0]*m[k][1]*m[b][1]) 

ex)
a = 1 b= 3
k = 1~2
dp[1][1] + dp[2][3]  + m[1][0]*m[1][1]*m[3][1]
dp[1][2] + dp[3][3]  + m[1][0]*m[2][1]*m[3][1]

*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

constexpr int INF = 1e9;

int dp[201][201]; //  a < b

int solution(vector<vector<int>> matrix_sizes)
{
    int mSize = matrix_sizes.size();
    // init
    fill(&dp[0][0], &dp[0][0] + 201 * 201, INF);
    for (int i = 0; i < mSize; ++i)
        dp[i][i] = 0;

    // run
    for (int section = 2; section <= mSize; ++section)
    {
        for (int a = 0; a < mSize; ++a)
        {
            int b = a + section - 1;
            if (b >= mSize)
                break;
            for (int k = a; k < b; ++k)
                dp[a][b] = min(dp[a][b],
                               dp[a][k] + dp[k + 1][b] + matrix_sizes[a][0] * matrix_sizes[k][1] * matrix_sizes[b][1]);
        }
    }

    return dp[0][mSize - 1];
}
