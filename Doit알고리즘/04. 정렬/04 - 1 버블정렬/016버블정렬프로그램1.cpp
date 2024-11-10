//백준 1377번
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v(500'001);

void init(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin>> v[i].first;
        v[i].second = i;
    }
}

int run(){
    int max = 0;

    sort(v.begin(),v.begin()+n);

    for(int i = 0 ; i < n ; i++){
        max = max < v[i].second - i ? v[i].second - i : max;
    }
    return max + 1;
}

int main(){
    init();
    cout<< run();
}