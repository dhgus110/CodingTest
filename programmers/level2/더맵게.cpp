#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int k){
    int answer = 0;
    priority_queue<int,vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while(!pq.empty()&&pq.top()<k){
        int firstMin = pq.top();
        pq.pop();
        if(pq.empty()) return -1;
        int secondMin = pq.top();
        pq.pop();
        int newScoville = firstMin + (secondMin * 2);
        pq.push(newScoville);
        answer++;
    }

    return answer;
    
}


// int solution(vector<int> scoville, int k)
// {
//     int answer = 0;
//     priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(), scoville.end());
//     if (pq.top() >= k)
//         return -1;

//     while (pq.top() < k)
//     {
//         if(pq.size()<2) return -1;
//         int firstMild = pq.top(); pq.pop();
//         int secondMild = pq.top(); pq.pop();
//         if (secondMild == 0) return -1;
        
//         int mix = firstMild + secondMild * 2;
//         //cout<<"first : "<<firstMild<<"..second :"<<secondMild<<".. Mix : "<<mix<<endl;
//         pq.push(mix);
//         answer++;
//         // cout<<"top? "<<pq.top()<<endl;
//     }
//     cout<<answer;
//     return answer;
// }