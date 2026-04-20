#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    unordered_map<string, pair<int,string>> group;
    vector<int> money((int)enroll.size(), 0);
    //init
    for(int i = 0 ; i < enroll.size() ; ++i)
    {
        if(referral[i] == "-") 
            group[enroll[i]] = {i, "-"};
        else
            group[enroll[i]] = {i, referral[i]};

    }

    //run
    for(size_t i = 0; i < seller.size() ; ++i)
    {
        int m = amount[i] * 100;
        string name = seller[i];
        while(m >= 1)
        {
            auto it = group.find(name);

            if(it != group.end())
            {
                int curIndex = it->second.first;
                name = it->second.second;

                int parentMoney = m/10;
                
                money[curIndex] += m - parentMoney;
                m = parentMoney;

                if(name == "-") break;
            }
        }
    }

    return money;
}
