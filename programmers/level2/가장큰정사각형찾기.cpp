#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[0].size(); ++x)
        {
            if(board[y][x]== 0) continue;
            
            if(y != 0 && x != 0)
                board[y][x] = min(min(board[y - 1][x], board[y][x - 1]), board[y - 1][x - 1]) + 1;
            answer = max(answer, board[y][x]);
        }
    }
    return answer * answer ;
}

