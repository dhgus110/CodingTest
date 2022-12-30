#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int storey) {
	int answer = 0;
	int num = storey;
	while (storey != 0) {
		int curLength = to_string(storey).length();
		int curLength_10Power = pow(10, curLength - 1);
		int firstNum = storey / curLength_10Power;
		int pivot = 0;
		for (int i = 0; i < curLength; i++) pivot += pow(10, i);
		if (pivot*5 <= storey && storey != 5) { //자릿수가 3자리 수 일 때 555기준으로 검사
			storey = curLength_10Power * 10 - storey;
			answer += 1;
			cout <<"1 : "<< storey << " , " << answer << endl;
		}
		else {
			//answer += switchs(firstNum);
			answer += firstNum;
			storey -= firstNum * curLength_10Power;
			cout << "2 : " << storey << " , " << answer << endl;

		}
	}
	return answer;
}
