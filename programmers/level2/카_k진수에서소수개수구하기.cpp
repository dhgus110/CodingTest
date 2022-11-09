#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string convert(int n, int k) {
    string res = "";
    while (true) {
        res.push_back((char)(n % k + 48));
        if (n <= k) 
        {
            if( n!=k) res.push_back((char)(n / k + 48));
            break;
        }
        n /= k;
    }
    //res ������
    reverse(res.begin(), res.end());
    return res;
}

vector<long long> divide(string s) {
    vector<long long> res;
    string dummy = "";
    for (auto c : s) {
        if (c == '0') {
            if (!dummy.empty() && dummy != "1") res.push_back(stoll(dummy));
            dummy = "";
        }
        else
            dummy += c;
    }
    if (!dummy.empty() && dummy != "1") res.push_back(stoll(dummy));

    return res;
}

bool checkIsPrimeNumber(long long num) {
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; //num�� i�� ����� �Ҽ��� �ƴϹǷ� false
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    vector<long long> setNum = divide(convert(n, k));
    cout << "���� : " << convert(n, k)<<endl;
    cout << "���� : ";
    for (auto s : setNum) {
        
        if (checkIsPrimeNumber(s)) { answer++; cout << "@"; }
        cout << s << " ";
    }

    return answer;
}
