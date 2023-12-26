#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int cameraPos = routes[0][1];

    for(int i= 1; i<routes.size() ;i++){
        if(cameraPos < routes[i][0]){
            cameraPos =routes[i][1];
            answer++;
        }
    }

    return answer;
}

