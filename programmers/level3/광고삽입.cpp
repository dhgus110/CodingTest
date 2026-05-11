#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long sumTime[360'000];
int entry[360'000];
int leave[360'000];
int people[360'000]; //시간대에 몇명이 시청중인지

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
    fill(entry, entry + 360'000, 0);
    fill(leave, leave + 360'000, 0);
    fill(people, people + 360'000, 0);
    fill(sumTime, sumTime + 360'000, 0);
    for(const auto& log : logs)
    {
        ++entry[strTimeToInt(log.substr(0,8))];
        ++leave[strTimeToInt(log.substr(9,8))];
    }

    int playDurtaion = strTimeToInt(play_time);
    int advDurtaion = strTimeToInt(adv_time);
    int curPeople = 0;
    for(int i = 0 ; i <= playDurtaion ; ++i)
    {
        curPeople = curPeople + entry[i] - leave[i];
        people[i] = curPeople;
    }


    int firstSumTime = 0;
    for(int i = 0 ; i < advDurtaion ; ++i)
        firstSumTime += people[i];
    

    sumTime[0] = firstSumTime;
    int maxTime = 0;
    long long maxTimeValue = sumTime[0];

    for(int i = 1 ; i <= playDurtaion ; ++i)
    {
        int next = advDurtaion + i - 1;
        if(next > playDurtaion) break;

        sumTime[i] = sumTime[i - 1] + people[next] - people[i - 1];
        if( maxTimeValue < sumTime[i] )
        {
            maxTimeValue = sumTime[i];
            maxTime = i;
        }

    }

    return intTimeToStr(maxTime);
}

