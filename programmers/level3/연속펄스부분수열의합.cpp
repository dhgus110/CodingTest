#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
long long prefixSum[500'001];

long long solution(vector<int> sequence) {
    long long answer, prefixSumOfMaxIndex, prefixSumOfMinIndex = 0;
    prefixSum[0] = prefixSumOfMaxIndex = prefixSumOfMinIndex = sequence[0];

    for (int i = 1; i < sequence.size(); i++){
        prefixSum[i] = prefixSum[i - 1] + sequence[i] * (i % 2 ? -1 : 1);
        if (prefixSumOfMaxIndex < prefixSum[i])
            prefixSumOfMaxIndex = prefixSum[i];
        if (prefixSumOfMinIndex > prefixSum[i])
            prefixSumOfMinIndex = prefixSum[i];
    }

    //output
     for (int i = 0; i < sequence.size(); i++){
         cout<< prefixSum[i] << "  ";
     }
     cout<<endl<<prefixSumOfMaxIndex<<" "<<prefixSumOfMinIndex;

    answer = max(max(prefixSumOfMaxIndex - prefixSumOfMinIndex, prefixSumOfMaxIndex)
    , abs(prefixSumOfMinIndex));

    return answer;
}