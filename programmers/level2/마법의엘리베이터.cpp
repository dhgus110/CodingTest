#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int storey) {
	int answer = 0;
	string dummy = to_string(storey);
	int curLength = dummy.length();
	int preButton = 0;
	int preStore = 0;
	while (curLength != 0)
	{
		
		int curLength_10Power = pow(10, curLength - 1);
		int firstNum = storey / curLength_10Power;
		if (dummy[0] == '9' && dummy[1] == '5') { //953 �̸� (100 - 953 = 47)
			storey = curLength_10Power * 10 - storey;
			answer += 1;
			cout << "1���� s: " << storey <<"len : "<<curLength<<" anw : " << answer << endl;
		}
		else if (curLength_10Power * 6 - 1 < storey) {
			storey += (10 - firstNum) * curLength_10Power - curLength_10Power * 10;
			answer += (10 - firstNum) + 1;
			preStore = (10 - firstNum) + 1;
			if (preButton - curLength_10Power * 10 == 0) answer -= 2; // -10 and 10�� ������ ��� ���
			if (dummy[0] == '9')preButton = curLength_10Power;
			cout << "2���� s: " << storey << " ��ư: " << (10 - firstNum) * curLength_10Power << " ," << -curLength_10Power * 10 << " anw : " << answer << endl;

		}
		else {
			storey += -firstNum * curLength_10Power;
			answer += firstNum;
			preStore = firstNum;
			cout << "3���� s: " << storey << " ��ư: " << -firstNum * curLength_10Power << " anw : " << answer << endl;

		}
		dummy = to_string(storey);
		curLength -= 1;
	}

	return answer;
}
