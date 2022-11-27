#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool accurate(string s){
    int slen = s.length();
    int open=0,close=0;
    for(int i = 0; i<slen;i++){
        if(s[i]=='(') open++;
        else close++;

        if(open<close) return false;
    }
    return true;
}

string dfs(string s){
    // step 1
    if (s.length() == 0) return s;

    //step2
    string u = "", v = "", empty = "";
    int cnt = 0, open = 0, close = 0 , slen = s.length();
    for(cnt; cnt <slen ;cnt++)
    {
        if (s[cnt] == '(')
            open++;
        else
            close++;

        if(open == close) break;
        cnt++;
    }
    cout<<cnt<<endl;
    u= s.substr(0,cnt);
    v= s.substr(cnt);

    //step3
    if (accurate(u))
    {
        cout<< "step3"<<endl;
        u += dfs(v);
        empty = u;
    }   
    else //step4
    {
        cout<< "step4"<<endl;
        empty += '(';
        empty += dfs(v);
        empty += ')';
        for(int i =1 ; i<u.length()-1;i++){
            if(u[i]=='(') empty += ')';
            else empty += '(';
        }
    }
    return empty;
}

string solution(string p) { 
    return dfs(p);
}