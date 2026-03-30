#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    
    for( char c : s)
    {
        if(!st.empty())
        {
            if(st.top() == c)
                st.pop();
            else
                st.emplace(c);
        }
        else
            st.emplace(c);
    }

    if(st.empty())
        return 1;
    else
        return 0 ;
}