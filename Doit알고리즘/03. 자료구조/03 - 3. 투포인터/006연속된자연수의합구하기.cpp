//백준 2018번

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
}

// 시작지점에 두개의 포인터
int twoPointer(){
    int start = 1, end = 1, sum = 1, cnt = 1; // cnt=1 <- 자기자신

    while (end != n){
        if (sum < n){
            end++;
            sum += end;
        }
        else if(sum > n){
            sum -= start;
            start++;
        }
        else if( sum == n){
            cnt++;
            end++;
            sum += end;
        }
    }

    return cnt;
}

int main(){
    init();
    cout<<twoPointer();

}