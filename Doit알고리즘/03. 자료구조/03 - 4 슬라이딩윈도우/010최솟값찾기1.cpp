//백준 11003번
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<pair<int,int>> n;
    int size ,slidingWindowSize;
    cin >> size >> slidingWindowSize;

    for (int i = 0; i < size; i++){
        int now ;
        cin >> now;

        //값이 들어올 때마다 정렬 x
        //현재 수보다 큰 값을 덱에서 제거하여 시간 복잡도를 줄임
        while (!n.empty() && n.back().first > now){
            n.pop_back();
        }
        
        n.push_back(make_pair(now, i));

        //범위에서 벗어나면 제거 
        if(n.front().second<= i-slidingWindowSize){
            n.pop_front();
        }

        //정답 출력
        cout << n.front().first << ' ';
    }
}