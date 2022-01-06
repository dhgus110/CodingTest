#include <string>
#include <vector>
#include <regex>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
// enum class Player  {A,C,F,J,M,N,R,T};
// static const char* Player[] = {"A","C","F","J","M","N","R","T"}; //enum_string  

bool check(string s, char player1, char player2, char condition, char dir){
    int seat1,seat2;
    for(int  i = 0; i<s.size(); i++){
        if(s[i]==player1){
            seat1=i;
        }
        else if(s[i]==player2){
            seat2=i;
        }
    }
    int distance = abs(seat1-seat2) -1 ;

    switch (condition)
    {
    case '=':
        return distance == int(dir-'0');
        break;
    case '<':
        return distance < int(dir-'0');
        break;
    case '>':
        return distance > int(dir-'0');
        break;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    vector <int> playernum;
    vector <char> player = {'A','C','F','J','M','N','R','T'};
    for(int i = 0; i <8 ; i++){
        playernum.push_back(i);
    }

    do 
    {
        string s = "";
        for(int i = 0; i <8 ;i++){
            s.push_back(player[playernum[i]]); //플레이어 순열 순으로 s에 저장
        }

        bool flag = true;
        for(auto d :data){
            if(!check(s,d[0],d[2],d[3],d[4]) ){ //A~F=0
                flag =false;
                break;
            }
        }
        if(flag) answer++;

    }while(next_permutation(playernum.begin(),playernum.end()));
    
    return answer;
}
