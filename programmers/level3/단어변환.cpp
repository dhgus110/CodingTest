#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

bool visited[50]={false};

bool oneGapWord(string s1, string s2){
    int gap = 0;
    for(int i = 0; i< s1.size() ; i++){
        if(s1[i] != s2[i]) gap++;
    }
    if(gap ==1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    //단어가 없을 경우
    bool isExistent =false;
    for(auto w : words){
        if(w ==target)
            isExistent =true;
    }
    if(!isExistent) return 0;

    // bfs(begin);
    queue<string> q;
    map<string,int> m;
    q.push(begin);
    m.insert(make_pair(begin,0));
    while(!q.empty()){
        string cur = q.front();
        q.pop();

        int level;
        auto item =m.find(cur);
        if(item != m.end())
            level = item->second;
        else cout<<"error";

        bool isBreak =false;

        for(int i = 0; i< words.size(); i++){
            if(oneGapWord(cur,words[i])&& visited[i]==false){
                if( words[i]==target) isBreak= true;
                m.insert({words[i],level+1});
                visited[i] =true;
                q.push(words[i]);
            }
        }

        if(isBreak) break;
    }
    auto item =m.find(target);
        if(item != m.end())
            answer = item->second;
        else cout<<"not find target!";

    return answer;
}

int main(){
    cout<< solution("hit","cog",{"hot", "dot", "dog", "lot", "log", "cog"});
}
