#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;
    for(int m : moves){
        int size= board[m-1].size();
        for(int i=size-1 ;i >=0 ; i--){
           if(board[m-1][i] !=0){
               basket.push_back(board[m-1][i]);
               board[m-1][i]=0;
           }
        }
    }
    for(int i=0; i<basket.size(); i++){
        cout<<basket[i]<< " ";
        if(basket[i]==basket[i+1])
        answer++;
    }
    return answer;
}

//같으면 삭제
int main(){
    vector<vector<int>> b = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    vector<int> mo = {1, 5, 3, 5, 1, 2, 1, 4};
    cout<< solution(b,mo);
    // solution(b,m);
}