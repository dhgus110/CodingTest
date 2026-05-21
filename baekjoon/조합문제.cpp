/*
[문제]
정수를 문자열로 변환하여 특별한 규칙에 따라 순서대로 나열할 때, k번째 문자열을 구하여라.

[정렬 규칙]

자릿수가 작은 문자열이 더 앞에 온다
자릿수가 같으면 수의 크기가 작은 문자열이 더 앞에 온다

"7" < "01"   → 자릿수 1 < 2 이므로 "7"이 앞
"12" < "13"  → 자릿수 같고 12 < 13 이므로 "12"가 앞

[유효한 문자열 조건]
왼쪽에서 오른쪽으로 읽을 때, 각 자리의 숫자는 왼쪽 숫자보다 반드시 커야 한다
"01"  → 0 < 1  ✅ 유효
"12"  → 1 < 2  ✅ 유효
"21"  → 2 > 1  ❌ 무효
"11"  → 1 = 1  ❌ 무효
"013" → 0<1<3  ✅ 유효

[입력]
정수 k (1 ≤ k ≤ 1,000,000,000)

[출력]
k번째 문자열을 출력한다.
단, k번째 문자열이 존재하지 않으면 -1을 출력한다.

[예시]
k출력1"0"10"9"11"01"999,999,999-1

*/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string strData[1024];
int dataIndex = 0 ;

void storeData(string current, int last)
{
    if(!current.empty()) 
        strData[dataIndex++] = current;
    for(int i = last; i <= 9 ; ++i)
        storeData(current + (char)('0' + i), i + 1);
}

string solution(int k)
{
    if(k >= 1024) return "-1";

    storeData("",0);
    sort(strData, strData + dataIndex, [](const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });
    
    return strData[k - 1];
}


int main()
{
    solution(10);
}