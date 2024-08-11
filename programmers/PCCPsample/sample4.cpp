#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct model {
    int order;  //들어온 순서
    int priority; //우선순위
    int start;  //시작시간
    int run;    //실행시간
};

struct modelCmp {
    bool operator()(const model& a, const model& b) {
        if (a.priority == b.priority)
            return a.order > b.order;
        return a.priority > b.priority;
    }
};

bool cmp(vector<int>const& a, vector<int>const& b) {
    return a[1] < b[1];
}

vector<long long> solution(vector<vector<int>> program) {
    vector<long long> answer(11, 0);
    sort(program.begin(), program.end(), cmp);
    
    priority_queue < model, vector<model>, modelCmp > pq;
    long long curTime = 0;
    int index = 0;
    int programSize = program.size();

    while (index < programSize || !pq.empty()) {
        while (index < programSize && program[index][1] <= curTime) {
            pq.push({ index, program[index][0], program[index][1], program[index][2] });
            index++;
        }
        
        if (pq.empty()) {
            if (index < programSize)
                curTime = program[index][1];
            continue;
        }

        model cur = pq.top();
        pq.pop();

        long long waitTime = curTime - cur.start;
        answer[cur.priority] += waitTime;
        curTime += cur.run;
    }

    answer[0] = curTime;

    return answer;
}
