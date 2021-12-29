#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
   for(int a =0; a< commands.size() ;a++){
       int i = commands.at(a).at(0); 
       int j = commands.at(a).at(1); 
       int k = commands.at(a).at(2); 

       vector<int> v;
       for(int b= i-1; b< j;b++){
           v.push_back(array.at(b));
       }
       sort(v.begin(),v.end());
       answer.push_back(v.at(k-1));
        v.clear();
   }
    return answer;
}*/
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;
    for(int i = 0 ; i< commands.size() ; i++){
        v = array;
        sort(v.begin() + commands[i][0] - 1, v.begin() + commands[i][1]);
        answer.push_back(v[(commands[i][0] - 1) + (commands[i][2] - 1)]);
    }
    return answer;
}


int main(){
    vector<int> a={1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> b ={{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    vector<int> v =  solution(a,b);

    for(int i =0; i<v.size();i++){
        cout <<v[i]<< " " <<endl;
    }
}