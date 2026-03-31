#include <string>
#include <cctype>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string str1, string str2)
{
    int interCnt = 0;
    int unionCnt = 0;
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;

    string temp1, temp2;
    for (int i = 0; i < str1.size() - 1; ++i)
    {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1]))
            continue;
        temp1 = "";
        temp1 += tolower(str1[i]);
        temp1 += tolower(str1[i + 1]);
        ++m1[temp1];
    }

    for (int i = 0; i < str2.size() - 1; ++i)
    {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1]))
            continue;
        temp2 = "";
        temp2 += tolower(str2[i]);
        temp2 += tolower(str2[i + 1]);
        ++m2[temp2];
    }

    for(auto it = m2.begin() ; it != m2.end() ; ++it)
    {
        if( m1.find(it->first) == m1.end()) unionCnt += it->second; //m1에 없는 m2
    }

    for (auto it = m1.begin(); it != m1.end(); ++it)
    {
        auto it2 = m2.find(it->first);
        if (it2 != m2.end())
        {
            interCnt += min(it->second, it2->second);
            unionCnt += max(it->second, it2->second);
        }
        else
            unionCnt += it->second; // m2에 없는 m1
    }

    if (unionCnt == 0)
        return 65536;

    float jaccard = ((float)interCnt / (float)unionCnt) * 65536.f;
    if (jaccard > 65536)
        jaccard = 65536;
    return (int)jaccard;
}