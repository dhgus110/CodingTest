#include <string>
#include <vector>
#include <iostream>

using namespace std;

int playTime[360'000];
int peopleSum[360'000];

int strTimeToInt(string time)
{
    int h = stoi(time.substr(0,2));
    int m = stoi(time.substr(3,2));
    int s = stoi(time.substr(6,2));

    return h * 3600 + m * 60 + s;
}

string intTimeToStr(int time)
{
    int h = time / 3600;
    time -= h * 3600;
    int m = time / 60;
    time -= m * 60;
    int s = time;

    string strTime ="";
    if(h < 10)strTime +="0";
    strTime += to_string(h);

    strTime +=":";
    if(m < 10) strTime +="0";
    strTime += to_string(m);

    strTime +=":";
    if(s < 10) strTime +="0";
    strTime += to_string(s);

    return strTime;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    fill(playTime, playTime + 360'000, 0);
    fill(people, people + 360'000, 0);

    int startTime = 360'000 ; 
    for(const auto& log : logs)
    {
        int firstTime =strTimeToInt(log.substr(0,8));
        startTime = min(startTime, firstTime);
        ++playTime[firstTime];
        --playTime[strTimeToInt(log.substr(9,8))];
    }

    int playDuration = strTimeToInt(play_time);
    int advDuration = strTimeToInt(adv_time);
    int lastAdvTime = playDuration - advDuration + 1;
    int StartAdvTime = startTime < lastAdvTime ? startTime : lastAdvTime;

    int startSum = 0;
    for(int i = StartAdvTime ; i <= StartAdvTime + advDuration - 1 && playDuration >= i  ; ++i)
        startSum +=playTime[i];

    people[StartAdvTime] = startSum;

    int maxPeople = startSum;
    int maxIndex = StartAdvTime;

    int cnt = 0 ;
    cout<< StartAdvTime<< " "<< lastAdvTime<< " "<< playDuration<<endl;

    for(int i = StartAdvTime + 1 ; i <= lastAdvTime && playDuration >= i ; ++i)
    {
        if(i & 9 == 0 ) cout<<i;
        people[i] = people[i - 1] + playTime[i - 1 + advDuration] - playTime[i - 1];
        if( maxPeople < people[i])
        {
            maxIndex = i;
            maxPeople = people[i];
        }
        ++cnt;
    }
cout<<cnt;
    return intTimeToStr(people[maxIndex]);
}

