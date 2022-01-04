#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0,count =0;
    queue <pair<int,int>> q; //(중요도, 순서)
    priority_queue <int> pq; //중요도  

    for(int i = 0; i <priorities.size();i++){
        q.push(make_pair(priorities[i],i));
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int priority = q.front().first;
        int index = q.front().second;

        q.pop();
        if(priority == pq.top()){
            pq.pop();
            count++;
            if(index==location){
                answer=count;
                break;
            }
        }
            else{
                q.push(make_pair(priority,index));
            }
        }
    
    return answer;
}