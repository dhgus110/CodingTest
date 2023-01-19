#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#define ll long long

using namespace std;

string perfectBinaryTreeTranslation(ll number) {
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

    //��ȭ����Ʈ�������
    int supplementCnt = pow(2, treeLevel) - 1 - cnt;
    for (int i = 0; i < supplementCnt; i++)
        res += "0";
    //reverse(res.begin(), res.end());  //���� �� �ʿ� ���� Ž�� ���� 
    //for (int i = 1; i < res.length(); i += 2) {
    //    if (res[i] == '0') { //�θ��尡 0�� ��
    //        if (res[i - 1] == '0' && res[i + 1] == '0')continue; //�ڽĳ��鵵 0�̸� ok
    //        else return "fail";
    //    }
    //}

    int rootNode = pow(2, treeLevel) / 2;
    int visit[47] = { 0 };
    return res;
}

//todo �ڽĳ�� dfs�� Ȯ���ؾ���
void check(string s, int parent, int level) {
    if (level == 1) return;

}


vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (auto n : numbers) {
        if (perfectBinaryTreeTranslation(n) == "fail")answer.push_back(0);
        else answer.push_back(1);
    }

    return answer;
}