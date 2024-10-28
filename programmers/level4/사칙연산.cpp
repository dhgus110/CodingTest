#include <vector>
#include <string>
#include <algorithm>

#define _MIN 0
#define _MAX 1

using namespace std;

//동적계획법
int solution(vector<string> arr)
{
    int answer = -1;
    int backSum[2] , sum = 0;

    for(int i = arr.size()-1 ; i >=0; i--){
        //범위 1~1000
        if(arr[i][0]>'0')
        {
            sum+= stoi(arr[i]);
        }
        // 연산자 '-'일 때만 
        else if(arr[i]=="-")
        {
            int curMin = backSum[_MIN], curMax = backSum[_MAX];
            backSum[_MIN] = min((sum + curMax) * (-1), curMin - sum);
            backSum[_MAX] = max(sum + curMax - stoi(arr[i + 1]) * 2, (sum + curMin) * (-1));
            sum =0;
        }
    }
    answer = sum + backSum[_MAX];
    return answer;
}
// 최솟값- 전부 마너이스 or sum만 마이너스 + backsum[min] 
// 최대값- 첫 항만 마이너스 그리고 전부 + , (sum + backsum[min]) * -1 ? 
