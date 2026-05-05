#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

ll min(ll a, ll b)
{
    return a < b ? a : b;
}
ll max (ll a, ll b)
{
    return a < b ? b : a;
}

ll solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{
    ll l = 0, r = 1e15, m;
    int townCnt = g.size();

    while (true)
    {
        m = (l + r) / 2;
        ll moveG, moveS;
        for (size_t i = 0; i < townCnt; ++i)
        {
            ll power = 0;
            ll carry = m / (2 * t[i]);      // 왕복 운반 수
            if (m % (2 * t[i]) >= t[i])     // 편도 운반 수
                ++carry;
            power += w[i] * carry;

            ll powerG = min(power,g[i]);
            moveG += powerG;
            power -= powerG;

            ll powerS = min(power,s[i]);
            moveS += powerS;
            power -= powerS;
        }
    }


    return ;
}

/*
결국 특정 시간에 각 마을마다 전달된 자원으로  a,b 비교 -> 특정 시간만 구하면 됨.
(각 마을은 특정시간에 운반할 수 있는 최대 운반력을 계산해야함)
이분탐색? ㅇㅋ
  각 마을에서 해당 시간(m)동안 최대 운반력 계산 : P = w/t *m   (m/t + 1)/ 2w   m / 2wt + 1/2w
  왕복 : 2t : w = m : ? ->   ? = (w * m) / 2t
  편도 : if( m % 2t >= t) ? = w

*/