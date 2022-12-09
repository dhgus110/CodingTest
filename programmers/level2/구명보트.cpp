#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(),people.end());

    int right = people.size()-1;
    int left = 0;
    while(left<=right){
        answer+= 1;
        if(people[right]+people[left] <= limit){
            left++;
            right--;
        }
        else{
            right--;
        }

    }

    return answer;
}
