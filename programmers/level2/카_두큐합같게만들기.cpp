#include <string>
#include <vector>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int size = queue1.size();
    long long qSum1 = 0, qSum2 = 0;
    for (auto q : queue1) qSum1 += q;
    for (auto q : queue2) qSum2 += q;

    int point1 = 0, point2 = 0;
    while (answer <= size * 4) {
        if (qSum1 > qSum2) {
            queue2.push_back(queue1[point1]);
            qSum2 += queue1[point1];
            qSum1 -= queue1[point1++];
        }
        else if (qSum1 < qSum2) {
            queue1.push_back(queue2[point2]);
            qSum1 += queue2[point2];
            qSum2 -= queue2[point2++];
        }
        else return answer;

        answer++;

        // erase를 쓰게되면 O(n)시간초과됨 최악인 경우 300,000*600,000
        //if (qSum1 > check) {
        //    qSum2 += queue1.front();
        //    qSum1 -= queue1.front();
        //    queue2.push_back(queue1.front());
        //    queue1.erase(queue1.begin());
        //}
        //else {
        //    qSum1 += queue2.front();
        //    qSum2 -= queue2.front();
        //    queue1.push_back(queue2.front());
        //    queue2.erase(queue2.begin());
        //}
      
    }

    return -1;
}
