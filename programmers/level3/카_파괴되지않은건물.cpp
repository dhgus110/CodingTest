#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    //2차원 행렬 누적합
    // n 0 0 -n     n n n 0
    // 0 0 0  0  -> n n n 0
    // 0 0 0  0     n n n 0
    //-n 0 0  n     0 0 0 0
    vector<vector<int>> skillsAccumulatedSum(board.size() + 1, vector<int> (board[0].size() + 1, 0));
    for(auto s : skill){
        if (s[0] == 2)
        {
            skillsAccumulatedSum[s[1]][s[2]] += s[5];
            skillsAccumulatedSum[s[3] + 1][s[2]] -= s[5];
            skillsAccumulatedSum[s[1]][s[4] + 1] -= s[5];
            skillsAccumulatedSum[s[3] + 1][s[4] + 1] += s[5];
        }
        else
        {
            skillsAccumulatedSum[s[1]][s[2]] -= s[5];
            skillsAccumulatedSum[s[3] + 1][s[2]] += s[5];
            skillsAccumulatedSum[s[1]][s[4] + 1] += s[5];
            skillsAccumulatedSum[s[3] + 1][s[4] + 1] -= s[5];
        }
    }

    //왼 -> 오 누적합
    for (int j = 0; j < skillsAccumulatedSum.size(); j++)
    {
        int sum = 0;
        for (int i = 0; i < skillsAccumulatedSum[0].size(); i++)
        {
            sum += skillsAccumulatedSum[j][i];
            skillsAccumulatedSum[j][i] = sum;
        }
    }

    //위 -> 아래 누적합 
    for (int i = 0; i < skillsAccumulatedSum[0].size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < skillsAccumulatedSum.size(); j++)
        {
            sum += skillsAccumulatedSum[j][i];
            skillsAccumulatedSum[j][i] = sum;
        }
    }

    for(int i = 0 ;i<board.size() ; i++){
        for(int j = 0 ;j<board[0].size(); j++){
            if (board[i][j] + skillsAccumulatedSum[i][j] > 0) answer++;
        }
    }

    return answer;
}