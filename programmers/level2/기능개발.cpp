#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> res;
    queue <int> q ;
    for(auto p : progresses){
        q.push(p);
    }
    int sum=0;
    int cur =q.front();
    int curIndex = 0 ;
    int remaining = (100 - cur)/speeds[curIndex];
    remaining = cur + speeds[curIndex] * remaining >= 100 ? remaining : remaining + 1;

    while (!q.empty())
    {
        int curProgress = q.front();
        q.pop();
        if( curProgress + speeds[curIndex]* remaining < 100){
            res.push_back(sum);
            sum = 0;
            remaining = (100 - curProgress)/speeds[curIndex];
            remaining = curProgress + speeds[curIndex] * remaining >= 100 ? remaining : remaining + 1;
        }
        sum++;
        curIndex++;
    }
    if(sum >0) res.push_back(sum);
    return res;
    
}


// vector<int> solution(vector<int> progresses, vector<int> speeds) {
//     vector<int> answer;
//     queue<int> job;
//     for(int i =0; i<speeds.size();i++){
//         int remainingJob = ceil((100.0f-(float)progresses[i])/(float)speeds[i]);
//         job.push(remainingJob);
//     }
//     int a=0;
//     int compare = job.front();

//     while(!job.empty()){
//         job.pop();
//          a++;
//         if(job.front()==0) break;
//         if(compare<job.front()){
//             compare = job.front();
//             answer.push_back(a);
//             a=0;
//         }
//     }
//     if(a!=0) answer.push_back(a);
//     return answer;
// }