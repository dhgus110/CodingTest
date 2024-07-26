#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool scoreBox[61];
pair<int,int> dp[100'001]; //(cnt, single & bull cnt)

void init(){
    fill_n(scoreBox, 61, false);
    fill_n(dp, 61, make_pair(0, 0));

    for (int i = 1; i <= 20; i++){
        scoreBox[i] = true;
        scoreBox[i * 2] = true;
        scoreBox[i * 3] = true;
    }
    scoreBox[50]=true;

    for(int i = 1 ; i <= 20; i++){
        dp[i * 2] = make_pair(1, 0);
        dp[i * 3] = make_pair(1, 0);
    }

    for(int i = 1 ; i <= 20; i++){
        dp[i] = make_pair(1, 1);
    }
    dp[50] = make_pair(1, 1);

    for(int i = 20 ; i<40 ; i++){
        if (dp[i].first == 0) dp[i] = make_pair(2, 2);
    }
    for(int i = 40 ; i<50 ; i++){
        if (dp[i].first == 0) dp[i] = make_pair(2, 1);
    }
    for(int i = 50 ; i<=60 ; i++){
        if (dp[i].first == 0) dp[i] = make_pair(2, 2);
    }
}

void run(){
    for (int n = 61; n < 100'001; n++){
        int cnt60 = dp[60].first + dp[n-60].first;
        int singleAndBull60 = dp[60].second + dp[n-60].second;
        int cnt50 = dp[50].first + dp[n-50].first;
        int singleAndBull50 = dp[50].second + dp[n-50].second;
        if(cnt50 < cnt60)
            dp[n] = make_pair(cnt50, singleAndBull50);
        else if(cnt50 > cnt60)
            dp[n] = make_pair(cnt60, singleAndBull60);
        else{
            if(singleAndBull50 < singleAndBull60)
                dp[n] = make_pair(cnt60, singleAndBull60);
            else
                dp[n] = make_pair(cnt50, singleAndBull50); 
        }
    }

}

vector<int> solution(int target) {
    vector<int> answer;
    init();
    run();
    answer.push_back(dp[target].first);
    answer.push_back(dp[target].second);

    return answer;
}