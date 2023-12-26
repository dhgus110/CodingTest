#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    deque<int> dq(people.begin(), people.end());

    while (!dq.empty()) {
        if (dq.size() == 1) {
            answer += 1;
            break;
        }
        int fatty = dq.back();
        int slender = dq.front();

        if (fatty + slender <= limit) {
            dq.pop_front();
            dq.pop_back();
            answer += 1;
        }
        else {
            dq.pop_back();
            answer += 1;
        }
    }
    return answer;
}

int solution2(vector<int> people, int limit) {
    int answer =0;
    sort(people.begin(),people.end());
    int front =0;
    int back = people.size() - 1;

    while(front<back){
        if( people[front]+people[back]<= limit){
            answer ++;
            front ++;
            back --;
        }else{
            answer++;
            back--;
        }
    }
    if(front == back) answer++;
    return answer;
}
