#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int erasedNumber = 0;
    int sameNumber = 0;

    for (int l : lottos)
    {
        if (l == 0)
            erasedNumber++;
        for (int w : win_nums)
        {
            if (l == w)
                sameNumber++;
        }
    }
    int best = erasedNumber + sameNumber;
    switch (best)
    {
    case 0:
        answer.push_back(6);
        break;
    case 1:
        answer.push_back(6);
        break;
    case 2:
        answer.push_back(5);
        break;
    case 3:
        answer.push_back(4);
        break;
    case 4:
        answer.push_back(3);
        break;
    case 5:
        answer.push_back(2);
        break;
    case 6:
        answer.push_back(1);
        break;
    }
    switch (sameNumber)
    {
    case 0:
        answer.push_back(6);
        break;
    case 1:
        answer.push_back(6);
        break;
    case 2:
        answer.push_back(5);
        break;
    case 3:
        answer.push_back(4);
        break;
    case 4:
        answer.push_back(3);
        break;
    case 5:
        answer.push_back(2);
        break;
    case 6:
        answer.push_back(1);
        break;
    }

    return answer;
}

int main()
{
    solution({44, 1, 0, 0, 31, 25}, {31, 10, 45, 1, 6, 19});
}