#include <string>
#include <vector>
#include <iostream>

#define INF 1e9
using namespace std;

int d[3] = { 2,3,0 };
int map[1'000'001];
int minCnt = INF;

void calculation(int x, int y, int cnt) {

    if (x > y || cnt > minCnt)
        return;
    if (x == y) {
        minCnt = minCnt > cnt ? cnt : minCnt;
        return;
    }
   
    for (int i = 0; i < 3; i++) {
        int curX = x;
        if (i == 2) curX += d[i];
        else curX *= d[i];
        cout <<"cnt :"<<cnt<<(i==2?" +":" *")<<d[i]<<" -> "<< curX << endl;
        calculation(curX, y, cnt + 1);
    }
}

int solution(int x, int y, int n) {
    int answer = 0;
    d[2] = n;
    fill_n(map, 1'000'001, INF);

    calculation(x, y, 0);
    answer = minCnt != INF ? minCnt : -1;
    return answer;
}