#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> matrix;

int rotation(vector<int> q) {
    vector<int> path;
    int x1 = q[0]-1, x2 = q[2]-1;
    int y1 = q[1]-1, y2 = q[3]-1;

    path.push_back(matrix[x1][y1]);
    //y1 row 
    for (int i = y1; i < y2; i++) {
        path.push_back(matrix[x1][i+1]);
        auto riter = path.rbegin() + 1;
        matrix[x1][i+1] = *riter;

    }
    //x2 col
    for (int i = x1; i < x2; i++) {
        path.push_back(matrix[i+1][y2]);
        auto riter = path.rbegin() + 1;
        matrix[i+1][y2] = *riter;
    }
    //y2 row
    for (int i = y2; i > y1; i--) {
        path.push_back(matrix[x2][i - 1]);
        auto riter = path.rbegin() + 1;
        matrix[x2][i - 1] = *riter;
    }
    //x1 col
    for (int i = x2; i > x1; i--) {
        path.push_back(matrix[i - 1][y1]);
        auto riter = path.rbegin() + 1;
        matrix[i - 1][y1] = *riter;
    }

    return *min_element(path.begin(),path.end());
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    for (int x = 0; x < rows; x++) {
        vector<int> dummy;
        for (int y = 0; y < columns; y++) {
            dummy.push_back(x * columns + y + 1);
        }
        matrix.push_back(dummy);
    }

    for (auto q : queries) {
        answer.push_back(rotation(q));
    }

    return answer;
}
