#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> question;
vector<vector<int>> modify;
vector<bool> isBase(10,true);
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
int nConversion(int nBase, int num)
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

void checkBase()
{
    for(const auto& mo : modify)
    {
        for(int i = maxBase ; i < 10 ; ++i)
        {
            if(!isBase[i]) continue;
            
            int a = tenConversion(i, mo[0]);
            int b = tenConversion(i, mo[2]);
            int c = tenConversion(i, mo[3]);
            if (mo[1] == 1 && a + b != c)  isBase[i] = false;
            else if (mo[1] == -1 && a - b != c) isBase[i] = false;

        }
    }
}

vector<string> run()
{
    vector<string> answer;

    for(const auto& q : question)
    {
        int ans = -1;
        bool isSame = true;
        int base = 0;
        for(int i = maxBase ; i <10 ; ++i)
        {
            if(!isBase[i]) continue;
            base = i;
            int a = tenConversion(i,q[0]);
            int b = tenConversion(i,q[2]);
            int c =  q[1] == 1 ? a + b : a - b;
            c = nConversion(i, c);

            if(ans == -1 ) ans = c;
            else if(ans != c)
            {
                isSame = false;
                break;
            }
            
        }
        string temp = to_string(q[0])+" ";
        temp += q[1] == 1 ? "+ ": "- ";
        temp +=  to_string(q[2])+" = ";
        if(isSame) temp += to_string(ans);
        else temp += "?";

        answer.emplace_back(temp);
    }
    return answer;
}

vector<string> solution(vector<string> expressions) {
    init(expressions);
    checkBase();

    cout<<endl;
      for(int i = maxBase ; i <10 ; ++i)
        if(isBase[i]) cout<<i<<endl;

    return run();
}