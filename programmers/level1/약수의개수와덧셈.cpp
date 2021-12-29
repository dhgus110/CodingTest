#include <string>
#include <vector>
#include <iostream>
using namespace std;
int a(int n){
    int cnt=1;
    int clone = n;
    for(int i =1 ; i < clone ; i++){
        if(clone%i == 0 ){
            cnt++;
        }
    }
    if(cnt%2 ==0) return n;
    else return (-1)*n; 
}
int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i<right+1 ; i++){
        answer +=a(i);
    }
    return answer;
}

int main(){
    solution(13,17);
}