/*1 ≤ r1 < r2 ≤ 1,000,000
r= 10, y=1 일때  x의 값은?
x^2 = 10^2 - 1^2
*/
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int h = 0; h < r2; h++){
        int outVertexX1 = r1 > h ? ceil(sqrt(pow(r1, 2) - pow(h, 2))) : 0;
        int inVectexX2 = floor(sqrt(pow(r2,2)-pow(h,2)));
        // cout << inVectexX2 << ", " << outVertexX1 << " =" << (inVectexX2 - outVertexX1 + 1) << endl;
        answer += (inVectexX2 - outVertexX1);
        if(outVertexX1 >0) answer+=1;
    }

    return answer * 4;
}
