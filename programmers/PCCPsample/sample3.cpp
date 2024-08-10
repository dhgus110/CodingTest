#include <string>
#include <vector>

using namespace std;

string secondGeneration[4] = { "RR","Rr","Rr","rr" };

string generation(int n, int p) {
    if (n == 1) return "Rr";
    if (n == 2) return secondGeneration[p - 1];

    int parentIndex = (p - 1) / 4;
    int posInParent = (p - 1) % 4;

    string parent = generation(n - 1, parentIndex + 1);

    if (parent == "RR")return"RR";
    if (parent == "rr")return"rr";
    if (parent == "Rr")return secondGeneration[posInParent];
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;

    for (auto q : queries) {
        answer.push_back(generation(q[0], q[1]));
    }

    return answer;
}

