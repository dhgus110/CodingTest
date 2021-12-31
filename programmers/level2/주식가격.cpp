#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    for(int i = 0 ;i<prices.size(); i++){
        int a =0;
        for(int j = i+1 ; j<prices.size(); j++){
            if(prices[i]>prices[j]){
                a=1;
                answer[i] = j-i;
                break;
            }
        }
        if(a==0){
            answer[i] =prices.size()-i-1;
        }
    }

    return answer;
}