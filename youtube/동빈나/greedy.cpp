#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

//문제 : 1이 될 때 까지
int solution1(int N, int k){ 
    int num = N;
    int cnt = 0;
    while(1){
        //num이 k로 나누어 떨어지는 수가 될 때까지
        int target = (num/k) *k ;
        cnt += num - target;
        num = target;

        //num이 k 보다 잡아지면 나가기
        if(num <k ) break;

        //딱 나눌 수 있으면 나누고 cnt증가
        num /= k;
        cnt++;
    }
    //남아있는 num 처리
    cnt += num-1;

    return cnt;
}

//문제 : 곱하거나 더하기
int solution2 (string s){

    long long pivot = s[0]-'0';
    for(int i = 1 ; i<s.size();i++){
        int target = s[i]-'0';
        if (pivot <=1 || target <=1)
            pivot += target;
        else
            pivot *= target;
    }

    return pivot;
}

//문제 : 모험가 길드
int solution3(vector<int> adventurer){
    int person = adventurer.size();
    sort(adventurer.begin(), adventurer.end());
    int cnt = 1; //현재 길드의 모험가 수
    int teamCnt =0; //총 길드 수

    for(int i = 0 ; i<person ;i++){
        //현재 길드의 모험가 수와 i에 해당하는 모험가의 공포도가 같으면 
        if(cnt == adventurer[i]){
            teamCnt++;
            cnt = 1;
        }
        else
            cnt++;
    }
    return teamCnt;

}

int main(){
    cout << solution1(26, 3) << endl;


    system_clock::time_point start = system_clock::now();

    cout<<solution2("01011159602369093959932105223211232100121211123566934115152124453252435141112352509012")<<endl;

    system_clock::time_point end = system_clock::now();
    nanoseconds nano = end - start;
    microseconds micro = chrono::duration_cast<chrono::microseconds>(end - start);
    milliseconds mill = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout<<"측정 시간: "<<nano.count()<<endl;  //10억 분의 1     1,000,000,000
    cout<<"측정 시간: "<<micro.count()<<endl; //100만 분의 1    1,000,000
    cout<<"측정 시간: "<<mill.count()<<endl;  //1000 분의 1     1,000

    cout<<solution3({1,2,2,3,4,5,5,5,5,5,6,6,6,6})<<endl;

}