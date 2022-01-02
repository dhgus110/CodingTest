#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int visit[200][200];
int maxN;
vector<set<int>> group(200);

void init(int n, vector<vector<int>> c){
    for(int i = 0; i<n ;i++){
        for(int j = 0; j<n ; j++){
            visit[i][j] = c[i][j];
        }
    }

    maxN = n;
}

void dfs(int x, int y, int order){
    visit[x][y] = 0;

    group[order].insert(x);
    group[order].insert(y);
    
    for(int go = 0 ;go< maxN ; go++){
        if(visit[go][y]==1)
            dfs(go,y,order);
        if(visit[x][go]==1)
            dfs(x,go,order);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    init(n,computers);

    for(int x = 0; x< n ; x++){
        for(int y = 0 ; y<n; y++){
            if (visit[x][y] == 1)
            {
                dfs(x, y ,answer);
                answer++;
            }
        }
    }
    for(auto gr : group){
        for(auto g :gr){
            cout<<g<<" ";
        }cout<<endl;
    }

    return answer;
}

int main(){

    vector<vector<int>> v ;
    // v.push_back({1,0,1,0,0,0});
    // v.push_back({0,1,0,1,0,0});
    // v.push_back({1,0,1,0,0,0});
    // v.push_back({0,1,0,1,1,0});
    // v.push_back({0,0,0,1,1,0});
    // v.push_back({0,0,0,0,0,1});

    v.push_back({1, 1, 0, 1});
    v.push_back({1, 1, 0, 0});
    v.push_back({0, 0, 1, 1});
    v.push_back({1, 0, 1, 1});
    cout<< solution(4,v);
    
}

