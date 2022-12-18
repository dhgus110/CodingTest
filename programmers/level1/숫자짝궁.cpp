#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
	int numX[10] = { 0 }, numY[10] = { 0 }, numXY[10] = { 0 };

    for (auto x : X) {
        numX[x - '0']++;
    }
    for (auto y : Y) {
        numY[y - '0']++;
    }

    for (int i = 0; i <= 9; i++) {
        if (numX[i] == 0 || numY[i] == 0) numXY[i] = 0;
        else numXY[i] = numX[i] < numY[i] ? numX[i] : numY[i];
    }

    bool check = false;
    for (int i = 9; i >=0; i--) { 
        if (i == 0 && numXY[i] > 0 && !check) {
            return "0";
        }
        if (numXY[i] > 0) {
            check = true;
            for (int j = 0; j < numXY[i]; j++) {
                answer.push_back(i+'0');
            }
		}
       
    }
    if (!check) return "-1";

    return answer;
}