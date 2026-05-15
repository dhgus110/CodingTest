#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int weakSize = weak.size();
    int distSize = dist.size();
    int answer = distSize + 1;
    
    sort(dist.begin(), dist.end());

    do
    {
        for(int start = 0 ; start < weakSize ; ++start)
        {
            int friends = 1;
            int pos = weak[start] + dist[friends - 1]; //첫 친구가 닿는 끝 점

            for(int i = 0 ; i < weakSize ; ++i)
            {
                int cur = weak[(start + i) % weakSize];
                cur = cur < weak[start] ? cur + n : cur; //원형 처리

                if(cur > pos) //못 닿음
                {
                    ++friends;
                    if(friends > distSize) break;
                    pos = cur + dist[friends - 1];
                }
            }
            if(friends <= distSize)
            answer = min(answer, friends);
        }
    } while (next_permutation(dist.begin(),dist.end()));

    return answer > distSize ? -1 : answer;
}

/*  
dist <= 8 : 순열로 나열.   8! = 40320 

각 weak 지점을 시작점으로 시계방향으로 돌기
    현재 친구가 닿는 범위는 ok, 못 닿는 범위는 다음 친구 투입
    weak를 전부 커버한 최솟값 갱신 

8! * 15 * 15

*/