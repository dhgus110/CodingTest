#include <string>
#include <vector>

using namespace std;

//최대공약수
int GCD(int a, int b)
{
    if( b == 0) return a;
    return GCD(b, a % b);
}

//최소공배수
int LCM(int a, int b)
{
    return a*b / GCD(a,b);
}

int solution(vector<int> arr) {
    int answer = arr[0];

    for(size_t i = 1 ; i < arr.size() ; ++i)
        answer = LCM(answer, arr[i]);
    
    return answer;
}