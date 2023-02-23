#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int cards1Index = 0;
    int cards2Index = 0;
    for (auto g : goal)
    {
        if (g == cards1[cards1Index])
            cards1Index++;
        else if (g == cards2[cards2Index])
            cards2Index++;
        else
            return "No";
    }
    return "Yes";
}