/*
    문자열이 주어졌을 때  (1차원 배열)
    문자열에서 순차적 삽입이 베이스로 이루어지면서
    그 후 중간 삽입 및 삭제 가능 해야함. (뒤 요소들은 유지)
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string run(string temp)
{
   stack<char> front;
   stack<char> back;

   for(char c : temp)
   {
        if(c == '<')
        {
            if(!front.empty())
            {
                back.emplace(front.top());
                front.pop();
            }
        }
        else if ( c == '>')
        {
            if (!back.empty())
            {
                front.emplace(back.top());
                back.pop();
            }
        }
        else if ( c == '-')
        {
            if(!front.empty())
                front.pop();
        }
        else
        {
            front.emplace(c);
        }
   }

   string res1 = "", res2 = "";
   while(!front.empty())
   {
        res1 += front.top();
        front.pop();
   }
   while(!back.empty())
   {
        res2+= back.top();
        back.pop();
   }
   reverse(res1.begin(),res1.end());
  // reverse(res2.begin(),res2.end());

   return res1 + res2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; ++i)
    {
        string temp;
        cin >> temp;
        cout << run(temp) << '\n';
    }
}
