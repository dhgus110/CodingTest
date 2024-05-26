#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//투 포인터 ,슬라이딩 윈도우 
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int,int>> kCollection;

    int size = sequence.size();
    int lHandle = 0,rHandle = 0 ;
    int minL = 0 , minR = size-1;
    int sum = sequence[0];

    while(lHandle < size){
        if( sequence[rHandle]> k) break;

        if( sum == k){
            if((rHandle - lHandle) < (minR-minL)) {
                minL = lHandle;
                minR = rHandle;
            }
            if(rHandle + 1 < size) sum += sequence[++rHandle];
            else sum -= sequence[lHandle++];
        }
        else if ( sum < k){
            if (rHandle + 1 < size) sum += sequence[++rHandle];
            else break;
        }
        else{
            sum -= sequence[lHandle++];
        }

    }

    answer.push_back(minL);
    answer.push_back(minR);

    return answer;
}