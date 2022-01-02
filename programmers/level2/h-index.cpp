#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(),citations.end(),greater<int>());
    for(int i : citations){
        if(answer+1<= i) answer++;
        else break;
    }
    return answer;
}