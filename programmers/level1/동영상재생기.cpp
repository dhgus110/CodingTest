#include <string>
#include <vector>

using namespace std;

int toSecond(const string& time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string toString(int sec)
{
    int m = sec / 60;
    int s = sec % 60;

    string mm = (m < 10 ? "0" : "") + to_string(m);
    string ss = (s < 10 ? "0" : "") + to_string(s);

    return mm + ":" + ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    int video = toSecond(video_len);
    int cur = toSecond(pos);
    int opS = toSecond(op_start);
    int opE = toSecond(op_end);

    auto SkipOpening = [&]()
    {
        if (opS <= cur && cur <= opE)
            cur = opE;
    };

    SkipOpening();

    for (const string& cmd : commands)
    {
        if (cmd == "prev")
        {
            cur -= 10;
            if (cur < 0)
                cur = 0;
        }
        else
        {
            cur += 10;
            if (cur > video)
                cur = video;
        }

        SkipOpening();
    }

    return toString(cur);
}