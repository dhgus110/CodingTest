#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool search(int i, vector<string>& want, vector<int> number, vector<string>const& discount) {
    int count = 0;
    for (int j = 0; j < 10; j++) {
        vector<string>::iterator iter = find(want.begin(), want.end(), discount[i + j]);
        //discount[i+j]가 want중에 있을 경우
        if (iter != want.end()) {
            number[iter - want.begin()]--; //number는 순서대로 want의 수량을 나타내므로 discount[i+j]에 해당하는 거에 -1 해줌
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