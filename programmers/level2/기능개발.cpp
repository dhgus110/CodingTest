#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> job;
    for(int i =0; i<speeds.size();i++){
        int remainingJob = ceil((100.0f-(float)progresses[i])/(float)speeds[i]);
        job.push(remainingJob);
    }
    int a=0;
    int compare = job.front();

    while(!job.empty()){
        job.pop();
         a++;
        if(job.front()==0) break;
        if(compare<job.front()){
            compare = job.front();
            answer.push_back(a);
            a=0;
        }
    }
    if(a!=0) answer.push_back(a);
    return answer;
}