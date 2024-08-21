//백준 1717번
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int a){
    if(parent[a] != a) return find(parent[a]);
    else return a;
}

void unionfunc(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b) parent[b] = a;
}

bool checkSame(int a, int b){
    a = find(a);
    b = find(b);

    if(a==b) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);

    // 1. 각 노드가 모두 대표 노드
    for(int i = 0 ; i <= n ; i++){
        parent[i] = i;
    }

    for (int i = 0; i < m; i++){
        int type, a, b;
        cin >> type >> a >> b;
        
        if(type == 0) unionfunc(a,b);
        else {
            if(checkSame(a,b)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}