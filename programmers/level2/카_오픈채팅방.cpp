#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> split(string s, string divid)
{
    vector<string> v;
    int start = 0;
    int d = s.find(divid);
    while (d != string::npos)
    {
        v.push_back(s.substr(start, d - start));
        start = d + 1;
        d = s.find(divid, start);
    }
    v.push_back(s.substr(start, d - start)); //음수를 넣으면 제일 큰 값으로 세팅-> 문자열이 길어질 수 있는 최대의 길이를 나타냄
    return v;
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<string> clone;
    map<string, string> map;

    for (string s : record)
    {
        vector<string> words = split(s, " ");

        if (words[0] == "Enter")
        {
            // 삽입 시 이미 키가 존재하므로 second의 false를 갖는다. 그러면 at() 함수를 사용하여 해당 값을 변경해주면 된다.
            if (map.insert(make_pair(words[1], words[2])).second == false)
                map.at(words[1]) = words[2];
            clone.push_back(words[1] + "님이 들어왔습니다.");
        }
        else if (words[0] == "Leave")
        {
            clone.push_back(words[1] + "님이 나갔습니다.");
        }
        else if (words[0] == "Change")
        {
            if (map.insert(make_pair(words[1], words[2])).second == false)
                map.at(words[1]) = words[2];
        }
    }
    for (string s : clone)
    {
        int d = s.find("님");
        string key = s.substr(0, d);
        answer.push_back(map[key] + s.substr(d , -1));
    }
    return answer;
}