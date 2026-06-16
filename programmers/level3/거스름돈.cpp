#include <string>
#include <vector>

using namespace std;

constexpr int MOD = 1'000'000'007;

int solution(int n, vector<int> money)
{
    vector<long long> dp(n + 1, 0);

    dp[0] = 1;

    for (int coin : money)
    {
        for (int i = coin; i <= n; ++i)
        {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    return dp[n];
}