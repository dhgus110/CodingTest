#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int curfood = -1;
    for (auto f : food) {
        curfood++;
        if (f < 2) continue;
        for (int i = 0; i < f / 2; i++) {
            answer.push_back((char)(curfood+48));
        }

    }
    answer.push_back('0');
    curfood++;
    for (int a = food.size()-1; a > 0; a--) {
        curfood--;
        if (food[a] < 2) continue;
        for (int i = 0; i < food[a] / 2; i++) {
            answer.push_back((char)(curfood + 48));
        }

    }

    return answer;
}
//int main() {
//    string s = "";
//    s.push_back((char)(0 +48));
//   
//    cout << s << endl;
//}