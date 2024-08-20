// 백준 1541번 
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> split(string input, char delimiter){
    vector<string> res;
    stringstream ss(input);
    string splitData;

    while (getline(ss, splitData, delimiter)){
        res.push_back(splitData);
    }

    return res;
}

int stringSum(string str){
    int sum = 0;
    vector<string> temp = split(str, '+');

    for (auto t : temp){
        sum += stoi(t);
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string example;
    cin >> example;

    vector<string> str = split(example, '-');

    int answer = 0 ;
    for (int i = 0; i < str.size(); i++){
        if(i == 0) answer += stringSum(str[i]);
        else answer -= stringSum(str[i]);
    }

    cout<<answer<<endl;
}