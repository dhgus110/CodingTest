#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//97 ~ 122
string solution(string s, string skip, int index)
{
    string answer = "";

    for (auto c : s)
    {
        char re = c;
        for (int i = 0; i < index; i++)
        {
            if (re == 'z')
                re = 'a';
            else
                re += 1;
            auto it = find(skip.begin(), skip.end(), re);
            if (it != skip.end())
            {
                i -= 1;
            }
        }
        answer.push_back(re);
    }

    return answer;
}