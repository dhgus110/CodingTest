#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxAbilitys = -1;

void print(vector<int>v){
    for(auto vv:v){cout<<vv<<" ";}cout<<endl;
}

void dfs(int sum, int cur, vector<int> order, vector<vector<int>>const& ability,int n){
    if(cur == ability.size()){
        maxAbilitys = max(maxAbilitys, sum);
        print(order);
    }

    for (int i = 0; i < ability[0].size(); i++){
        if(order[i]>0)continue;
        order[i]=n;
        dfs(sum+ability[cur][i], cur + 1, order, ability, n+1);
    }

}

int solution(vector<vector<int>> ability) {
    int gap =ability.size()-ability[0].size();
    for(int i= 0 ; i<ability.size();i++){
        for (int j = 0; j < gap; j++){
            ability[i].push_back(0);
        }
    }

    for (int i = 0; i < ability[0].size(); i++){
        vector<int> order(ability[0].size(),0);
        order[i]=1;
        dfs(ability[0][i], 1, order, ability, 2);
    }

    return maxAbilitys;
}