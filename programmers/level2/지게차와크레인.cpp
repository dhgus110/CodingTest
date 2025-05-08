#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define EMPTY   ' '

using namespace std;

int sizeX, sizeY;
bool isTakeOut[50][50];
bool isOutWall[50][50];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void show(vector<string>* storage)
{
    for (int i = 0; i < sizeY; ++i)
        cout << (*storage)[i] << endl;
    cout << endl;
}

void showOutWall()
{
    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            if (isOutWall[i][j])
                cout << "w";
            else
                cout << "-";
        }
        cout << endl;
    }
    cout << endl;

}

bool FindOutWall_BFS(vector<string>* storage, int y, int x)
{
    queue<pair<int, int>> sour;
    bool visited[50][50] = {};

    sour.push({ y,x });
    visited[y][x] = true;

    while (!sour.empty())
    {
        auto pair = sour.front();
        sour.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nextY = pair.first + dy[i];
            int nextX = pair.second + dx[i];

            if (nextY < 0 || nextY >= sizeY || nextX < 0 || nextX >= sizeX || (isTakeOut[nextY][nextX] && isOutWall[nextY][nextX]))
                return true;

            if (!visited[nextY][nextX] && isTakeOut[nextY][nextX])
            {
                sour.push({ nextY , nextX });
                visited[nextY][nextX] = true;
            }
        }
    }
    return false;
}

void Forklift(vector<string>* storage, const char& request)
{    
	for (int i = 0; i < sizeY; ++i) {
		for (int j = 0; j < sizeX; ++j) {
			if ((*storage)[i][j] == request && isOutWall[i][j])
			{
                isTakeOut[i][j] = true;
                //(*storage)[i][j] = EMPTY;
			}
		}
	}

    //외벽이 아닌 녀석들만 다시 외벽검사
    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            if (!isOutWall[i][j] && FindOutWall_BFS(storage, i, j))
            {
                isOutWall[i][j] = true;
            }
        }
    }
}

void Crane(vector<string>* storage, const char& request)
{
    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            if ((*storage)[i][j] == request)
            {
                isTakeOut[i][j] = true;
                //(*storage)[i][j] = EMPTY;
            }
        }
    }

    //외벽이 아닌 녀석들만 다시 외벽검사
    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            if (!isOutWall[i][j] && FindOutWall_BFS(storage,i,j))
            {
                isOutWall[i][j] = true;
            }
        }
    }

}



int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;

	sizeY = storage.size();
	sizeX = storage[0].size();

    fill(&isTakeOut[0][0], &isTakeOut[0][0] + 50 * 50, true);

	for (int i = 0; i < sizeY; ++i)
	{
        isOutWall[i][0] = true;
        isOutWall[i][sizeX - 1] = true;
		for (int j = 0; j < sizeX; ++j)
		{
            isTakeOut[i][j] = false;
            isOutWall[0][j] = true;
            isOutWall[sizeY - 1][j] = true;
		}
	}


	for (auto request : requests)
	{
		if (request.size() == 1)
            Forklift(&storage, request[0]);
        else
            Crane(&storage, request[0]);
    }

    for (int i = 0; i < sizeY; ++i)
        for (int j = 0; j < sizeX; ++j)
            if (!isTakeOut[i][j]) ++answer;

    return answer;
}
