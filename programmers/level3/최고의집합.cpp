/*
집합에서 원소의 갯수는 N
각 원소의 합이 S가 되는 수의 집합
위 조건을 만족하면서 각 원소의 곱 이 최대가 되는 집합

-> 정정당당하게 나누기. 
    각 원소가 가장 중간일수록 곱이 큼
    ex) n = 4 , s = 16
        답 : {4, 4, 4, 4}

*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n > s)
        return {-1};
    
    int pivot = s/n;
    int cnt = s%n;
    
    vector<int> answer(n, pivot);
    
    for(int i = n - 1 ; cnt != 0 ; --i)
        {
            ++answer[i];
            --cnt;
        }
    
    return answer;
}

