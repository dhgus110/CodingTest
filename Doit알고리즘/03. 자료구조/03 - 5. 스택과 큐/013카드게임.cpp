//백준 2164번
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
queue<int> q;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++){
        q.push(i);
    }
}

void run(){
    int cnt = N;
    while(cnt != 1){
        q.pop();
        int dummy = q.front();
        q.pop();
        q.push(dummy);
        cnt--;
    }
}

int main(){
    init();
    run();
    cout << q.front();
}