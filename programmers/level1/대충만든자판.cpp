#include <string>
#include <vector>

using namespace std;

//A=65 Z=90
int d[91];

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    fill_n(d, 91, 101);
    for (auto key : keymap) {
        for (int i = 0; i < key.length(); i++) {
            d[key[i]] = d[key[i]] > i + 1 ? i + 1 : d[key[i]];
        }
    }
    for (auto target : targets) {
        int res = 0;
        for (auto t : target) {
            if (d[t] == 101) {
                res = -1;
                break;
            }
            res += d[t];
        }
        answer.push_back(res);
    }
    return answer;
}