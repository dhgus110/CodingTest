#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> cores) {
    int coreSize = cores.size();
    if( n <= coreSize) return n;

    // 전부 완료되는 최소 시간 구하기
    long long l = 0, r =  n * 10'000LL;
    n -= coreSize;

    while( l < r)
    {
         long long mid = (l + r) / 2LL;
         long long processed = 0;

        for(int core : cores){
            if( core == 0) continue;
            processed += mid / (1LL * core);
        }
        if( processed >= n)  r = mid;
        else  l = mid + 1LL;
    }
    long long time = l;

    // 마지막 코어 찾기
    long long done = 0;
    long long prevTime = time - 1LL; 

    for(int core : cores){
        if( core == 0) continue;
        done += prevTime / (1LL * core); //최소시간 바로 이전 시간에 완료된 작업량
    }

    for(int i = 0 ; i < coreSize ; ++i)
    {
        if(time % (cores[i] * 1LL) == 0)
        {
            ++done;
            if(done == n)  return i + 1;
        }
    }
    return 0;
}


int solution2(int n, vector<int> cores) {
    int coreSize = (int)cores.size();
    if (n <= coreSize) return n;

    int coreMin = *min_element(cores.begin(), cores.end());
    int coreMax = *max_element(cores.begin(), cores.end());
    int remaining = n - coreSize;

    // 답이 존재할 수 있는 가장 좁은 시간 범위
    //  - 모든 코어가 coreMin(최속)일 때 t* ≈ coreMin * remaining / coreSize
    //  - 모든 코어가 coreMax(최저속)일 때 t* ≈ coreMax * remaining / coreSize
    int lo = (int)((long long)coreMin * remaining / coreSize);
    int hi = (int)((long long)coreMax * remaining / coreSize) + coreMax;
    if (lo < 1) lo = 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        long long workDone = coreSize;     // 시각 0의 초기 할당 포함
        int currentWork = 0;               // mid 시점에 ticking 하는 코어 수
        for (int c : cores) {
            workDone += mid / c;
            if (mid % c == 0) ++currentWork;
        }

        if (workDone < n) {
            lo = mid + 1;                  // 아직 n번째까지 못 감
        } else if (workDone - currentWork >= n) {
            hi = mid - 1;                  // 이미 mid 이전에 n번째 끝남
        } else {
            // n번째 작업이 정확히 mid 시점에 할당됨 — 어느 코어인지 찾기
            long long done = workDone - currentWork;
            for (int i = 0; i < coreSize; ++i) {
                if (mid % cores[i] == 0) {
                    if (++done == n) return i + 1;
                }
            }
        }
    }
    return 0;
}
