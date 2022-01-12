#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

//문제 : 개미 전사 
int solution1(vector<int> store){
    int answer = 0;
    vector<int> dp(store.size());
    dp[0] =store[0];
    dp[1] = max(store[0], store[1]);

    for(int  i = 2; i<store.size() ; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + store[i]);
    }

    answer = dp.back();
    return answer;
}

//문제 : 1로 만들기
int dp2[30000];
int solution2(int x){
    int answer  = 0;
    for(int i = 2 ; i <=x ; i++){
        dp2[i] = dp2[i-1] +1; //1을 뺸 경우
        if (i % 2 == 0) dp2[i]=min(dp2[i], dp2[i / 2] + 1);
        if (i % 3 == 0) dp2[i]=min(dp2[i], dp2[i / 3] + 1);
        if (i % 5 == 0) dp2[i]=min(dp2[i], dp2[i / 5] + 1);
    }
    answer = dp2[x];
    return answer;
}


//문제 : 효율적인 화폐 구성
//dp[i] 는  금액 i를  만들 수 있는 최소한의 화폐 갯수
//money는 각 화폐 종류
//점화식 : 각 화폐의 종류를 하나씩 확인하여 만들기
int dp3[10001];
int tar;
vector<int> mo;
void dynamic3(int cur){
    if(cur > tar) return ;
    for(auto m : mo){
        if(dp3[cur+m]!= 0) dp3[cur + m] = min(dp3[cur] + 1, dp3[cur + m]);
        else dp3[cur+m] = dp3[cur]+1;
        dynamic3(cur+m);
    }
}

int solution3(vector<int> money, int target){
    tar = target;
    mo =money;
    dynamic3(0);

    if(dp3[target]==0 ) return -1;
    return dp3[target];
}


//문제 : 금광
int dp4[20][20];
int solution4(int n ,int m , vector<vector<int>> board){
    int answer = 0;
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            dp4[y][x] = board[y][x];
        }
    }

    for(int x = 0 ; x < m ; x++){
        for (int y = 1; y < n; y++){
            if(y==0) dp4[y][x] += max(dp4[y-1][x],dp4[y-1][x+1]);
            else if(y == m-1) dp4[y][x] += max(dp4[y-1][x-1],dp4[y-1][x]);
            else dp4[y][x] += max(dp4[y - 1][x - 1], max(dp4[y-1][x], dp4[y - 1][x + 1]) );
        }
    }
    for(int i = 0 ;i<n;i++){
        answer = answer<dp4[i][m-1] ? dp4[i][m-1] : answer;
    }

    return answer;

}


int main(){
    // cout<<solution2(8)<<endl;
    // cout<< solution3({2,3},15)<<endl;
    cout <<solution4(4,3,{{1,2,0},{3,1,6},{3,4,4},{2,1,7}});
}
