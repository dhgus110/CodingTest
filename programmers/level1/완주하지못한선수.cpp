#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
/*
string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    map<string, int> map;
    for (auto c : completion)
    {
        map[c] += 1;
    }
    for (auto p : participant)
    {
        map[p] -= 1;
        if (map[p] < 0)
            answer = p;
    }

    return answer;
}*/
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    for(auto c : completion){
        m[c] +=1;
    }
    for(auto p : participant){
        m[p]-=1;
        if(m[p]<0)
            answer = p;
    }
    return answer;
}

int main()
{
    vector<string> s1 = {"q", "q", "w", "r", "e", "e", "w", "s", "b", "a", "1", "5"};
    vector<string> s2 = {"q", "q", "w", "r", "e", "5", "1", "e", "w", "s", "b"};
    string s = solution(s1, s2);
    cout << endl;
    cout << s;
}