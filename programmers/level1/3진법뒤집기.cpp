#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int ternary(int n){ //3진법으로 
    
}

int solution(int n) {
    int answer = 0;
    vector<int> v;

    while(n){
        v.push_back(n % 3);
        n = n / 3;
    }
    reverse(v.begin(),v.end());

    for(int i =0; i <v.size() ; i++){
        answer += v[i]*pow(3,i);
    }

    return answer;
}
