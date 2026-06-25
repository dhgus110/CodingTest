#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

map<ll,ll> rangeNumbers;

void updateRange(map<ll,ll>::iterator curIt)
{
    if (rangeNumbers.size() <= 1) return;

    bool prevRun = false , nextRun = false;
    auto prevIt = curIt , nextIt = curIt;

    if(curIt == rangeNumbers.begin())
    {
        ++nextIt;
        nextRun = true;

    }
    else if ( curIt == prev(rangeNumbers.end()))
    {
        --prevIt;
        prevRun = true;
    }
    else{
        --prevIt;
        ++nextIt;
        prevRun = true;
        nextRun = true;
    }

    bool prevFlag =false, nextFlag = false;

    if(prevRun && prevIt->second + 1 == curIt->first)
    {
        prevFlag = true;
        prevIt->second = curIt->second;
    }
    if(nextRun && curIt->second + 1 == nextIt->first)
    {
        nextFlag = true;
        curIt->second = nextIt->second;
    }

    if(prevFlag && nextFlag)
    {
        prevIt->second = curIt->second;
        rangeNumbers.erase(curIt);
        rangeNumbers.erase(nextIt);
    }
    else if(prevFlag) rangeNumbers.erase(curIt);
    else if(nextFlag) rangeNumbers.erase(nextIt);
}

ll addNumber(map<ll,ll>::iterator& prevIt)
{
    ll nextNumber = prevIt->second + 1;
    prevIt->second = nextNumber;

    if (prevIt != prev(rangeNumbers.end()))
        updateRange(prevIt);

    return nextNumber;
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    answer.reserve(room_number.size());

    for(ll n : room_number)
    {
        auto  it = rangeNumbers.upper_bound(n);
        bool used = false;

        if (it != rangeNumbers.begin())
        {
            auto prevIt = prev(it);
            if (prevIt->first <= n && n <= prevIt->second) {
                 answer.emplace_back(addNumber(prevIt));
                continue;
            }
        }

        //바로 삽입
        auto newIt = rangeNumbers.emplace_hint(it, n, n);
        updateRange(newIt);

        answer.emplace_back(n);

        // cout<<n<<endl;
        // for(auto p : rangeNumbers)
        //     cout<<"["<< p.first<<" - "<<p.second<<"]"<<endl;
        // cout<<endl;
    }

    return answer;
}

