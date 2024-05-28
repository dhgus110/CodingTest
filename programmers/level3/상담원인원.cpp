#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int mentorsByType[6][21]; // [유형][멘토 수] = 총 대기 시간
int maxMentors;

void init(int const& k , int const& n){
    maxMentors = n - k + 1;
}

void waitingTimeByMentors(int const& m, queue<vector<int>> q){
    int totalWaitTime = 0; //참가자가 멘토를 기다린 시간
    int endTimes[21]={0,}; //멘토마다의 끝나는 시간
    int type =q.front()[2];

    while (!q.empty())
    {
        int startTime =q.front()[0];
        int adviceTime =q.front()[1];
        q.pop();

        int minIndex = min_element(endTimes+1,endTimes+(m+1))-endTimes;// 1~m 최소 인덱스 찾기
        if (endTimes[minIndex] == 0) endTimes[minIndex] = startTime + adviceTime;
        else {
            if(endTimes[minIndex] > startTime){
                totalWaitTime += endTimes[minIndex] -startTime;
                endTimes[minIndex] += adviceTime;
            }
            else{
                endTimes[minIndex] = startTime + adviceTime;
            }
        }
    }

    mentorsByType[type][m] = totalWaitTime;
    // cout<<"type :"<<type<<", mentors : "<<m<<" , 총 대기 시간 :"<<totalWaitTime<<endl;
    
}

void pushTimeByType(vector<vector<int>>const& reqs){
    queue<vector<int>> q1;
    queue<vector<int>> q2;
    queue<vector<int>> q3;
    queue<vector<int>> q4;
    queue<vector<int>> q5;

    for (auto r : reqs)
    {
        switch (r[2])
        {
        case 1:
            q1.push(r);
            break;
        case 2:
            q2.push(r);
            break;
        case 3:
            q3.push(r);
            break;
        case 4:
            q4.push(r);
            break;
        case 5:
            q5.push(r);
            break;
        }
    }

    for (int mentor = 1; mentor <= maxMentors; mentor++)
    {
        if(!q1.empty()) waitingTimeByMentors(mentor,q1);
        if(!q2.empty()) waitingTimeByMentors(mentor,q2);
        if(!q3.empty()) waitingTimeByMentors(mentor,q3);
        if(!q4.empty()) waitingTimeByMentors(mentor,q4);
        if(!q5.empty()) waitingTimeByMentors(mentor,q5);
    }
}

int getMinValue(int const& k, int const& n){
    int decreaseTimes[6]={0,}; // 멘토 1명일때 대기시간과 2명일때 대기시간의 감소 값
    int getMentor[6]={0,};    //감소 값이 가장 큰 타입에 +1 명 하기
    int total=0; //걸린 시간

        // cout<<"멘토 수 :"<<1<<endl;
    for(int i = 1; i <=5; i++){
        decreaseTimes[i]=mentorsByType[i][1];
        getMentor[i] = 1 ;

        // cout<<decreaseTimes[i]<<" ";
    }
    // cout<<endl;

    //타입별로 멘토 한명씩 늘어날 때 마다 시간이 가장 많이 감소한 타입에 멘토 한명 증가시킨다.
    for(int mentor = 2 ; mentor <= maxMentors; mentor++){
        int maxWaitTime = 0, maxIndex = 0;

        for (int type = 1; type <= k; type++){
            // cout<<decreaseTimes[type] <<" , "<<mentorsByType[type][mentor]<<endl;
            if(maxWaitTime< decreaseTimes[type] - mentorsByType[type][mentor]){
                maxIndex=type;
                maxWaitTime = decreaseTimes[type] - mentorsByType[type][mentor];
            }
        }
        decreaseTimes[maxIndex] =mentorsByType[maxIndex][mentor];
        getMentor[maxIndex]++;

        // cout<<"멘토 수 :"<<mentor<<" ,maxIndex : "<<maxIndex<<" ,maxWaitTime : "<<maxWaitTime<<endl;
        // for (int i = 1; i <= 5; i++)
        // {
        //     cout << decreaseTimes[i] << " ";
        // }
        // cout << endl;
    }
    // cout<<"getmentor"<<endl;
    // for(auto a :getMentor){
    //     cout<<a<<" ";
    // }cout<<endl;

    for (int type = 1; type <= k; type++){
        total += mentorsByType[type][getMentor[type]];
    }
    return total;

}


int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    init(k,n);
    pushTimeByType(reqs);
    return getMinValue(k,n);
}