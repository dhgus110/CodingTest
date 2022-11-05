#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int oneSideMaxCard[2] = { 0,0 };
    int check = 0;
    //1. 길이가 가장 큰 카드를 찾는다.
    for (auto s : sizes) {
        if (check < s[0]) { oneSideMaxCard[0] = s[0]; oneSideMaxCard[1] = s[1]; check = s[0]; }
        else if (check < s[1]) { oneSideMaxCard[0] = s[0]; oneSideMaxCard[1] = s[1]; check = s[1]; }
    }

    int minSide = oneSideMaxCard[0] > oneSideMaxCard[1] ? oneSideMaxCard[1] : oneSideMaxCard[0];
    int maxSide = oneSideMaxCard[0] > oneSideMaxCard[1] ? oneSideMaxCard[0] : oneSideMaxCard[1];
    if (oneSideMaxCard[0] == oneSideMaxCard[1]) return oneSideMaxCard[0] * oneSideMaxCard[1];

    //2. 찾은 카드에서 상대적으로 작은 길이를 minSide라고한다.
    // 다른 카드의 w,h가 minSide보다 더 클 경우 w,h 중 작은 길이를 minSide에 저장한다.
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
        w = max(w, max(s[0], s[1])); // 1. 가장 큰 길이를 저장
        h = max(h, min(s[0], s[1])); // 2. 하나의 카드에서 작은 길이 중에서 큰 것을 저장
    }
    answer = w * h;
    return answer;
}
