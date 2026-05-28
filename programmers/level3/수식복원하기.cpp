#include <string>
#include <vector>
#include <cctype>

using namespace std;
//n진수 -> 10진수 
int tenConversion(int base, int n)
{
    int res = 0;
    int tempBase = 1;
    while(n > 0)
    {
        res += (n % 10) * tempBase;
        tempBase *= base;
        n /= 10;
    }
    return res;
}
// 10진수 -> n진수
int numConversion(int base, int n)
{
    int res = 0 ;
    int tempBase = 1;
    while(n > 0)
    {
        res += (n % base) * tempBase;
        tempBase *= 10;
        n /= base;
    }
    return res;
}

int checkNumeral(int base, const vector<vector<int>>& expressions)
{
    bool check = true;
    for(const auto& ex : expressions)
    {
        int a = tenConversion(base,ex[0]);
        int b = tenConversion(base,ex[2]);
        int c = tenConversion(base,ex[3]);
        if(ex[1] == 1 && a+b != c) 
        {
            check =false;
            break;
        }
        else if( a-b != c) 
        {
            check = false;
            break;
        }
    }
    if(check) return base;
    else checkNumeral(base+1,expressions);
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    
    vector<vector<int>> question;
    vector<vector<int>> modify;
    int maxValue = 0 ;
    
    for(const string& e : expressions)
    {
        string tempStr="";
        vector<int> tempV;
            
        for(char c : e)
        {
            if(c== ' ' && !tempStr.empty()) {
                tempV.emplace_back(stoi(tempStr));
                tempStr ="";
            }
            else if(c == '+') tempV.emplace_back(1);
            else if(c == '-') tempV.emplace_back(-1);
            else if(c == '=' || c==' ') continue;
            else 
            {
                tempStr += c;
                maxValue = max( maxValue, c - '0');
            }
        }
        if(tempStr == "X")
        {
            question.push_back(tempV);
        }
        else
        {
            tempV.emplace_back(stoi(tempStr));
            modify.push_back(tempV);
        }
    }
    
    int baseNumeral = checkNumeral(maxValue + 1 , modify);
    
    for(const auto& q : question)
    {
        string temp = to_string(q[0])+" ";
        if(q[1] == 1) temp +="+ "+to_string(q[2])+" = ";
        else temp +="- "+to_string(q[2])+" = ";
        
        int a = tenConversion(baseNumeral, q[0]);
        int b = tenConversion(baseNumeral, q[2]);
        int c = q[1] == 1 ? a + b : a-b;
        c = numConversion(baseNumeral, c);
        temp+=(to_string(c));
        answer.emplace_back(temp);
    }
    
    
    return answer;
}