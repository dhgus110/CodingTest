//백준 10986번

#include <string>
#include <vector>
#include <iostream>
#define ll long long

using namespace std;

int N, M;
vector<ll> remainderCnt;

void init(){
    cin >> N >> M;
    remainderCnt.resize(M, 0);

    ll sum = 0;

    for (int i = 1; i <= N; i++){
        int temp = 0;
        cin >> temp;
        sum += temp;
        remainderCnt[sum % M]++;
    }

}
//1. 0~i구간은 나머지가 0인 원소를 구하면 됨
//2. i~j구간은 나머지가 같은 원소 2개를 뽑으면 M으로 나눴을 때 딱 떨어지는 구간이다.(조합)
void solution(){
    // 1.
    ll answer = remainderCnt[0];

    // 2.
    for (int i = 0; i < M; i++){
        if(remainderCnt[i] > 1)
            answer += (remainderCnt[i] * (remainderCnt[i] - 1)) / 2;
    }

    cout << answer << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();
}