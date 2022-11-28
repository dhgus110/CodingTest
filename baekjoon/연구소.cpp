#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8][8];
int temp[8][8];  //3개의 벽을 세운 임시맵
int check[8][8]; //바이러스가 퍼진 곳이면 1 ,그 외 지역 0

//바이러스 진행 방향
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int result;

//바이러스 확산
void spreading(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m)
        {
            if (temp[nx][ny] == 0)
            {
                check[nx][ny] = 1;
                temp[nx][ny] = 2;
                spreading(nx, ny);
            }
        }
    }
}

//안전지대 확인
int safetyZone()
{
    int safety = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
                safety+=1;
        }
    }
    return safety;
}

void dfs(int wallCount)
{
    //벽을 3개 세웠을 경우
    if (wallCount == 3)
    {
        //임시맵 초기화
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                temp[i][j] = arr[i][j];
                check[i][j] = 0;
            }
        }

        //확산시킴
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (check[i][j] == 0 && temp[i][j] == 2)
                {
                    check[i][j] = 1;
                    spreading(i, j);
                }
            }
        }

        //안전지대 확인
        result = max(result, safetyZone());
        return; //함수가 끝나는 지점
    }

    //벽 세우고 뿌시는 과정
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = 1;
                wallCount += 1;
                dfs(wallCount);
                arr[i][j] = 0;
                wallCount -= 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    dfs(0);
    cout << result<<'\n';
}
