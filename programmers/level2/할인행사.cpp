#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool search(int i, vector<string>& want, vector<int> number, vector<string>const& discount) {
    int count = 0;
    for (int j = 0; j < 10; j++) {
        vector<string>::iterator iter = find(want.begin(), want.end(), discount[i + j]);
        //discount[i+j]�� want�߿� ���� ���
        if (iter != want.end()) {
            number[iter - want.begin()]--; //number�� ������� want�� ������ ��Ÿ���Ƿ� discount[i+j]�� �ش��ϴ� �ſ� -1 ����
            if (number[iter - want.begin()] == 0)
                count++;
        }
    }
    if (count == want.size()) return true;
    else return false;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    for (int i = 0; i < discount.size() - 9; i++) {
        if (search(i, want, number, discount))
            answer++;
    }

    return answer;
}