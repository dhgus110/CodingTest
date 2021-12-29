#include <string>
#include <vector>
#include <iostream>

using namespace std;
string func(string s){
    if(s=="zero") return "0";
    else if(s=="one") return "1";
    else if(s=="two") return "2";
    else if(s=="three") return "3";
    else if(s=="four") return "4";
    else if(s=="five") return "5";
    else if(s=="six") return "6";
    else if(s=="seven") return "7";
    else if(s=="eight") return "8";
    else if(s=="nine") return "9";
    else return "10";
}
int solution(string s) {
    string ss;
    string result;
    for(int i = 0 ; i<s.size();i++){
        if(!isdigit(s[i])){
            ss.push_back(s[i]);
            if(func(ss)!="10"){
                result.push_back(func(ss)[0]);
                ss.clear();
            }
        }
        else{
            result.push_back(s[i]);
        }
    }
    return stoi(result);
}

int main(){
    solution("1zerotwozero3");
}