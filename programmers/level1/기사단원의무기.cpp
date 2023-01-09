#include <string>
#include <vector>

using namespace std;

int cnt[100001];

void init(int number) {
    for (int i = 1; i <= number; i++) {
        for (int j = 1; i * j <= number; j++) {
            cnt[i * j]++;
        }
    }
}

int solution(int number, int limit, int power) {
    int answer = 0;

    init(number);

    for (int i = 1; i <= number; i++) {
        if (cnt[i] > limit)
            answer += power;
        else
            answer += cnt[i];
    }

    return answer;
}