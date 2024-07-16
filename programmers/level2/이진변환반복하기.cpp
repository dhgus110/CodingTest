#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//문자열에서 0 갯수 찾기
int zeroCount(string s){
    return count(s.begin(),s.end(),'0');
}

//문자열에서 0 삭제
void zeroErase (string &s){
    s.erase(remove(s.begin(),s.end(),'0'), s.end());
}

//10진수 -> 2진수 문자열
string binarySystem(int n){
    string result ="";

    while(n>1){
        result += to_string(n%2);
        n/=2;
    }

    result += to_string(n);
    reverse(result.begin(),result.end());
    return result;
}


vector<int> solution(string s) {
    vector<int> answer;
    int cycleCnt = 0;
    int zeroCnt = 0;

    while(s.size()>1){
        zeroCnt += zeroCount(s);
        cycleCnt++;
        zeroErase(s);
        s = binarySystem(s.size());
    }
    answer.push_back(cycleCnt);
    answer.push_back(zeroCnt);
    return answer;
}