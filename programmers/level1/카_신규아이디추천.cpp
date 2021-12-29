#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
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
*/

//1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
// 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
// 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
// 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
// 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//      만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
// 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

string step1(string s){
    for(int i = 0; i<s.size();i++){
        s[i] = tolower(s[i]);
    }
    return s;
}
string step2(string s){
    for(int i =0; i<s.size();){
        if(s[i]!='-' && s[i]!='_' && s[i]!='.' && !isalpha(s[i]) && !isdigit(s[i]))
            s.erase(s.begin()+i);
        else
            i++;
    }
    return s;
}
string step3(string s){
    for(int i=0 ; i<s.size()-1 ;){
        if(s[i]=='.' && s[i+1]=='.')
            s.erase(s.begin()+i+1);
        else
            i++;
    }
    return s;
}
string step4(string s){
    if(s.front()=='.')
        s.erase(s.begin());
    if(s.back()=='.')
        s.erase(s.begin()+s.size()-1);
    return s;
}
string step5(string s){
    if(s.empty())
        s.push_back('a');
    return s;
}
string step6(string s){
    if(s.size()>15)
        s.erase(15,s.size()-15);
    s = step4(s);
    return s;
}
string step7(string s){
    if (s.size()==1){
        s.push_back(s[0]);
        s.push_back(s[0]);
    }
    else if(s.size()==2)
     s.push_back(s[1]);
    return s;
}
string solution(string new_id) {
    string answer = "";
    answer = step1(new_id); cout<<answer<<endl;
    answer = step2(answer); cout<<answer<<endl;
    answer = step3(answer); cout<<answer<<endl;
    answer = step4(answer); cout<<answer<<endl;
    answer = step5(answer); cout<<answer<<endl;
    answer = step6(answer); cout<<answer<<endl;
    answer = step7(answer); cout<<answer<<endl;
    return answer;
}

int main(){
    string s ="abcdefghijklmn.p";
    solution(s);
}