#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    unordered_map<string, int> m ; // <종류, 가짓수>
    for(auto c : clothes){
        ++m[c[1]];
    }
    int result =1;
    for( auto num : m ){
        result += (num.second+1);
    }
    
    return result -1;
}
