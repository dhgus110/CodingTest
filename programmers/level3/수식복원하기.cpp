#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> question;
vector<vector<int>> modify;
vector<bool> isBase(10,false);
int maxBase = 0;

void init(const vector<string>& expresstions)
{
    for(const string& ex : expresstions)
    {
        vector<int> tempV;
        string tempStr = "";
        bool isQuestion = false;
        for(char e : ex)
        {
            int num = e -'0';
            if(e==' ' && !tempStr.empty()){
                tempV.emplace_back(stoi(tempStr));
                tempStr = "";
            }
            else if( e == '+')tempV.emplace_back(1);
            else if( e == '-') tempV.emplace_back(-1);
            else if(0 <= num && num <=9 ){
                tempStr += e;
                maxBase = max(maxBase, num);
            }
            else if(e == 'X') isQuestion = true;
        }
        if(isQuestion)
            question.emplace_back(tempV);
        else{
            tempV.emplace_back(stoi(tempStr));
            modify.emplace_back(tempV);
        }
    }

    ++maxBase;
}

// n -> 10
int tenConversion(int nBase, int num)
{
    int res = 0;
    int multi = 1;

    while( num > 0)
    {
        res += (num % 10) * multi;
        multi *= nBase;
        num /= 10;
    }
    return res;
}

//10 -> n
int nConvertion(int nBase, int num)
{
    int res = 0;
    int multi = 1;
    while( num > 0)
    {
        res +=(num % nBase) * multi;
        multi *= 10;
        num /= nBase;
    }
    return res;
}

void checkBase(int base, int num)
{

}

void run()
{
    for(const auto& mo : modify)
    {
        for(int i = 2 ; i <10 ; ++i)
        {
            if(isBase[i]) continue;
            
        }
    }
}


vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    init(expressions);


    return answer;
}