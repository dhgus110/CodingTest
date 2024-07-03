#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(int n ,int i ,int j ,int k ,vector<vector<int>>& triangle){
    triangle[i][j] =n;
    //방향 : 좌변 -> 아랫변 -> 우변
    int nexti[] = {i + 1, i, i - 1};
    int nextj[] = {j, j + 1, j - 1};
    int kk = (k + 1) % 3;
    if (nexti[k] < triangle.size() && triangle[nexti[k]][nextj[k]] == -1)
        dfs(n+1,nexti[k],nextj[k],k,triangle);
    else if (triangle[nexti[kk]][nextj[kk]] == -1)
        dfs(n+1,nexti[kk],nextj[kk],kk,triangle);

}

vector<int> solution(int n) {
    vector<vector<int>> triangle(n);
    for(int i = 0 ; i<n ; i++)
        triangle[i] = vector<int>(i+1,-1);
    
    dfs(1,0,0,0,triangle);

    vector<int> answer;
    for(auto tr :triangle){
        for(auto t: tr){
            answer.push_back(t);
        }
    }
    return answer;
}