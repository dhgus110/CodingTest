#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int pivot;
bool cmp(vector<int> const& a, vector<int> const& b) {
    if (a[pivot] == b[pivot]) return a[0] > b[0];
    else return a[pivot] < b[pivot];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    pivot = col - 1;
    sort(data.begin(), data.end(), cmp);

    for (auto d : data[row_begin - 1]) {
        answer += d % row_begin;
    }

    for (int i = row_begin; i < row_end; i++) {
        int s_i = 0;
        for (auto d : data[i]) {
            s_i += d % (i + 1);
        }
        answer ^= s_i;
    }

    return answer;
}