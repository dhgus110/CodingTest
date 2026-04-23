#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    if(a.size()<=2) return a.size();
    
    int answer = 2;
    vector<int> l(a.size());
    vector<int> r(a.size());
    int minL = a[0], minR = a[a.size()-1];
    
    int rIndex = a.size() - 2;
    for(int i = 1; i < a.size()-1; ++i)
    {
        l[i] = minL;
        minL = min(minL, a[i]);
        r[rIndex] = minR;
        minR = min(minR, a[rIndex--]);
    }
    
    for(int i = 1; i < a.size()-1; ++i)
    {
        if(l[i] < a[i] && r[i] < a[i]) continue;
        ++answer;
    }
    
    return answer;
}


/*
[-16,27,-2,58,-92,-71,-68,-61,-33]
작아야 생존가능.
1. 양쪽 끝은 살 수 있음.
2. 가운데 원소들은. 좌 우 그룹 나누고. 양쪽 최소값을 구해서.
3. 그 원소는 좌,우 그룹의 최소값들보다 크면 ㅂ2
4. 나머지는 생존
*/
