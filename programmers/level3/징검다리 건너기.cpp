#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

constexpr int INF = 1e9;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    map<int,int, greater<int>> m;

    for(int i = 0 ; i < k ; ++i)
        ++m[stones[i]];
    
    int value = m.begin()->first;
    
    for(int i = k ; i < stones.size() ; ++i)
    {
        auto it = m.find(stones[i - k]);
        if(it->second == 1)
            m.erase(it);
        else
            --it->second;

        ++m[stones[i]];

        value = min(value , m.begin()->first);
    }


    return value;
}

//구간 내에서 가장 큰수에서 순회 돌면서 그 수에서 가장 작은 값 구하기