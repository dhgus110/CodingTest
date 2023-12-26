#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int sum[MAX][2] ={0};
    int size = money.size();

    //3번째 자리까지 비교하기 위해 맨앞에 0이 필요함
    vector<int> m1 ; //  money 앞에 0 을 붙임 , 원형탐색이므로 맨 뒤에는 탐색 ㄴㄴ
    m1.push_back(0);
    m1.insert(m1.end(),money.begin(),money.end());

    vector<int> m2(money.begin(),money.end()); // money[0]을 0으로 바꿈 <- 처음 탐색ㄴㄴ
    m2[0]=0;

    //초기화
    for(int i = 0; i <2 ; i++){
        sum[i][0]= m1[i];
        sum[i][1]= m2[i];
    }
    for(int i =2 ; i<size ; i++){
        sum[i][0] = max(sum[i - 1][0], sum[i - 2][0] + m1[i]);
        sum[i][1] = max(sum[i - 1][1], sum[i - 2][1] + m2[i]);
    }

    answer = max(sum[size - 1][0], sum[size - 1][1]);
    return answer;
}

// class Solution {
//     public int solution(int[] money) {
//         if(money.length==3) return Math.max(money[0],Math.max(money[1],money[2]));
//         int [][]dp = new int[2][money.length];
//         dp[0][0]=money[0];dp[0][1]=money[0];dp[0][2]=Math.max(dp[0][1],dp[0][0]+money[2]);
//         dp[1][1]=money[1];dp[1][2]=Math.max(dp[1][1],money[2]);
//         for(int i=3;i<money.length-1;i++){
//             dp[0][i]=Math.max(dp[0][i-1],dp[0][i-2]+money[i]);
//             dp[1][i]=Math.max(dp[1][i-1],dp[1][i-2]+money[i]);
//         }
//         dp[1][money.length-1]=Math.max(dp[1][money.length-2],dp[1][money.length-3]+money[money.length-1]);

//         return Math.max(dp[0][money.length-2],dp[1][money.length-1]);
//     }
// }


// int solution(vector<int> money) {
//     int answer = 0;
//     int sum[MAX][3];
//     int size = money.size();
//     if(size<=3){
//         return max(money[0],max(money[1],money[2]));
//     }else if (size<=4){
//         return max(money[0]+money[2],money[1]+money[3]);
//     }
    
//     for(int start =0 ; start <3 ; start++){
//         sum[start][start] = money[start];
//         sum[start + 1][start] = money[start + 1];
//         sum[start + 2][start] = money[start + 2];
//     }

//     for (int i = 3; i < size; i++){
//         sum[i][0] = max(sum[i - 1][0], max(sum[i - 2][0] + money[i], sum[i - 3][0] + money[i]));
//         if (i < size - 1) sum[i + 1][1] = max(sum[i][1], max(sum[i - 1][1] + money[i], sum[i - 2][1] + money[i]));
//         if (i < size - 2) sum[i + 2][2] = max(sum[i + 1][2], max(sum[i][2] + money[i], sum[i - 1][2] + money[i]));
//     }

//     answer = max(sum[size - 1][0], max(sum[size - 1][1], sum[size - 1][2]));

//     return answer;
// }


