#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

int mentorsByType[6][21]; // [유형][멘토 수] = 총 대기 시간
int maxMentors;

void init(int const& k , int const& n){
    maxMentors = n - k + 1;
}

void calWaitTime(const int& m, queue<vector<int>> q){
    priority_queue<int,vector<int>,greater<int>> mentorEndTimes;
    for(int i =0 ;i <m ; i++){
        mentorEndTimes.push(0);
    }

    int waitTime = 0;
    int type = q.front()[2];

    while(!q.empty()){
        int startTime = q.front()[0];
        int duration = q.front()[1];
        q.pop();

        int earliesEndTime = mentorEndTimes.top();
        mentorEndTimes.pop();

        if(earliesEndTime >startTime){
            waitTime += earliesEndTime - startTime;
            earliesEndTime += duration;
        }else{
            earliesEndTime = startTime + duration;
        }

        mentorEndTimes.push(earliesEndTime);
    }

    mentorsByType[type][m] = waitTime;
}

//유형마다 상담 요청 시간 분리
void pushQueueSet(vector<vector<int>>const& reqs){
    vector<queue<vector<int>>> queueSet(5);

    for (auto r : reqs){
        queueSet[r[2]-1].push(r);
    }

    for (int mentor = 1; mentor <= maxMentors; mentor++){
        for (int i = 0; i < 5; i++){
            if(!queueSet[i].empty())calWaitTime(mentor,queueSet[i]);
        }
    }
}

int getMin(const int& k , const int & n){

    //멘토 한 명씩 배치
    int curMentors[21] ={0,};
    for(int type =1 ; type <= k ; type++){
        curMentors[type] =1;
    }
    //한 명씩 배치하고 남은 멘토들
    int reminMentor = maxMentors - 1;

    while (reminMentor-- > 0){
        int maxReducieTime = 0;
        int curType = 0;

        for (int type = 1; type <= k; type++){
            //현재 멘토 수
            int curMentorsByType = curMentors[type];
            //현재 멘토 수일 때의 대기시간
            int curWaitTimeOfCurMentors = mentorsByType[type][curMentorsByType];
            //멘토 1명 추가시 대기시간
            int next = mentorsByType[type][curMentorsByType + 1];
            //멘토 1명 추가시 줄어든 대기시간
            int reduceWaitTime = curWaitTimeOfCurMentors - next ;

            //가장 많이 줄어든 대기시간 저장
            if(reduceWaitTime >= maxReducieTime){
                maxReducieTime = reduceWaitTime;
                curType = type;
            }

        }

        if(maxReducieTime ==0 ) break;

        curMentors[curType]++;
        cout<<curType<<endl;
    }

    int totalWaitTime = 0 ;
    for(int type =1 ; type <= k ; type++){
        totalWaitTime += mentorsByType[type][curMentors[type]];
    }

    return totalWaitTime;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    init(k,n);
    pushQueueSet(reqs);
    answer = getMin(k, n);
    return answer;
}