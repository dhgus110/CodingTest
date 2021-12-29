#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> binary(int n,int size){ //2진법 만들기
    vector<int> v;
    while(n){
        v.push_back(n%2);
        n = n/2;
    }
    while(v.size()<size){
        v.push_back(0);
    }
    reverse(v.begin(),v.end());
    // for(auto a: v)
    //     cout<<a;
    // cout<<endl;
    return v;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int>> map1;
    vector<vector<int>> map2;
    vector<vector<int>> map3(n); //초기화 해주기 중요 

    for(auto a: arr1){
        map1.push_back(binary(a,n));
    }
    for(auto a: arr2){
        map2.push_back(binary(a,n));
    }
    for(int i = 0 ; i< n; i++){
        for(int j = 0 ; j< n ; j++){
            if(map1[i][j] || map2[i][j])
                map3[i].push_back(1);
            else
                map3[i].push_back(0);
        }
    }
    for(auto first : map3){
        string s="";
        for(auto second: first){
            if(second) s+="#";
            else s+=" ";
        }
        answer.push_back(s);
    }
    return answer;
}

int main(){
    solution(5, {9, 20, 28, 18, 11}, {30, 1, 21, 17, 28});
}