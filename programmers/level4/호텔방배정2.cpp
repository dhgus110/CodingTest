#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map<ll, ll> nxt;  // nxt[n] = n이상 다음 빈 방 후보

ll findNext(ll n)
{
    auto it = nxt.find(n);
    
    while(it != nxt.end())
    {
        auto nit = nxt.find(it->second);
        if( nit != nxt.end()) it->second = nit->second;

        n = it->second;
        it = nxt.find(n);
    }

    return n;
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    answer.reserve(room_number.size());
    nxt.reserve(room_number.size() * 2);

    for(ll n : room_number)
    {
        ll room = findNext(n);
        answer.emplace_back(room);
        nxt[room] = room + 1;
    }

    return answer;
}

/*
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map<ll, ll> parent;  // <child , parent>

ll findParent(ll n)
{
    while(parent[n] != n)
    {
        parent[n] = parent[parent[n]]; 
        n = parent[n];
    }

    return n;
}

void unionParent(ll a, ll b)
{
    ll parentA = findParent(a);
    ll parentB = findParent(b);
    if (parentA == parentB) return;
    if (parentA > parentB) parent[b] = parentA;
    else parent[a] = parentB;
}
vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    answer.reserve(room_number.size());
    parent.reserve(room_number.size() * 2);

    for(ll n : room_number)
    {
        if(parent.find(n) != parent.end())  n = findParent(n) + 1;

        parent[n] = n;
        if (parent.find(n + 1) != parent.end()) unionParent(n, n + 1);
        if (parent.find(n - 1) != parent.end()) unionParent(n, n - 1);

        answer.emplace_back(n);
    }

    return answer;
}
    */