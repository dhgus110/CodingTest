#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> board) {
    int oNum = 0, xNum = 0;
    for(auto bo : board){
        for(auto b :bo){
            if(b=='O') oNum++;
            else if(b=='X') xNum++;
        }
    }

    if (oNum < xNum || oNum - 1 > xNum ) return 0;

    int oWin =0, xWin =0;

    for (int i = 0; i < 3; i++)
    {
        //가로
        if(board[i]=="OOO") oWin++;
        else if(board[i]=="XXX") xWin++;

        //세로
        int oCnt = 0, xCnt = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i] == 'O') oCnt+=1;
            else if (board[j][i] == 'X') xCnt+=1;
        }
        if(oCnt == 3 ) oWin++;
        else if(xCnt == 3 ) xWin++;
    }
    //대각
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') xWin++;
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') oWin++;
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') xWin++;
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') oWin++;

    //선공, 후공 둘 다 이겼을 경우 
    if (oWin > 0 && xWin > 0) return 0;
    //선공이 이기고 게임을 더 한 경우
    else if (oWin > 0 && oNum <= xNum) return 0;
    //후공이 이기고 게임을 더 한 경우
    else if (xWin > 0 && oNum != xNum) return 0;

    return 1;
}