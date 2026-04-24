#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, pair<int,int>> mp; // m[보석] = {인덱스, 갯수}
    mp.reserve(100'001);

    int index = 0;
    for(const auto& gem : gems)
    {
        if(mp.count(gem)==0)
        {
            mp[gem] = {index++, 0};
        }
    }
    
    int gemCnt = mp.size();
    int curGemTypeCnt = 0, numCnt = 0;
    int maxNumCnt = 100'001;
    int l = 0, r = 0;
    bool isR = true;
    pair<int,int> minIndex;

    while(l < gems.size())
    {
        if(isR && r < gems.size())
        {
            if(mp[gems[r]].second ==0) ++curGemTypeCnt;
            ++mp[gems[r]].second;
            ++numCnt;

            if(curGemTypeCnt == gemCnt)
            {
                if(maxNumCnt > numCnt)
                {
                    maxNumCnt = numCnt;
                    minIndex = {l,r};
                }
                isR = false;
            }

            ++r;
        }
        else
        {
            if( l == r)
            {
                isR = true;
                continue;
            }

            --mp[gems[l]].second;

            if(mp[gems[l]].second == 0)
            {
                if(curGemTypeCnt == gemCnt && maxNumCnt > numCnt)
                {
                    maxNumCnt = numCnt;
                    minIndex = {l,r - 1};
                }
                isR = true;
                --curGemTypeCnt;
            }

            --numCnt;
            ++l;
        }
    }

    answer.emplace_back(minIndex.first+1);
    answer.emplace_back(minIndex.second+1);

    return answer;
}
