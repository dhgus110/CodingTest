#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#define ll long long

using namespace std;

ll f(ll num) {
    ll  n = num;
    string bit = "";
    while (n >= 1) {
        bit.push_back(n % 2 + '0');
        n /= 2;
    }
    string bit2(bit.rbegin(), bit.rend());
    auto firstZero = bit2.find('0');
    if (firstZero != string::npos) {
        bit2[firstZero] = '1';
        bit2[firstZero + 1] = '0';
    }
    else {
        bit2.insert(1, "0");
    }

    ll re = 0;
    int e = 0;
    for (int i = bit2.length() - 1; i >= 0; i--) {
        re += (bit2[i] - '0') * pow(2, e++);

    }

    return re;
}

vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;

    for (auto n : numbers) {
        if (n % 2 == 0)
            answer.push_back(n + 1);
        else {
            answer.push_back(f(n));
        }
    }

    return answer;
}