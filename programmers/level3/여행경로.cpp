#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

vector<pair<vector<string>,int>> maps; //[[start, dest], order]

pair<vector<string>,bool> dfs(vector<string> result, int order, vector<int> cnt){
    vector<pair<vector<string>,bool>> fork;
    string nextCity = maps[order].first[1];
    result.push_back(nextCity);
    cnt[order] =0;

    int sum =accumulate(cnt.begin(),cnt.end(),0);

    //     for(auto r :result){
    //     cout<< r << " ";
    // }cout<<sum<<endl;

    if(sum==0) return make_pair(result,true);

    for(int i = 0 ;i<maps.size() ; i++){
        if (cnt[maps[i].second] == 1 && maps[i].first[0] == nextCity){
            fork.push_back(dfs(result,maps[i].second,cnt));
        }
    }

    for(auto f : fork){

        return f;
    }

    return make_pair(result,false);
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
            pair<vector<string>,bool> res = dfs(answer,maps[i].second,cnt);
            // for(auto r : res.first){
            //     cout<< r<<" ";
            // }cout<<endl;
            if(res.second) results.push_back(res.first);
        }
    }
    results.push_back({"ZZZ"});
    sort(results.begin(),results.end());

    return results[0];
}


// [["ICN", "AAA"], ["ICN", "CCC"], ["CCC", "DDD"], ["AAA", "BBB"], ["AAA", "BBB"], ["DDD", "ICN"], ["BBB", "AAA"]]
// ["ICN","CCC","DDD","ICN","AAA","BBB","AAA"]


// [["ICN", "A"], ["A", "B"], ["A", "C"], ["C", "A"], ["B", "D"]]
// ["ICN", "A", "C", "A", "B", "D"]