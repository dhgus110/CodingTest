#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;
    unordered_map<string, int> hash;
    for (auto const &p : clothes)
        ++hash[p[1]];
    

    int n = 1;
    for (auto const &h : hash)
        n *= (h.second+1);

    answer=n-1;
    return answer;
}
//(한 옷의 종류수 + 1(안입는경우의수))* (한 옷의 종류수 + 1(안입는경우의수)) -(아무것도 안 입는경우의수)