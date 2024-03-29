#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int max_answer = 0;
vector<int> arrA;
vector<int> arrB;

void find(int max, vector<int>& array, int a) {
    bool check = 0;
    for (int i = 2; i <= max; i++) {
        check = 1;
        for (int j : array) {
            if (j % i != 0 and check) {
                check = 0;
                break;
            }
        }
        if (check) {
            if (a) {
                arrA.push_back(i);
            }
            else {
                arrB.push_back(i);
            }
        }
    }
}

void max_find(vector<int>list, vector<int>& array) {
    bool check = 0;
    for (int i : list) {
        check = 1;
        for (int j : array) {
            if (j % i == 0 and check) {
                check = 0;
                break;
            }
        }
        if (check) {
            max_answer = max(max_answer, i);
        }
    }
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    find(arrayA[0], arrayA, 1);
    find(arrayB[0], arrayB, 0);
    max_find(arrA, arrayB);
    max_find(arrB, arrayA);

    return max_answer;
}