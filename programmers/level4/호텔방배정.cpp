#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;
constexpr ll LLNF = LLONG_MAX;

//vector<pair<ll,ll>> rangeNumbers;
map<ll,ll> rangeNumbers;

void updateRange(map<ll,ll>::iterator it)
{
    for(int i = 0 ; i < 2 ; ++i)
    {
        auto it2 = it;
        if(++it2 == rangeNumbers.end()) break;
        if (it->second + 1 == it2->first)
        {
            it->second = it2->second;
            rangeNumbers.erase(it2);
            break;
        }
    }
}

void addNumber(ll n)
{
    auto [it, inserted] = rangeNumbers.emplace(n,n);
    it = it == rangeNumbers.begin() ? it : --it;
    updateRange(it);
}

ll addNumber2(ll n)
{
    auto  it = rangeNumbers.upper_bound(n);
    if(it != rangeNumbers.end())
    {
        --it;
        ll nextNumber = it->second + 1;
        it->second = nextNumber;
        return nextNumber;
    }
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    set<ll> numbers;

    for(ll n : room_number)
    {
        auto it = numbers.find(n);

        if(it == numbers.end())
        {
            numbers.emplace(n);
            answer.emplace_back(n);
            addNumber(n);
        }
        else{
            ll nextNumber = addNumber2(n);
            numbers.emplace(nextNumber);
            answer.emplace_back(nextNumber);
        }

        cout<<n<<endl;
        for(auto p : rangeNumbers)
            cout<<"["<< p.first<<" - "<<p.second<<"]"<<endl;
        cout<<endl;
    }

    return answer;
}

