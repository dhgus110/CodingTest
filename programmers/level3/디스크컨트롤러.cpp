#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue <pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; // {소요 시간, 요청 시간}
    sort(jobs.begin(),jobs.end());
    
    int i =0;
    int time =0;
    int requestTime =0, costTime =0; 

    pq.push({jobs[i][1],jobs[i++][0]}); 
    costTime = pq.top().first;
    requestTime = pq.top().second;
    pq.pop();
    time = requestTime + costTime;
    answer += costTime;

    while(true ){
        if(i == jobs.size() && pq.empty()) break;

        //현재 시간 보다 작거나 같은 요청 시간들을 push
        while (i < jobs.size() && jobs[i][0]<= time){
            pq.push({jobs[i][1],jobs[i++][0]}); 
        }
        
        //pq가 비어 있지 않다면 top을 꺼내서 시간 계산 하고 pop
        if(!pq.empty()){
            costTime = pq.top().first;
            requestTime = pq.top().second;
            pq.pop();
            time += costTime;
            answer += (time -requestTime);
        } // jobs에 작업이 더 남아 있는데 pq가 비어 있다면 push 하고 시간 계산 후 pop
        else if (pq.empty() && i - 1 < jobs.size()){
            pq.push({jobs[i][1],jobs[i++][0]});
            time = pq.top().second + pq.top().first; // 흘러간 시간은 요청된 시간 + 소요시간
            answer += pq.top().first; // answer은 소요시간만큼 더하기
            pq.pop();
        }

    }

    answer /= jobs.size();
    return answer;

}
