#include <vector>

#include <iostream>
#include <algorithm>

using namespace std;

//문제 :  두 배열의 원소 교체
bool compare(int a, int b){
    return a > b;
}

int solution1(int n,int k ,vector<int> a , vector<int> b){
    int answer = 0 ;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), compare);

    for (int i = 0; i < k; i++){
        if(a[i]<b[i]) swap(a[i],b[i]);
        else break; //더 이상 크지 않으면 빠져나감
    }
    for(int i = 0 ; i <n ; i++){
        answer+=a[i];
    }
    return answer;
}

int main(){

}