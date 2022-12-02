#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; //집의 수
vector<int> M; //집 위치 

int main(){
    cin >> N;
    for(int i =0;i<N;i++){
        int x;
        cin >>x;
        M.push_back(x);

    }
    sort(M.begin(),M.end());

    cout<< M[(N-1)/2];
}