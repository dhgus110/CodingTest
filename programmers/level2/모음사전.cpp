#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string word) {
    int answer = 0;

    int numberOfBranch = 5;
    int max = 0;
    for (int i = 1; i <= numberOfBranch; i++) {
        max += pow(numberOfBranch, i);
    }

    for (int i = 1; i <= word.size(); i++) {
        if (word[i - 1] == 'A')
            answer += 1;
        else if (word[i - 1] == 'E')
            answer += (max / pow(numberOfBranch, i) * 1) + 1;
        else if (word[i - 1] == 'I')
            answer += (max / pow(numberOfBranch, i) * 2) + 1;
        else if (word[i - 1] == 'O')
            answer += (max / pow(numberOfBranch, i) * 3) + 1;
        else if (word[i - 1] == 'U')
            answer += (max / pow(numberOfBranch, i) * 4) + 1;
    }

    return answer;
}