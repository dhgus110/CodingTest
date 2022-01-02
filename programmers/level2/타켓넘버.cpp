#include <string>
#include <vector>
#include <iostream>

using namespace std;

int _count = 0;
int _target;
void dfs(int sum,int depth, vector<int>& v){
    if(depth >= v.size()){
        if(sum == _target) _count++;

        return;
    }

    dfs(sum + v[depth], depth+1, v);
    dfs(sum - v[depth], depth+1, v);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    _target = target;
    dfs(0,0,numbers);
    answer=_count;
    cout<<endl<<answer;
    return answer;
}

int main(){
    solution({1, 1, 1, 1, 1},3);
}