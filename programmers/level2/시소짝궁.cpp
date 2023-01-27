#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <numeric>
using namespace std;

int d[1001] = { 0 };

long long solution(vector<int> weights) {
    long long answer = 0;
    map <int, vector<int>>m;
    for (auto w : weights) {
        d[w] += 1;
    }
    for (int i = 100; i <= 1000; i++) {
        if (d[i] > 0) {
            if (d[i] >= 2) {
                for (int j = 1; j < d[i]; j++)answer += j;
            }
            m[i * 2].push_back(d[i]);
            m[i * 3].push_back(d[i]);
            m[i * 4].push_back(d[i]);
        }
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        auto vec = it->second;
        if (vec.size() > 1) {
            long long  sum = accumulate(vec.begin(), vec.end(), 0);
            long long  temp = 0;
            for (int i = 0; i < vec.size(); i++) {
                cout << sum << endl;
                sum -= vec[i];
                temp += vec[i] * sum;
            }

        }
    }
    return answer;

}
