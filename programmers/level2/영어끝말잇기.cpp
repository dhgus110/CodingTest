#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0,0 };
    unordered_set<string> us;
    char endWord = words[0].front();

    for (int i = 0; i < words.size(); i++) {
        if (endWord != words[i][0] || us.find(words[i]) != us.end()) {
            int who = (i + 1) % n == 0 ? n : (i + 1) % n;
            int cycle = (i + 1) % n == 0 ? (i + 1) / n : (i + 1) / n + 1;
            return { who , cycle };
        }
        else if (us.find(words[i]) == us.end()) {
            us.insert(words[i]);
            endWord = words[i].back();
        }
    }

    return answer;
}
