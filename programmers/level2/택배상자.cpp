#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int now = 0;
    stack<int> assist;

    for(int box = 1; box <= order.size(); box++){
        if(order[now] != box){
            assist.push(box);
            continue;
        }
        now++;
        answer++;

        while (!assist.empty() && order[now] == assist.top()){
            assist.pop();
            now++;
            answer++;
        }
    }

    return answer;
}
