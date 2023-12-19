#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location)
{
    queue <pair<int,int>> q; // <중요도, 순서>
    priority_queue <int> pq; //<중요도>

    for(int i = 0 ; i<priorities.size();i++){
        q.push({priorities[i],i});
        pq.push(priorities[i]);
    }

    int count =0;
    while(true){
        int curPrior = q.front().first;
        int curIndex = q.front().second;
        q.pop();

        if(curPrior == pq.top()){
            count++;
            if(curIndex == location) return count;
            pq.pop();
        }
        else{
            q.push({curPrior,curIndex});
        }
    }
}