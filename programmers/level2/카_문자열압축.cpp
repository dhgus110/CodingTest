#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s)
{
    int answer = s.size();
    // int count = 0;
    // int prise = s.size();
    // bool hit = false;

    if(s.length() == 1)
        return 1;

    for (int i = 1; i < s.size() / 2 + 1; i++)  
    {
        int count = 1;
        string origin = s.substr(0, i);
        string next, clone;

        for (int j = i; j < s.size() ; j += i) 
        {
            next = s.substr(j, i);
            if (!(origin.compare(next))) //같으면
            {
                count++;
            }
            else
            {
                if (count == 1)
                {
                    clone += origin;
                    origin = next;
                }
                else
                {
                    clone += to_string(count) + origin;
                    origin = next;
                    count = 1;
                }
            }
            if (i + j >= s.size())
            {
                if (count > 1)
                {
                    clone += to_string(count) + origin;
                    break;
                }
                else
                {
                    clone += s.substr(j);
                    break;
                }
            }
        }
        // cout<<" i : "<<i<<" , clone : "<<clone<<endl;
        answer = (answer > clone.length()) ? clone.length() : answer;
    }
    
    return answer;
}