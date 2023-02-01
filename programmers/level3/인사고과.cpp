#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//근무 태도 점수(v[0])는 내림차순 동료 평가 점수(v[1])는 오름차순정렬
bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}
int solution(vector<vector<int>> scores) {
    int answer = 1;
    auto pivot = scores[0];
    int pivotValue = scores[0][0] + scores[0][1];
    sort(scores.begin(), scores.end(), cmp);
    int max = 0;

    // 내 앞에 동료평가점수가 나보다 높은사람이 한명이라도 있으면 탈락 (max로 판별)
    // 근무태도 동점자의 경우 동료평가 오름차순 하였으므로 고려하지 않아도 됨
    for (auto s : scores) {
        if (s[0] > pivot[0] && s[1] > pivot[1])
            return -1;
        if (s[0] + s[1] > pivotValue && max <= s[1]) {
            answer++;
            max = s[1];
        }
    }
    return answer;
}