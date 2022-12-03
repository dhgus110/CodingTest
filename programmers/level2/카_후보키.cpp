#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int answer = 0;
vector<vector<string>> new_r; // 보드 판
unordered_set<string> mini; //최소성 판별

bool mini_check_func(string temp, string s, int now_pos){
    if(temp.size() == s.size()) return false;

    for(int i=now_pos;i<s.size();i++){
        temp.push_back(s[i]);
        if(mini.count(temp)) return true;
        else{
            bool mini_temp_check = mini_check_func(temp,s,i+1);
            if(mini_temp_check == true) return true;
        }
        temp.pop_back();
    }

    return false;
}

void dfs(vector<int> pick,int max_col,string mini_check){
    if(pick.size() == max_col){
        unordered_set<string> u;
        for(int i=0;i<new_r.size();i++){
            string s="";

            for(int now_col : pick){
                s+=new_r[i][now_col];
                s.push_back('+');
            }
            if(u.count(s)) return;
            else u.insert(s);
        }
        answer++;
        mini.insert(mini_check);
        return;
    }

    int start;
    if(pick.size()) start = pick.back()+1;
    else start = 0;

    for(int i=start;i<new_r[0].size();i++){
            pick.push_back(i);
            string to_att = "";
            to_att.push_back((char)(i+'0'));
            mini_check+= to_att;

            bool is_mini = mini_check_func("",mini_check,0);

            if(is_mini == false)
            {
                dfs(pick,max_col,mini_check);
            }

            mini_check.pop_back();
            pick.pop_back();
        }
    }


int solution(vector<vector<string>> relation) {
    new_r = relation;
    vector<int> v;
    for(int i=1;i<=relation[0].size();i++){
        dfs(v,i,"");
    }
    return answer;
}