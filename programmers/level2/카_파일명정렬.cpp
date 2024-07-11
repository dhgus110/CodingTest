#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool pos(char c){ return isdigit(c);}
bool epos(char c){ return !isdigit(c);}

string toLowerString(string s){
    string dummy =s;
    for(int i = 0 ; i<dummy.size();i++){
        dummy[i] = tolower(dummy[i]);
    }
    return dummy;
}

vector<string> split(string str){
    string head = "", number = "", tail = "";
    int numberStart = find_if(str.begin(), str.end(), pos) - str.begin();
    int numberEnd = find_if(str.begin()+numberStart, str.end(), epos) - str.begin();

    head = toLowerString(str.substr(0, numberStart));
    number = str.substr(numberStart, numberEnd - numberStart);
    tail = toLowerString(str.substr(numberEnd));

    //전부 소문자로 저장
    return {head, number, tail};
}

bool compare(pair<int,vector<string>> a , pair<int,vector<string>> b){
    if(a.second[0]< b.second[0])return true;
    else if (a.second[0]> b.second[0])return false;
    else return stoi(a.second[1]) < stoi(b.second[1]);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<int,vector<string>>> headNumberTail; 

    for(int i = 0 ; i<files.size(); i++){
        headNumberTail.push_back(make_pair(i, split(files[i])));
    }

    //sort - 불완전 정렬  aa,aa,aa와같은 같은 원소들을 정렬 시 상대적인 순서를 유지를 못할지도 모른다.
    //stable_sort - 완전 정렬 상대적인 순서를 유지한다.
    stable_sort(headNumberTail.begin(), headNumberTail.end(), compare);

    for(auto ss: headNumberTail){
        answer.push_back(files[ss.first]);
    }
    return answer;
}