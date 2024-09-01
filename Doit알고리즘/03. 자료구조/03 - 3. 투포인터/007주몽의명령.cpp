//백준 1940번

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n , m;
vector<int> v;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0 ; i<n ; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
}

//시작지점과 끝지점에 포인터
int twoPointer(){
    int start = 0, end = n - 1, cnt = 0;

    while(start < end){
        int sum = v[start] + v[end];
        if( sum == m){
            cnt++;
            start++;
            end--;
        }
        else if( sum > m){
            end--;
        }
        else if( sum < m){
            start++;
        }
    }
    return cnt;
}


int main(){
    init();
    sort(v.begin(), v.end());

    cout<<twoPointer();

}