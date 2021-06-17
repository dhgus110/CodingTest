#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;
    for(int m : moves){
        for(int i=board.size()-1 ;i >=0 ; i--){
           if(board[m-1][i] !=0){
                if(!basket.empty() && basket[basket.size()-1]==board[m-1][i]){
                    basket.pop_back();
                    answer+=2;
                }
                else
                    basket.push_back(board[m-1][i]);
               board[m-1][i]=0;
               break;
           }
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> b = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};  //1 1 3 3 2 
    vector<int> mo = {1, 5, 3, 5, 1, 2, 1, 4};
    int a= solution(b,mo);
     cout<<a<<endl;
}
