#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> cnt(e + 1, 0);
    vector<int> ans(e + 1);
    for (int a = 1; a <= e; a++) {
        ans[a] = a;
        for (int b = 1; b <= e/a; b++) {
            cnt[a * b]++;
        }
    }

    int min = *min_element(starts.begin(), starts.end());

    for (int i = e - 1; i >= min; i--) {
        if (cnt[i] < cnt[i + 1]) {
            cnt[i] = cnt[i + 1];
            ans[i] = ans[i + 1];
        }
    }

    for (auto s :starts)
        answer.push_back(ans[s]);

    return answer;
}