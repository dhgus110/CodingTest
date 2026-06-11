#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string,int> compress;

void init()
{
    for(int i = 1 ; i < 27 ; ++i)
    {
        string str ="-";
        str[0] = char(i+ 'A' -1);
        compress.emplace(str, i);
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    int msgSize = msg.size();
    int curIndex = 0;
    int compressIndex = 27;

    init();

    while(curIndex <= msgSize)
    {
        int nextIndex = curIndex + 1;
        string temp ="";
        temp = msg[curIndex];

        bool findFlag = true; 
        while(nextIndex < msgSize)
        {
            temp += msg[nextIndex];
            if(compress.find(temp) == compress.end())
            {
                compress.emplace(temp, compressIndex);
                ++compressIndex;

                temp.pop_back();
                answer.emplace_back(compress[temp]);

                findFlag = false;
                break;
            }
            else 
                ++nextIndex;
        }

        if(findFlag)
        {
            answer.emplace_back(compress[temp]);
            break;
        }

        curIndex = nextIndex;
    }

    return answer;
}