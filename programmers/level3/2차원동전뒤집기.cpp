#include <string>
#include <vector>
#define INF 1e9
using namespace std;

void reverseColumn(vector<vector<int>>& v, int col) {
    for (int i = 0; i < v[col].size(); i++) {
        v[col][i] = (v[col][i] == 0) ? 1 : 0;
    }
}

void reverseRow(vector<vector<int>>& v, int row) {
    for (int i = 0; i < v.size(); i++) {
        v[i][row] = (v[i][row] == 0) ? 1 : 0;
    }
}

//각 행의 첫 번째 원소가 서로 다르면 행을 먼저 뒤집는다. 이후 각 열의 첫 번째 원소가 다르면 열을 뒤집는다.
pair<bool,int> test1(vector<vector<int>> beginning, vector<vector<int>>const& target) {
    int cnt = 0;
    for (int i = 0; i < beginning.size(); i++) {
        if (beginning[i][0] != target[i][0]){
            reverseColumn(beginning, i);
            cnt++;
        }
    }
    for (int i = 0; i < beginning[0].size(); i++) {
        if (beginning[0][i] != target[0][i]) {
            reverseRow(beginning, i);
            cnt++;
        }
    }
    if (beginning == target)return { true,cnt };
    else return { false,-1 };
    
}

//각 행의 첫 번째 원소가 서로 같으면 행을 먼저 뒤집는다. 이후 각 열의 첫 번째 원소가 다르면 열을 뒤집는다.
pair<bool, int> test2(vector<vector<int>> beginning, vector<vector<int>>const& target) {
    int cnt = 0;
    for (int i = 0; i < beginning.size(); i++) {
        if (beginning[i][0] == target[i][0]) {
            reverseColumn(beginning, i);
            cnt++;
        }
    }
    for (int i = 0; i < beginning[0].size(); i++) {
        if (beginning[0][i] != target[0][i]) {
            reverseRow(beginning, i);
            cnt++;
        }
    }
    if (beginning == target)return { true,cnt };
    else return { false,-1 };
}

//각 열의 첫 번째 원소가 서로 다르면 열을 먼저 뒤집는다. 이후 각 행의 첫 번째 원소가 다르면 행을 뒤집는다.
pair<bool, int> test3(vector<vector<int>> beginning, vector<vector<int>>const& target) {
    int cnt = 0;
    for (int i = 0; i < beginning[0].size(); i++) {
        if (beginning[0][i] != target[0][i]) {
            reverseRow(beginning, i);
            cnt++;
        }
    }
    for (int i = 0; i < beginning.size(); i++) {
        if (beginning[i][0] != target[i][0]) {
            reverseColumn(beginning, i);
            cnt++;
        }
    }
    if (beginning == target)return { true,cnt };
    else return { false,-1 };
}

//각 열의 첫 번째 원소가 서로 같으면 열을 먼저 뒤집는다. 이후 각 행의 첫 번째 원소가 다르면 행을 뒤집는다.
pair<bool, int> test4(vector<vector<int>> beginning, vector<vector<int>>const& target) {
    int cnt = 0;
    for (int i = 0; i < beginning[0].size(); i++) {
        if (beginning[0][i] == target[0][i]) {
            reverseRow(beginning, i);
            cnt++;
        }
    }
    for (int i = 0; i < beginning.size(); i++) {
        if (beginning[i][0] != target[i][0]) {
            reverseColumn(beginning, i);
            cnt++;
        }
    }
    if (beginning == target)return { true,cnt };
    else return { false,-1 };
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = INF;
    pair<bool, int> res;
    res = test1(beginning, target);
    if (res.first)answer = answer > res.second ? res.second : answer;
    res = test2(beginning, target);
    if (res.first)answer = answer > res.second ? res.second : answer;
    res = test3(beginning, target);
    if (res.first)answer = answer > res.second ? res.second : answer;
    res = test4(beginning, target);
    if (res.first)answer = answer > res.second ? res.second : answer;

    if (answer == INF) return -1;
    return answer;
}