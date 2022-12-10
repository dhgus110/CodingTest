#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    multiset<int, greater<int>> s;

    for (int i = 0; i < enemy.size(); i++)
    {
        //막을 수 있는 경우
        if ((n - enemy[i]) >= 0)
        {
            n-=enemy[i];
            s.insert(enemy[i]);
        }
        else if((n - enemy[i]) < 0 && k>0) //막을 수 없지만 무적권표가 있을 경우
        {
            k--;
            if (!s.empty())
            {
                s.insert(enemy[i]);
                auto iter = s.begin();
                n += *iter;
                s.erase(iter);
                n -= enemy[i];
            }
        }
        else{
            return i;
        }
    }

    return enemy.size();
}