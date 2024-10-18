#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#define INF 1e9
#define ll long long

using namespace std;

int minLevel, maxLevel;

void init(vector<int> const& diffs){
    int dummyMin = INF, dummyMax = 0;
    for(auto d : diffs){
        dummyMin = dummyMin < d ? dummyMin : d;
        dummyMax = dummyMax > d ? dummyMax : d;
    }
    minLevel = dummyMin; maxLevel = dummyMax;
}

//탐색
pair<ll,ll> search(vector<int> const& diffs, vector<int> const& times, int level){
    long long originalProgressTime = 0;
    long long minorProgressTime = 0;
    int minorLevel = level - 1;
    for (int i = 0; i < times.size(); i++)
    {
        if (diffs[i] <= level)
            originalProgressTime += times[i];
        else if (diffs[i] > level)
            originalProgressTime += (times[i] + times[i - 1]) * (diffs[i] - level) + times[i];

        if (diffs[i] <= minorLevel)
            minorProgressTime += times[i];
        else if (diffs[i] > minorLevel)
            minorProgressTime += (times[i] + times[i - 1]) * (diffs[i] - minorLevel) + times[i];
    }

    return make_pair(originalProgressTime, minorProgressTime);
}

//이진탐색 이용
int run(vector<int> const& diffs, vector<int> const& times, long long limit){
    int pivot = 0;
    int left = minLevel; 
    int right = maxLevel; 
    
    while(true){
        pivot = floor((left + right) / 2);
        if (pivot == 0){
            pivot = 1;
            break;
        }
        auto progressTime = search(diffs, times, pivot);

        //시간초과시 레벨을 더 높이자
        if(limit < progressTime.first){
            left = pivot + 1;
        }
        //제한시간 내 해결시 레벨 최솟값을 찾아야 함
        else if(limit >= progressTime.first){
            if (limit < progressTime.second){
                break;
            }

            right = pivot - 1;
        }
    }

    return pivot;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    init(diffs);
    return run(diffs, times, limit);
}