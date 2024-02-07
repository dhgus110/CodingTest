#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#define BIG 1000001;

using namespace std;

//기본 알고리즘 문제
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(auto  ball : balls){
        int curx = ball[0];
        int cury = ball[1];
        int re1 =BIG;int re2=BIG;int re3=BIG;int re4=BIG;

        //up&down
        if (startX != curx)
        {
            re1 = pow(abs(startX - curx), 2) + pow(n - startY + n - cury, 2);
            re2 = pow(abs(startX - curx), 2) + pow(startY + cury, 2);
        }
        else
        {
            if (startY > cury)
                re1 = pow(abs(startX - curx), 2) + pow(n - startY + n - cury, 2);
            else
                re2 = pow(abs(startX - curx), 2) + pow(startY + cury, 2);
        }

        //left&right
        if (startY != cury)
        {
            re3 = pow(startX + curx, 2) + pow(abs(startY - cury), 2);
            re4 = pow(m - startX + m - curx, 2) + pow(abs(startY - cury), 2);
        }
        else
        {
            if (startX < curx)
                re3 = pow(startX + curx, 2) + pow(abs(startY - cury), 2);
            else
                re4 = pow(m - startX + m - curx, 2) + pow(abs(startY - cury), 2);
        }

        int minNum = min(re4,min(re3,min(re1,re2)));
        answer.push_back(minNum);
    }

    return answer;
}
