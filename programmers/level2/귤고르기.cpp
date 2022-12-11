#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;

    for (auto const& t : tangerine)
        ++m[t];
    
    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    
    for (auto v : vec) {
        cout << v.first << " " << v.second << endl;
    }

    while (k > 0) {
        k -= vec[answer++].second;

    }

    return answer;
}