#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<pair<int,int>> s;
    for (int i = 0; i < numbers.size(); i++) {
        if (s.empty())
            s.push(make_pair(numbers[i], i));
        else
            while (true && !s.empty()) {
                int preNum = s.top().first;
                if (preNum < numbers[i]) {
                    answer[s.top().second] = numbers[i];
                    s.pop();
                    if(s.empty())
                        s.push(make_pair(numbers[i], i));
                }
                else {
                    s.push(make_pair(numbers[i], i));
                    break;
                }
            }
    }
    while (!s.empty()) {
        answer[s.top().second] = -1;
        s.pop();
    }

    return answer;
}