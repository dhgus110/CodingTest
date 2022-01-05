#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//문제 : 떡볶이 떡 자르기
int solution1(vector<int> rice ,int m){
    int answer = 0;
    sort(rice.begin(),rice.end());
    int start= 0 , end = 1e9 ;
    int size = rice.size();

    while(1){
        long long int total =0;
        int mid = (start+end) /2;
        for(int i = 0; i <size ;i++){
            if( rice[i]> mid) total += rice[i];
        }
        if(total < m) end = mid -1;
        else
        {
            answer =mid;
            start = mid + 1;
        }
    }
}

//정렬된 배열에서 특정 수의 개수 구하기
int solution2(vector<int> n ,int x){
    int answer =0;
    int start;
    int end;

    start = lower_bound(n.begin(), n.end(), x) - n.begin(); //데이터 x가 첫 번째로 나오는 위치
    end = upper_bound(n.begin(), n.end(), x) - n.begin();  //데이터 x가 처음으로 초과되는 위치 
    answer = end-start;
    return answer;
}


int main(){

}