#include <string>
#include <vector>
#include <iostream>
using namespace std;
string stage1(string s);
string stage2(string s);
string stage3(string s);
string stage4(string s);
string stage5(string s);
string stage6(string s);
string stage7(string s);
string frontperiod(string s);
string backperiod(string s);


string solution(string new_id)
{
    string answer = "";
    answer = stage1(new_id);
    answer = stage2(answer);
    answer = stage3(answer);
    answer = stage4(answer);
    answer = stage5(answer);
    answer = stage6(answer);
    answer = stage7(answer);
    return answer;
}
string stage1(string s)
{
    for (int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    return s;
}
string stage2(string s)
{
    for (int i = 0; i < s.size(); )
        if (s[i] != '.' && s[i] != '-' && s[i] != '_' && !isalpha(s[i]) && !isdigit(s[i]))
            s.erase(s.begin() + i);
        else
            i++;
    return s;
}
string stage3(string s)
{
    for (int i = 0; i < s.size() - 1;){
        if (s[i] == '.' && s[i + 1] == '.')
            s.erase(s.begin() + i + 1);   
        else
            i++;}
    return s;
}
string stage4(string s)
{
    // string tmp="";
    // tmp = frontperiod(s);
    // backperiod(tmp);
    if (s.front() == '.')
        s.erase(s.begin() + 0);
    if (s.back() == '.')
        s.pop_back();
    return s;
}
string stage5(string s)
{
    if (s.empty())
        s = "a";
    return s;
}
string stage6(string s)
{
    if (s.size() >= 16)
        s.erase(15, s.size() - 15);
    while (s.back() == '.')
        s.pop_back();
    return s;
}
string stage7(string s)
{
    if (s.size() < 3)
        for (int i = 0; i <= 3 - s.size(); i++)
            s.push_back(s.back());
    return s;
}
string frontperiod(string s)
{
    if (s.front() == '.')
        s.erase(s.begin()+0);
    return s;
}
string backperiod(string s)
{
    if (s.back() == '.')
        s.pop_back();
    return s;
}
//. 46
//- 45
//_ 95
//A~Z  65~90
//a~z 97~122