#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left + 1; i < right + 2; i++) {
        int row;
        if (i < n) row = 1;
        else row = i / n + 1;
        if (row > n) row = n;
        
        int col = i % n == 0 ? n : i % n;
        if (i == 0) col = 1;
        cout <<"i:"<<i<<" "<< row << col << endl;
        answer.push_back(row > col ? row : col);
    }

    return answer;
}
