#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> prefixSum; //구간 누적합
    prefixSum.push_back(0.0);
    int cur = k;
    int preH = cur;
    double lozenge=0;
    while (preH > 1) {
        if (cur % 2 == 0)
            cur = cur / 2;
        else
            cur = cur * 3 + 1;

        lozenge += preH > cur ? ((double)preH*3/2 + (double)cur / 2) : ((double)cur * 3 / 2 + (double)preH / 2);
        prefixSum.push_back(lozenge);
        preH = cur;
    }

    for (auto r : ranges) {
        int start = 0 + r[0];
        int end = k + r[1];
        if (start > end)
            answer.push_back(0.0);
        else
            answer.push_back(prefixSum[end] - prefixSum[start]);
    }

    return answer;
}