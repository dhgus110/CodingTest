#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int dir[4] = {-1,1,-2,2};

int solution(std::vector<int> a) {
    if (a.size() == 1) return 0;

    unordered_map<int,int> graph;
    for(int i : a) ++graph[i];

    int best = 0;

    for(auto it = graph.begin() ; it != graph.end() ; ++it)
    {
        int cur = it->first;
        if(best >= it->second) continue;

        int cnt = 0;

        for(int i = 0 ; i < a.size() - 1; )
        {
            if (a[i] != a[i + 1] && (a[i] == cur || a[i + 1] == cur))
            {
                cnt++;
                i += 2; 
            }
            else
                i += 1;
        }

        int index = a.size()-1;
        if(a[index] == cur && a[index-1] != cur && a[index-2] != cur) ++cnt;

        best = max(best, cnt);
    }

    return  best * 2;
}
