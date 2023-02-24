#include <string>
#include <vector>

using namespace std;

bool isWin(vector<string>const& board){
    for(auto bo : board){
        if(bo=="OOO"){

        }
        if(bo=="XXX"){

        }
    }
    for(int i = 0 ; i <3;i++){
        for(int j =0 ;j<3;j++){
          if(board[j][i]){
              
          }  
        }
        
    }

}

int solution(vector<string> board) {
    int answer = 1;
    int dotNum = 0, oNum = 0, xNum = 0;
    for(auto bo : board){
        for(auto b :bo){
            if(b =='.') dotNum++;
            else if(b=='O') oNum++;
            else xNum++;
        }
    }
    if(oNum < xNum) return 0;

    


    return answer;
}