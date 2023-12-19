#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)  //다리길이 2 , 무게한계치 10 , 순서대로 대기중인 트럭들 무게 [7,4,5,6] , return 8
{ 
    queue <int> entryTrucks;
    vector <int> passingTimes(truck_weights.size(),0);
    int curTruckIndex = 0 ;
    int curTruckWeight =0;
    int time = 0;
    int frontTruck =0, lastTruck =0;

    //첫 트럭 넣기
    entryTrucks.push(truck_weights[curTruckIndex]);
    curTruckWeight += truck_weights[curTruckIndex];
    //반복문
    //1. 빠져 나올 수 있는 것들 체크 
    //      다리길이만큼 시간이 됐으면 빠져나오기 
    //2. 현재 다리 위의 트럭무게 계산해서 무게한계치 도달했는지 체크
    //      false - 시간 +1 , entryTruck에 트럭 하나 추가
    //      ture - Pass
    //
    while(!entryTrucks.empty()){
        time++;
        for(int i = frontTruck; i<=lastTruck;i++){
            if(++passingTimes[i] ==bridge_length){
                entryTrucks.pop();
                frontTruck = i+1;
                curTruckWeight -= truck_weights[i];
            }
        }
        if (curTruckIndex + 1 != truck_weights.size() && weight >= curTruckWeight + truck_weights[curTruckIndex + 1]){
            entryTrucks.push(truck_weights[++curTruckIndex]);
            lastTruck = curTruckIndex;
            curTruckWeight+=truck_weights[curTruckIndex];
        }
    }
    time++;
    return time;

}

// int solution(int bridge_length, int weight, vector<int> truck_weights) {
//     int answer = 0;
//     queue <int> q; //트럭의 무게
//     vector <int> time (truck_weights.size(),0); //트럭마다의 시간

//     q.push(truck_weights[0]); //첫 트럭 넣기
//     int curWeight =q.front();
//     int i = 1; //현재 트럭 인덱스

//     while(!q.empty()){
//         answer++;
//         for(int j = 0 ; j< i ;j++){
//             if(++time[j]== bridge_length){
//                 curWeight -= truck_weights[j];
//                 q.pop();
//             }
//        }
//        if(curWeight+truck_weights[i] <= weight && i != truck_weights.size()){
//            curWeight += truck_weights[i];
//            q.push(truck_weights[i++]);
//        }
   
//     }
//     answer++;
//     return answer;
// }