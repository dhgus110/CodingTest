#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check[100];
int solution(vector<int> cards) {
    int answer = 0;
    vector<int> res;
    queue<int> q;
    for (int i = 0; i < cards.size(); i++) {
        if (check[i]) continue;
        q.push(cards[i] - 1);
        check[i] = true;
        int cnt = 0;
        while (!q.empty()) {
            int  n = q.front();
            q.pop();
            cnt++;
            if (!check[n]) {
                q.push(cards[n] - 1);
                check[n] = true;
            }
        }
        if (cnt != 0)res.push_back(cnt);

    }
    if (res.size() < 2) return 0;
    sort(res.begin(), res.end());
    answer = res[res.size() - 1] * res[res.size() - 2];

    return answer;
}