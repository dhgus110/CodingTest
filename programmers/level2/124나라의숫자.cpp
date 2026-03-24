#include <string>
#include <vector>
#include <algorithm>
#include <stack>
//#include <iostream>

using namespace std;

string Convert(int n){
    string res = " ";
    stack<int> s;
    s.push(n);
    while(s.top() >= 3)
    {
        int top = s.top();
        s.pop();
        
        int quotient = top / 3;
        int remainder = top % 3;
        
        s.push(remainder);
        
        if(quotient != 0) s.push(quotient - 1);
    }
    
    while(!s.empty())
    {
        res += to_string(s.top());
        s.pop();
    }
    
    //cout<< res<<endl;
    
    return res;
}

string solution(int n) {
    string answer = "";
    string convert = Convert(n -1);
    
    for(auto c : convert)
    {
        if(c =='0') answer += "1";
        if(c =='1') answer += "2";
        if(c =='2') answer += "4";
    }
    
    return answer;
}
