#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> ability, int number) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq (ability.begin(),ability.end());

    for (int i = 0; i < number; i++) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }
    
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    return answer;
}
