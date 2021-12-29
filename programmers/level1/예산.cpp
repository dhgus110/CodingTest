#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(),d.end());
    
    for(auto n : d){
        if(budget-n<0)
            break;
        budget-=n;
        answer++;
    }

    return answer;
}