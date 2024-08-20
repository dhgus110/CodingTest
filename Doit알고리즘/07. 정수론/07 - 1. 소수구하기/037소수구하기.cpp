//백준 1929번

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    int i = 0;
    vector<int> v(n + 1);

    for (int i = 0; i <= n; i++){
        v[i] = i;
    }

    //소수 구하기
    //제곱근까지만 수행
    for (int i = 2; i < sqrt(n); i++){
        if(v[i]==0) continue;
        //배수 지우기
        for (int j = i + i; j <= n; j = j + i){
            v[j] = 0;
        }
    }

    for (int i = m; i <= n; i++){
        if (v[i] != 0) cout<<v[i]<<endl;
    }
}