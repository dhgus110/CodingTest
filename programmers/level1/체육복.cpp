#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;
//n-전체 학생 수 ,lost -도난 당한 번호 , reserve - 여벌 번호
int solution(int n, vector<int> lost, vector<int> reserve) {  
    int answer = 0;
    vector<int> student(n);

    for(int l : lost) student[l-1]--;
    for(int r : reserve) student[r-1]++;
    for(int i=0; i<n;i++){
        if(student[i]<0){
            if(i>0 && student[i-1]>0){
            student[i]++; student[i-1]--;}
            if(i<n-1 && student[i+1]>0){
            student[i]++; student[i+1]--;}
        }
    }
    for(int s : student){
        if(s>=0)
        answer++;
    }
    return answer;
}   

int main(){
    vector<int> lost ={1,2,3,4,5,60};
    vector<int> reserve ={3,1,5,6,9,10};

    int i = solution(20,lost,reserve);
    for(int i : lost){
    cout<< i<<" "<<lost[i]<<endl;}
}