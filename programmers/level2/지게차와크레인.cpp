#include <string>
#include <vector>
#include <iostream>

using namespace std;

int sizeX, sizeY;
bool visited[50][50];

bool Check(int x, int y, vector<string>* storage , const char& request)
{
    if (x < 0 || y < 0 || x >= sizeX || y >= sizeY)
        return false;

    if (!visited[y][x])
    {
        if ((*storage)[y][x] == request)
        {
            (*storage)[y][x] = ' ';
            visited[y][x] = true;
        }
        return true;
    }
    return false;
}

void Forklift(vector<string>* storage, const char& request)
{
  
    for (int i = 0; i < sizeX; ++i)
    {   //위 
        for (int j = sizeY - 1; j >= 0; --j)
            if (Check(i, j, storage, request)) break;

        //아래
        for (int j = 0; j < sizeY; ++j)
            if (Check(i, j, storage, request)) break;
    }

    for (int i = 0; i < sizeY; ++i)
    {
        //왼
        for (int j = 0; j < sizeX; ++j)
            if (Check(j, i, storage, request)) break;

        //오
        for (int j = sizeX -1 ; j >= 0; --j)
            if (Check(j, i, storage, request)) break;

    }

}

void Crane(vector<string>* storage, const char& request)
{
    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            if ((*storage)[i][j] == request)
            {
                (*storage)[i][j] = ' ';
                visited[i][j] = true;
            }
        }
    }
}

void show(vector<string>* storage)
{
    for (int i = 0; i < sizeY; ++i)
        cout << (*storage)[i] << endl;

}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;

	sizeY = storage.size();
	sizeX = storage[0].size();

    fill(&visited[0][0], &visited[0][0] + 50 * 50, true);

    for (int i = 0; i < sizeY; ++i)
        for (int j = 0; j < sizeX; ++j)
            visited[i][j] = false;

	for (auto request : requests)
	{
		if (request.size() == 1)
            Forklift(&storage, request[0]);
        else
            Crane(&storage, request[0]);
        show(&storage);
    }

    for (int i = 0; i < sizeY; ++i)
        for (int j = 0; j < sizeX; ++j)
            if (!visited[i][j]) ++answer;

    return answer;
}
