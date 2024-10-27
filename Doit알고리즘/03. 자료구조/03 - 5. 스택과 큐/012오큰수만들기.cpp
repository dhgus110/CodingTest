//백준 17298번
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int progressionSize;
int n[1'000'000];
int result[1'000'000];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> progressionSize;
    for(int i = 0 ; i < progressionSize ; i++){
        cin >> n[i];
    }
}

void run(){
    stack<int> s;
    s.push(0);

    for (int i = 1; i < progressionSize; i++){
        while (!s.empty() && n[s.top()] < n[i]){
            result[s.top()] = n[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        result[s.top()] = -1;
        s.pop();
    }
}

void print(){
    for (int i = 0; i < progressionSize; i++){
        cout << result[i] << " ";
    }
}

int main(){
    init();
    run();
    print();
}