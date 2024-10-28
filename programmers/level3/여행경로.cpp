#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <set>

using namespace std;

//dfs
vector<pair<vector<string>,int>> maps; //[[start, dest], order]
set<vector<string>> s;

void dfs1(vector<string> result, int order, vector<int> cnt){
    string nextCity = maps[order].first[1];
    result.push_back(nextCity);
    cnt[order] =0;

    int sum =accumulate(cnt.begin(),cnt.end(),0);
    if(sum==0) {s.insert(result); return;}

    for(int i = 0 ;i<maps.size() ; i++){
        if (cnt[maps[i].second] == 1 && maps[i].first[0] == nextCity){
            dfs1(result,maps[i].second,cnt);
        }
    }

    return ;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<vector<string>> results;

    sort(tickets.begin(),tickets.end());

    int num =0;
    for(auto t : tickets){
        maps.push_back(make_pair(t,num++));
    }

    answer.push_back("ICN");
    for(int i = 0 ; i<maps.size(); i++){
        if (maps[i].first[0] == "ICN"){
            vector<int> cnt(tickets.size(), 1);
            // pair<vector<string>,bool> res = dfs(answer,maps[i].second,cnt);
            // if(res.second) results.push_back(res.first);
             dfs1(answer,maps[i].second,cnt);
        }
    }

    auto it = s.begin();

    return *it;
}


// [["ICN", "AAA"], ["ICN", "CCC"], ["CCC", "DDD"], ["AAA", "BBB"], ["AAA", "BBB"], ["DDD", "ICN"], ["BBB", "AAA"]]
// ["ICN","CCC","DDD","ICN","AAA","BBB","AAA"]


// [["ICN", "A"], ["A", "B"], ["A", "C"], ["C", "A"], ["B", "D"]]
// ["ICN", "A", "C", "A", "B", "D"]