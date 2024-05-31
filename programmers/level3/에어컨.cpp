#include <string>
#include <vector>
#include <iostream>
#define INF 1e9

using namespace std;

int dp[1000][52]; //[현재시간][온도] = 전력
int wishT1, wishT2; //희망온도
int outdoorTemperature; //실외온도 <- 쉽게 풀기 위해 0으로 맞춤 
//에어컨 트는 행위를 온도를 올리거나 유지하는 행위로 단순화  -> 실외온도를 t1 아래로 위치 시키고 실외온도를 0으로
// 0 ~ wishT2 사이 온도만 생각한다.
//온도 올리기  a
//온도 내리기  b
//온도 유지 0

void init(const int temperature, const int t1, const int t2){
    fill_n(&dp[0][0], 1000 * 52, INF);
    dp[0][0] = 0;
    outdoorTemperature = temperature > t2 ? t1 - (temperature - t2) : temperature;
    wishT1 = t1 - outdoorTemperature;
    wishT2 = t2 - outdoorTemperature;
    outdoorTemperature = 0;
}

//희망온도인가?
bool isDesiredTemperature(int t){
    return wishT1 <= t && wishT2 >= t;
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard)
{
    int answer = INF;
    init(temperature,t1,t2);

    for (int time = 1; time < onboard.size() ; time++){
        for (int temp = 0; temp <= wishT2 + 1; temp++)
        {
            //탑승 중일 때 실내 온도가 희망 온도가 아니라면 지나가기.
            if (onboard[time] && !isDesiredTemperature(temp)) continue;

            int minVal = INF;
            //실외 온도 == 희망 온도 일 때
            if (temp == 0){
                //온도 올림
                //온도 유지
                minVal = min(minVal, dp[time - 1][temp]);
                //온도 내림
                if (temp + 1 <= wishT2 + 1) minVal = min(minVal, dp[time - 1][temp + 1]);
            }
            //실외 온도 != 희망온도
            else{
                //온도 올림
                if (temp - 1 >= 0) minVal = min(minVal, dp[time - 1][temp - 1] + a);
                //온도 유지
                minVal = min(minVal, dp[time - 1][temp] + b);
                //온도 내림
                if (temp + 1 <= wishT2 + 1) minVal = min(minVal, dp[time - 1][temp + 1]);
            }
            dp[time][temp] =minVal;
        }
    }
    for (int temp = 0; temp <= wishT2 + 1; temp++)
        answer = min(answer, dp[onboard.size()-1][temp]);

    return answer;
}