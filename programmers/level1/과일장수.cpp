#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    if (score.size() < m) return 0;
    sort(score.begin(), score.end(), greater<>());

    for (int i = 1; i <= score.size() / m; i++) {
        answer += (score[m * i - 1] * m);
    }

    return answer;
}