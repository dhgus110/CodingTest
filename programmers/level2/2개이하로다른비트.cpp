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
    auto firstZero = bit.find('0'); //가장 오른쪽에 나오는 0의 자리
    if (firstZero != string::npos) {
        ll temp = pow(2, firstZero);
        n = num + temp - temp / 2;
    }
    else {
        ll temp = pow(2, bit2.length());
        n = num + temp - temp / 2;
    }

    return n;
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

//input data를 2진수 변환했을때 가장 먼저 나오는 0의 자리를 1로 나머지는 0으로
//이 숫자를 input data에 더하고 이 숫자를 / 2 한 값을 빼주시면 됩니다.

//ex)  111 -> 111 + 1000 - 10
//ex)  101 -> 101 + 10 - 1
//ex)  101001101 -> 101001101 + 10 - 1

