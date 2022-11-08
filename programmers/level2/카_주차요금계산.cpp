#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//차량 번호 순 우선, 시간 순
bool cmp(const string& a, const string& b) {
    int numa = (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[3] - '0') * 10 + (a[4] - '0');
    int numb = (b[0] - '0') * 1000 + (b[1] - '0') * 100 + (b[3] - '0') * 10 + (b[4] - '0');

    string cara;
    cara += a[6];
    cara += a[7];
    cara += a[8];
    cara += a[9];

    string carb;
    carb += b[6];
    carb += b[7];
    carb += b[8];
    carb += b[9];

    if (cara == carb) return numa < numb;
    else return cara < carb;
}

int minCeil(int n) {
    int minute = n / 100 * 60 + n % 100;  // 500(05:00) -> 300분
    int ceil = minute % 10 == 0 ? minute : (minute / 10) * 10 + 10; //1의 자리 올림

    cout << "누적 : " << n << " min : " << minute << " ceil : " << ceil;
    return ceil;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    sort(records.begin(), records.end(), cmp);

    for (auto r : records) cout << r << endl;
    cout << "기본시간 :" << fees[0] << "  기본요금 :" << fees[1] << "  단위시간 :" << fees[2] << "  단위요금 :" << fees[3] << endl;

    string beforecar = "";
    beforecar += records[0][6];
    beforecar += records[0][7];
    beforecar += records[0][8];
    beforecar += records[0][9];

    vector<vector<int>> recordTimes;

    int car = 0, cnt =0;
    for (auto r : records) {
        string curcar;
        curcar += r[6];
        curcar += r[7];
        curcar += r[8];
        curcar += r[9];

        int t = (r[0] - '0') * 1000 + (r[1] - '0') * 100 + (r[3] - '0') * 10 + (r[4] - '0');

        if (curcar == beforecar)
        {
            recordTimes[car].push_back(t);
            cnt++;
        }
        else
        {
            if(cnt %2 != 0)
                recordTimes[car].push_back(2359); //출차하지 않았다면 23:59 추가
            cnt = 0;
            recordTimes[++car].push_back(t);
        }
        beforecar = curcar;
    }

    for (auto r : recordTimes) {
        int accumulatedTime = 0;
        for (int i = r.size(); i > 0; i-=2) {
            accumulatedTime += (r[i] - r[i - 1]);
        }

        int fee = fees[1] + (minCeil(accumulatedTime) - fees[0]) / fees[2] * fees[3];
        answer.push_back(fee);
    }

    return answer;
}   

int main() {
    vector<vector<int>> a;
    a[0].push_back(1);
    a[0].push_back(1);
    a[1].push_back(2);
    a[1].push_back(2);
    a[1].push_back(2);


    for (auto aa : a) {
        for (auto aaa : aa)
            cout << aaa<<" ";
        cout << endl;
    }



}