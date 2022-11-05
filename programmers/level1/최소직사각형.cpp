#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int oneSideMaxCard[2] = { 0,0 };
    int check = 0;
    //1. ���̰� ���� ū ī�带 ã�´�.
    for (auto s : sizes) {
        if (check < s[0]) { oneSideMaxCard[0] = s[0]; oneSideMaxCard[1] = s[1]; check = s[0]; }
        else if (check < s[1]) { oneSideMaxCard[0] = s[0]; oneSideMaxCard[1] = s[1]; check = s[1]; }
    }

    int minSide = oneSideMaxCard[0] > oneSideMaxCard[1] ? oneSideMaxCard[1] : oneSideMaxCard[0];
    int maxSide = oneSideMaxCard[0] > oneSideMaxCard[1] ? oneSideMaxCard[0] : oneSideMaxCard[1];
    if (oneSideMaxCard[0] == oneSideMaxCard[1]) return oneSideMaxCard[0] * oneSideMaxCard[1];

    //2. ã�� ī�忡�� ��������� ���� ���̸� minSide����Ѵ�.
    // �ٸ� ī���� w,h�� minSide���� �� Ŭ ��� w,h �� ���� ���̸� minSide�� �����Ѵ�.
    for (auto s : sizes) {
        if (minSide < s[0] && minSide < s[1]) minSide = s[0] < s[1] ? s[0] : s[1];
    }
    answer = maxSide * minSide;
    return answer;
}

int solution2(vector<vector<int>> sizes) {
    int answer = 0;
    int w=0 , h = 0;
    for (auto s : sizes) {
        w = max(w, max(s[0], s[1])); // 1. ���� ū ���̸� ����
        h = max(h, min(s[0], s[1])); // 2. �ϳ��� ī�忡�� ���� ���� �߿��� ū ���� ����
    }
    answer = w * h;
    return answer;
}
