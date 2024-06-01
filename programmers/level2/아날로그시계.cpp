#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v_toHms(int sec) {
    vector<int> dummy;
    dummy.push_back(sec / 3600);
    sec %= 3600;
    dummy.push_back(sec / 60);
    sec %= 60;
    dummy.push_back(sec);
    return dummy;
}

int toSeconds(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

double toHourAngle(vector<int> v){
    return (double)(v[0] >= 12 ? v[0] - 12 : v[0]) * 30 + (double)v[1] / 2 + (double)v[2] / 120;
}

double toMinuteAngle(vector<int> v) {
    return (double)v[1] * 6 + (double)v[2] / 10;
}

double toSecondAngle(vector<int> v) {
    return v[2] * 6;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    int start = toSeconds(h1, m1, s1);
    int end = toSeconds(h2, m2, s2);

    vector<int> table(toSeconds(23, 59, 59) + 1);

    for (int i = 0; i <= end; i++) {
        int cnt = 0;

        vector<int> cur = v_toHms(i);
        double hAngle = toHourAngle(cur);
        double mAngle = toMinuteAngle(cur);
        double sAngle = toSecondAngle(cur);

        vector<int> next = v_toHms(i + 1);
        double n_hAngle = toHourAngle(next);
        double n_mAngle = toMinuteAngle(next);
        double n_sAngle = toSecondAngle(next);
        
        // 1초 단위는 초심이 6도만큼 이동함으로 예외처리 초심앵글이 354도에서 예외처리
		if (sAngle < mAngle && n_sAngle >= n_mAngle) cnt++;
		else if (sAngle == 354 && mAngle > 354) cnt++;
		if (sAngle < hAngle && n_sAngle >= n_hAngle) cnt++;
		else if (sAngle == 354 && hAngle > 354) cnt++;

        table[i + 1] = cnt;
    }

    //자정과 정오는 시침, 분침, 초침 딱 맞물리는 시간
    table[toSeconds(0, 0, 0)] = 1;
    table[toSeconds(12, 0, 0)] = 1;

    if (start == toSeconds(0, 0, 0) || start == toSeconds(12, 0, 0)) answer++;
    for (int i = start +1 ; i <= end; i++) {
        answer += table[i];
    }

    return answer;
}
