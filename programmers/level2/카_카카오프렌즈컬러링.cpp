#include <vector>
#include <cstring>

using namespace std;

int clonePic[100][100];
bool visit[100][100];

int dx[4];
int dy[4];
int maxX, maxY;

int cnt;

void init(int m, int n) {
    memset(visit, false, sizeof(visit));
    memset(clonePic, 0, sizeof(clonePic));

    dx[0] = -1; dy[0] = 0; //왼
    dx[1] = 1; dy[1] = 0; //오
    dx[2] = 0; dy[2] = -1; //아래
    dx[3] = 0; dy[3] = 1; //위

    maxX = m; maxY = n;
    cnt = 0;

}

bool limitArea(int x, int y) {
    if (x<0 || x>maxX || y<0 || y>maxY)
        return false;
    else return true;
}

void search(int m, int n) {
    int check = clonePic[m][n];
    visit[m][n] = false;
    cnt++;

    for (int i = 0; i < 4; i++) {
        if (limitArea(m + dx[i], n + dy[i]) && visit[m + dx[i]][n + dy[i]] && clonePic[m + dx[i]][n + dy[i]] == check) {
            search(m + dx[i], n + dy[i]);
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    init(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            clonePic[i][j] = picture[i][j];
            if (picture[i][j]) visit[i][j] = true; //그려져 있으면 
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j]) {
                cnt = 0;
                search(i, j);
                max_size_of_one_area = cnt > max_size_of_one_area ? cnt : max_size_of_one_area;
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}