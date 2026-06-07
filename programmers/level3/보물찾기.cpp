/*
임의의 열에 접근해서 보물이 왼쪽에 있는지 오른쪽에 있는지 찾는 문제.

열마다 접근 비용이 존재.

이진탐색으로 풀이 시  
    첫 mid가  mid(money)  > 사용할 수 있는 money
    일 때 잘못 된 풀이가 됨.
    ->이런 풀이는 탐색 횟수 최소화같은 경우임.

이 문제는 최악 비용을 보장해야함.
구간 dp 이용 가능
dp[lo][hi] = 보물이 lo ~ hi 열 안에 있다고 알때, 최악의 경우 추가로 드는 최소 비용

길이 (1 ~ w)에 대한 구간 dp를 구해야함
길이 len == 1일 때 [1,1] [2,2] [3,3] [4,4] [5,5] ....
len == 2일 때 [1,2] [2,3] [3,4] [4,5] ...
len == 3일 때 [1,3] [2,4] [3,5] [4,6] ...
...


lo ~ hi 구간중에서 삽을 어디에 꽂을지 분할점 k를 구해야함.
분할점 k 기준 보물이 어느 한쪽에만 존재함. 그래서 최악을 잡으면
cost = depth[k] + max(dp[lo][k-1], dp[k+1][hi])

lo ~ hi 구간안에서 분할 점 k의 최악의 코스트중에서 최소 코스트를 구하면
lo ~ hi 구간안에서 최악이 가장 작은 값 k 를 구할 수 있음.
그후 구간마다 k를 저장함. -> choice[lo][hi] = k;

이제 구간별 k를 다 저장했으면
구간 l과 r을 잡고
k = choice[l][r]
res = excavate(k)
if(res == 0)  return k
if(res == 1)  l = k+1
if(res == -1) r = k-1
반복하며 k를 구하자


*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

constexpr int INF = 1e9;

extern int excavate(int);

int dp[201][201];
int choice[201][201];

int solution(vector<int> depth, int money) {
    int depthSize = depth.size();

    for(int w = 1 ; w <= depthSize ; ++w)
    {
        for(int l = 1 ; l + w - 1 <= depthSize ; ++l)
        {
            int r = l + w - 1;
            dp[l][r] = INF;
   
            for(int k = l  ; k <= r ; ++k)
            {
                int cost = depth[k - 1] + max(dp[l][k - 1], dp[k + 1][r]);
                if(cost < dp[l][r])
                {
                    dp[l][r] = cost;
                    choice[l][r] = k;
                }
            }
        }
    }

    int l = 1 , r = depthSize;
    int k;
    while(l <= r)
    {
        k = choice[l][r];
        int res = excavate(k);
        if(res == 0) return k;
        else if(res == 1) l = k + 1;
        else if(res == -1) r = k - 1;
        
    }

    return 0;
}
