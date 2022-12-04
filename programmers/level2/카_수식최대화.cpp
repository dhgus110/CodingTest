#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long cal(long long a, long long b, char op){
    if(op == '*'){
        return a*b;
    }else if(op == '+'){
        return a+b;
    }else{
        return a-b;
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> op;
    long long num = 0;
    for(int i = 0 ; i < expression.length() ; i++){
        char c = expression[i];
        if(c >= '0'&& c <= '9'){
            num = num*10 + c-'0';
        }else{
            op.push_back(c);
            nums.push_back(num);
            num = 0;
        }
    }
    nums.push_back(num);
    
    vector<char> opp = {'*','+','-'};
    do{
        vector<char> tmp_op = op;
        vector<long long> tmp_nums = nums;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < tmp_op.size() ; j++){
                if(tmp_op[j] == opp[i]){
                    tmp_nums[j] = cal(tmp_nums[j],tmp_nums[j+1],tmp_op[j]);
                    tmp_nums.erase(tmp_nums.begin()+j+1);
                    tmp_op.erase(tmp_op.begin()+j);
                    j--;
                }
            }
        }
        if(answer < abs(tmp_nums[0])){
            answer = abs(tmp_nums[0]);
        }
    }while(next_permutation(opp.begin(), opp.end()));
    
    return answer;
}
