#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define INF 1e9
using namespace std;

int d[3] = { 0,2,3 };
int map[1'000'001];

//1번째 풀이 방법 :  y 이하의 나올 수 있는 모든 수를 탐색 <- 통과 되지만 너무 느리다(중복된 값들이 많음)
void calculation(int x, int y, int cnt) {
    if (x > y || map[x] < cnt || map[y] < cnt)return;
    map[x] = cnt;
    for (int i = 0; i < 3; i++) {
        int curX = x;
        if (i == 0) curX += d[i];
        else curX *= d[i];
        calculation(curX, y, cnt + 1);
    }
}

int solution(int x, int y, int n) {
    int answer = 0;
    d[0] = n;
    fill_n(map, 1'000'001, INF);
    calculation(x, y, 0);
    for (int i = 0; i < 41; i++) { cout << map[i] << " "; if (i % 10 == 0)cout << endl; }
    answer = map[y] != INF ? map[y] : -1;
    return answer;
}

//2번째 풀이 방법 : y부터 시작해서 나누기/빼기로 x까지 가게끔
int solution2(int x, int y, int n) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, 0));
    while (!q.empty())
    {
        int val = q.front().first;
        int count = q.front().second;
        q.pop();

        if (val == x)
            return count;

        if (val % 2 == 0)
        {
            q.push(make_pair(val / 2, count + 1));
        }

        if (val % 3 == 0)
        {
            q.push(make_pair(val / 3, count + 1));
        }

        if (val - n > 0)
        {
            q.push(make_pair(val - n, count + 1));
        }
    }

    return -1;
}

//3번째 풀이 방법 :i에 관해 x부터 y 까지 1씩 증가 시키면서 연산 된 테이블 값을 비교
int solution3(int x, int y, int n) {
    int answer = 0; 
    fill_n(map, 1'000'001, INF);
    map[x] = 0;

    for (int i = x; i <= y; i++) {
        if (i + n <= y) map[i + n] = min(map[i + n], map[i] + 1);
        if (i * 2 <= y) map[i * 2] = min(map[i * 2], map[i] + 1);
        if (i * 3 <= y) map[i * 3] = min(map[i * 3], map[i] + 1);
    }
    answer = map[y] != INF ? map[y] : -1;
    return answer;
}
