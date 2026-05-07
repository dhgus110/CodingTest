#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int teamSize = A.size();
    
    int a = 0 ,  b = 0 ;
    while(a < teamSize && b < teamSize)
    {
        if(A[a] < B[b]){
            ++a;
            ++b;
            ++answer;
        }
        else
        {
            ++b;
        }
        
    }
    
    return answer;
}