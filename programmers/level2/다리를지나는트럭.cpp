#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue <int> q; //트럭의 무게
    vector <int> time (truck_weights.size(),0); //트럭마다의 시간

    q.push(truck_weights[0]); //첫 트럭 넣기
    int curWeight =q.front();
    int i = 1; //현재 트럭 인덱스

    while(!q.empty()){
        answer++;
        for(int j = 0 ; j< i ;j++){
            if(++time[j]== bridge_length){
                curWeight -= truck_weights[j];
                q.pop();
            }
       }
       if(curWeight+truck_weights[i] <= weight && i != truck_weights.size()){
           curWeight += truck_weights[i];
           q.push(truck_weights[i++]);
       }
   
    }
    answer++;
    return answer;
}