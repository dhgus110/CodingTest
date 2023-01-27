#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int d[1001] = { 0 };
int d3[4001] = { 0 };

long long solution(vector<int> weights) {
    long long answer = 0;
    map <int, vector<int>>m;
    for (auto w : weights) {
        if (d[w]++ > 0)answer += 1;
    }
    for (int i = 100; i <= 1000; i++) {
        if (d[i] > 0) {
            d3[i * 2]++;
            d3[i * 3]++;
            d3[i * 4]++;
        }
    }
    for (int i = 200; i <= 4000; i++) {
        if(d3[i]>1)
            answer += d3[i] - 1;
    }

    return answer;
    //for (int num = 100; num <= 1000; num++) {
    //    if (d[num] == 0)continue;
    //    for (int a = 2; a <= 4; a++) {
    //        int numA = num * a;
    //        for (int b = 2; b <= 4; b++) {
    //            if (a == b)continue;
    //            if (numA % b != 0)continue;
    //            auto it = m.find(num);
    //            if (it != m.end()) {
    //                auto vec = it->second;
    //                bool check = false;
    //                for (auto v : vec) {
    //                    if (v == numA / b) {
    //                        check = true;
    //                        break;
    //                    }
    //                }
    //                if (check) continue;
    //            }
    //            if ((numA / b) <= 1000 && d[numA / b] > 0) {
    //                answer += d[numA / b];
    //                m[numA / b].push_back(num);
    //                cout << num << " " << numA / b << endl;
    //            }
    //        }
    //    }
    //}
    //for (auto it = m.begin(); it != m.end(); it++) {
    //    cout << it->first << " :";
    //    for (auto i : it->second) cout << i << " ";
    //    cout << endl;
    //}
    //return answer;
}