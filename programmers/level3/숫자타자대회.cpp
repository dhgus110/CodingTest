#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

//int num[4][3] = { 1,2,3,
//				  4,5,6,
//				  7,8,9,
//				  10,0,11 };

int left = 4;
int right= 6;
string number;
int numSize;
//bool visited[100'000];
vector<pair<int, int>> num;

int cal(int x1, int y1, int x2, int y2) {
	int cx = abs(x1 - x2);
	int cy = abs(y1 - y2);

	if (cx == 0 && cy == 0) return 1;
	if ((cx == 1 && cy == 0) || (cx == 0 && cy == 1))return 2;
	if ((cx == 1 && cy == 1))return 3;
	if ((cx == 2 && cy == 0) || (cx == 0 && cy == 2))return 4;
	if ((cx == 1 && cy == 2) || (cx == 2 && cy == 1))return 5;
	if ((cx == 2 && cy == 2) || (cx == 3 && cy == 0))return 6;
	if ((cx == 3 && cy == 1))return 7;
}

int update(int pos, int gavity, int l, int r) {
	if (pos == numSize)return gavity;
	int cur = number[pos] - '0';
	int curx = num[cur].first, cury = num[cur].second; //현재 가야하는 좌표
	int lx = num[l].first, ly = num[l].second; //현재 왼손 좌표
	int rx = num[r].first, ry = num[r].second; //현재 오른손 좌표


}

int solution(string numbers) {
	int answer = 0;
	
	//init
	num.push_back({ 4,2 }); // 0에 대한 좌표 먼저 저장
	for (int x = 1; x <= 3; x++) { //1~9 좌표
		for (int y = 1; y <= 3; y++) {
			num.push_back({ x,y });
		}
	}
	number = numbers;
	numSize = numbers.length();

	update(0, 0, 4, 6);

	return answer;
}