#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmpValue(pair<string,int> a, pair<string,int> b){
    return a.second>b.second;
}

bool cmpVector(pair<int,int> a, pair<int,int>b){
    if(a.first ==b.first) return a.second<b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> result;

    unordered_map<string, vector<pair<int,int>>> map1; // map1 < 장르 , vector<횟수 up,번호 down> >
    unordered_map<string ,int> map2; // map2 <장르, 총 재생횟수> 
    
    for(int i = 0 ;i <genres.size(); i++){
        map1[genres[i]].push_back({plays[i], i});
        map2[genres[i]] += plays[i];
    }

    vector<pair<string,int>> v(map2.begin(),map2.end());
    sort(v.begin(),v.end(),cmpValue);

    for (auto gen : v){
        sort(map1[gen.first].begin(),map1[gen.first].end(),cmpVector);
        result.push_back(map1[gen.first][0].second);
        if(map1[gen.first].size()>1)
            result.push_back(map1[gen.first][1].second);
    }
    return result;
}


// 정보 : 장르 음악번호 횟수    총 재생횟수 ? 
// 장르에 따른 map 동적 생성 ?
// map1 < 장르 ,  vector<횟수 up,번호 down> >

// map2 <장르, 총 재생횟수 up> 
