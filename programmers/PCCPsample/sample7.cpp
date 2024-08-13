#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    int maxCustomers = 1;
    int index = 0;
    int time = 0;
    vector<int> arrivalTimes(order.size());
    queue<pair<int, int>> q; //주문정보, 도착시간

    for (int i = 0; i < arrivalTimes.size(); i++) {
        arrivalTimes[i] = i * k;
    }

    while (index < order.size()) {
        if (q.empty()) {
            q.push(make_pair(order[index],arrivalTimes[index]));
            time = arrivalTimes[index];
            index++;
        }

        int curMakeTime = menu[q.front().first];
        int curArrivalTime = q.front().second;
        time += curMakeTime;

        while (index < order.size() && time >= arrivalTimes[index]) {
            q.push(make_pair(order[index], arrivalTimes[index]));
            index++;
        }
        int curCustomers = time == curMakeTime + curArrivalTime ? q.size() - 1 : q.size();
        maxCustomers = max(maxCustomers, curCustomers);
        q.pop();
  
    }

    return maxCustomers;
}
