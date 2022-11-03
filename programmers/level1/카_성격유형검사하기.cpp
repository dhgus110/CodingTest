#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    map<char, int> m;
    m.insert({ 'R',0 });
    m.insert({ 'T',0 });
    m.insert({ 'C',0 });
    m.insert({ 'F',0 });
    m.insert({ 'J',0 });
    m.insert({ 'M',0 });
    m.insert({ 'A',0 });
    m.insert({ 'N',0 });
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] < 4) {
            choices[i] == 1 ? m[survey[i][0]] += 3 : choices[i] == 2 ? m[survey[i][0]] += 2 : m[survey[i][0]] += 1;
        }
        else if (choices[i] > 4) {
            m[survey[i][1]] += choices[i] - 4;
        }
    }
    m['R'] < m['T'] ? answer.push_back('T') : answer.push_back('R');
    m['C'] < m['F'] ? answer.push_back('F') : answer.push_back('C');
    m['J'] < m['M'] ? answer.push_back('M') : answer.push_back('J');
    m['A'] < m['N'] ? answer.push_back('N') : answer.push_back('A');

    return answer;
}

