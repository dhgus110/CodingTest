#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

/*
    도달 가능한 최대 라운드를 구해야함. 
    어차피 조합 못 찾으면 끝
    매 라운드마다 코인을 소모하든 안하든 어떻게든 조합을 찾아야함. 
    중복되지 않는 카드 -> 같은 카드로 여러 조합수 못 만듦
*/

int solution(int coin, vector<int> cards) {
    int answer = 1;
    int cardSize = cards.size();
    int correct = cards.size() + 1;
    int index = cards.size() / 3;

    unordered_set<int> myCards(cards.begin(), cards.begin() + index);
    unordered_set<int> picked;

    while (!myCards.empty())
    {

        bool found =false;
        int next1, next2;
        if (index < cardSize - 1)
        {
            next1 = cards[index++];
            next2 = cards[index++];
        }

        picked.emplace(next1);
        picked.emplace(next2);

  
        for(int x : myCards)
        {
            int y = correct - x;
            if( y <= 0 || y == x) continue;

            // [myCards, myCards]
            if( myCards.count(y))
            {
                myCards.erase(x);
                myCards.erase(y);
                ++answer;
                found = true;
                break;
            }
        }
        if(found) continue;

        // 카드 하나 선택 [myCards,picked]
        if (coin >= 1)
        {
            for (int x : myCards)
            {
                int y = correct - x;
                if (y <= 0 || y == x)  continue;

                if (picked.count(y))
                {
                    myCards.erase(x);
                    picked.erase(y);
                    --coin;
                    ++answer;
                    found = true;
                    break;
                }
            }
        }
        if(found) continue;

        // 카드 2개 선택
        //[myCards, myCards], [myCards, picked]에서 조합이 없었으므로 [picked, picked]
        if (coin >= 2)
        {
            for (int x : picked)
            {
                int y = correct - x;
                if (y <= 0 || y == x)
                    continue;

                if (picked.count(y))
                {
                    picked.erase(x);
                    picked.erase(y);
                    coin-=2;
                    ++answer;
                    found = true;
                    break;
                }
            }
        }
        if(found) continue;
        else break;
    }

    return answer;
}