#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#define ll long long

using namespace std;

int visit[10'000];

void check(string s, int parent, int curLevel, bool parentZero, int order) {
    if (curLevel == 1) return;
    int leftNode = parent - pow(2, curLevel - 2);
    int rightNode = parent + pow(2, curLevel - 2);
    if (parentZero) {
        if (s[leftNode - 1] == '0' && s[rightNode - 1] == '0') {

        }
        else {
            visit[order] = 0;
        }
    }
    else if (s[parent - 1] == '0') {
        if (s[leftNode - 1] == '0' && s[rightNode - 1] == '0') {
            parentZero = true;
        }
        else {
            visit[order] = 0;
        }
    }
    check(s, leftNode, curLevel - 1, parentZero, order);
    check(s, rightNode, curLevel - 1, parentZero, order);
}

void perfectBinaryTreeTranslation(ll number, int order) {
    string res = "";
    int cnt = 0;
    int treeLevel = 1, exp = 1;
    while (number!=0)
    {
        if (number == 1) {
            res += "1";
            cnt += 1;
            break;
        }
        res+=to_string(number % 2);
        number /= 2;
        cnt += 1;

        int curLevel = pow(2, exp);
        if (cnt % curLevel == 0) {
            treeLevel += 1;
            exp += 1;
        }
    }

    //포화이진트리만들기
    int supplementCnt = pow(2, treeLevel) - 1 - cnt;
    for (int i = 0; i < supplementCnt; i++)
        res += "0";
    //reverse(res.begin(), res.end());  //굳이 할 필요 없이 탐색 가능 
    int rootNode = pow(2, treeLevel) / 2;
    check(res, rootNode, treeLevel, false, order);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    fill_n(visit, 10'000, 1);

    for (int i = 0; i < numbers.size(); i++) {
        perfectBinaryTreeTranslation(numbers[i], i);
        answer.push_back(visit[i]);
    }

    return answer;
}
