#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack <int> stack ;

    for( auto c : s ){
        if(c =='(') stack.push(1);
        else
        {
            if(stack.empty()) return false;
            stack.pop();
        }
    }
    if( stack.empty()) return true;
    else return false;
}