#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
1. 각 버스 마지막 승객 1분 전 도착
2. 각 버스 시간에 맞춰서 도착
3. 만약되면 저장해서 가장 늦은 시간으로 정답
*/

string strTime(int time)
{
    int h = time / 60;
    int m = time % 60;

    string str ="";
    if(h<10) str+='0'; str+= to_string(h);
    str+= ':';
    if(m<10) str+='0'; str+=to_string(m);
    
    return str;
}

int intTime(string strTime)
{
    int h = stoi(strTime.substr(0, 2));
    int m = stoi(strTime.substr(3, 2));

    return h * 60 + m;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    int answer = 0;
    int lastBusTime = 540 + t * (n - 1);
    int busTime = 540;
    int seatCnt = m;
    
    sort(timetable.begin(), timetable.end());
    vector<int> valid;
    vector<int> seats(n,0);
    int index = 0;
    
    for(string str : timetable){
        int time = intTime(str);
        
        if(time <= busTime && seatCnt > 0) // 제 시간에 옴 + 좌석 남음
        {
            ++seats[index];
            --seatCnt;
        }
        else
        {
            while(true) //현재 승객 기준으로 다음 버스시간까지 업데이트
            {
                busTime += t;
                ++index;
                if(time <= busTime) break;
            }

            if(index >= n ) break; //버스가 다 지나감

            ++seats[index];
            seatCnt = m - 1;
        }
        
        if(time <= lastBusTime) valid.emplace_back(time);
    }

    for(int i = 0 ; i < n - 1 ; ++i) // 첫 버스부터 정규화(?)-> 딱 좌석에 맞춰서 분배시키기
    {
        if(seats[i] > m)
        {
            seats[i + 1] += seats[i] - m;
            seats[i] = m;
        }
    }

    if(seats.back() < m) //마지막 버스에 자리가 남음
        return strTime(lastBusTime);

    return strTime(valid.back() - 1); //아니면 유효한 시간에 온 마지막 사람 - 1
}
