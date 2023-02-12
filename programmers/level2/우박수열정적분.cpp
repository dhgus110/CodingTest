#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> prefixSum; //구간 누적합
    prefixSum.push_back(0.0);
    double cur = k;
    double preH = cur;

    while (preH > 1) {
        if ((int)cur % 2 == 0)
            cur = cur / 2;
        else
            cur = cur * 3 + 1;

        double lozenge = (preH > cur ? preH - (preH - cur) / 2 : cur - (cur - preH) / 2);
        prefixSum.push_back(prefixSum.back() + lozenge);
        preH = cur;
    }

    for (auto r : ranges) {
        int start = 0 + r[0];
        int end = prefixSum.size() - 1 + r[1];
        if (start > end)
            answer.push_back(-1.0);
        else
            answer.push_back(prefixSum[end] - prefixSum[start]);
    }

    return answer;
}
