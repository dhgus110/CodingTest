#include <iostream>
#include <cstdlib>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    while( true)
    {
        int nextA = (a+1) /2;
        int nextB = (b+1) /2;
        if(nextA == nextB) break;
        a = nextA;
        b = nextB;
        ++answer;
    }
    return answer;
    
}
