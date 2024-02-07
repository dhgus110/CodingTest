#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//스택
vector<int> solution(vector<int> prices) {
    vector<int >res(prices.size());
    stack <int> s ;
    stack <int> order;
    int sec = prices.size()-1;
    
    for(int i = 0; i<prices.size(); i++){
        res[i]= sec - i;
    }
    order.push(0);
    

    s.push(prices[0]);

    for(int i = 1 ; i <prices.size() ; i++){
        sec--;
        while(!s.empty()&&s.top() > prices[i] ){ //떨어지는 타이밍
            s.pop();
            int cur = order.top();
            order.pop();
            res[cur]-=sec;
        }
        s.push(prices[i]);
        order.push(i);
    }
    return res;
}

// vector<int> solution(vector<int> prices) {
//     vector<int> answer(prices.size(),0);
//     for(int i = 0 ;i<prices.size(); i++){
//         int a =0;
//         for(int j = i+1 ; j<prices.size(); j++){
//             if(prices[i]>prices[j]){
//                 a=1;
//                 answer[i] = j-i;
//                 break;
//             }
//         }
//         if(a==0){
//             answer[i] =prices.size()-i-1;
//         }
//     }

//     return answer;
// }