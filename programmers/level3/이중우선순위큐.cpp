#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations){
    priority_queue<int> maxq;
    priority_queue<int> minq;
    int check =0;

    for(auto op : operations){
        if(op[0] =='I'){
            maxq.push(stoi(op.substr(2)));
            minq.push(stoi(op.substr(2))* -1 );
            check++;
        }
        else if(check>0){
            if(op[2]=='1'){
                maxq.pop();
            }
            else{
                minq.pop();
            }
            check--;
        }
        //clear 대신 함...
        if(check == 0){
            priority_queue<int> dummy1;
            priority_queue<int> dummy2;
            maxq.swap(dummy1);
            minq.swap(dummy2);
        }
    }

    if(check ==0) return {0,0};
    return {maxq.top(), minq.top() * -1};
}
