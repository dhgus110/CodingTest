//문제 설명이 부실하다..
//1. [aabba] <- aa 와 a는 다른 외톨이 알파벳인가?  o
//2. 같은 외톨이 인가?   x

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int sCnt[26][2601];

void init(){
    fill_n(&sCnt[0][0], 26 * 2601, 0);
}

//1번 다른 외톨이
string run1(string s){
    string answer ="";
    string str = "";
    set<char> setc;

    for (auto c : s){
        if(!str.empty() && str.back() != c){
            if(sCnt[str.back()-97][str.size()]++ >0){
                setc.insert(str.back());
            }
            str = c;
        }
        else{
            str += c;
        }
    }
    if(sCnt[str.back()-97][str.size()]++ >0){
        setc.insert(str.back());
    }

    if (setc.empty())
        return "N";

    for(auto c :setc){
        answer += c;
    }

    return answer;
}

//2번 같은 외톨이
string run2(string s){
    string answer ="";
    string str="";
    int cnt[26] ={0,};

    for(auto c: s){
        if(!str.empty()&& str.back() != c){
            cnt[str.back()-97]++;
            str=c;
        }
        else{
            str += c;
        }
    } 
    cnt[str.back()-97]++;

    for(int i = 0 ; i<26;i++){
        if (cnt[i] > 1)
            answer += char(i + 97);
    }
    if(answer.empty()) return "N";
    return answer;

}

string solution(string input_string) {
    string answer = "";
    init();
    answer =run2(input_string);

    return answer;
}