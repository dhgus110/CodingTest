#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(),targets.end());
    int e =targets[0][1];

    for(auto ta : targets){
        if(e >ta[0] && e>ta[1]){
            e= ta[1];
        }
        else if(e <= ta[0]){
            answer++;
            e = ta[1];
        }
    }
    
    return answer;
}
