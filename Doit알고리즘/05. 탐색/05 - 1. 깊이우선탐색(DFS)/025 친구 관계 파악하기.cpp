// 백준 13023번
//DFS, 백트래킹

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> graph[2001];
bool visited[2'001] = {};
int nodeSize = {}, edgeSize = {};
bool flag{false};

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> nodeSize >> edgeSize;

    for(int i = 0 ; i <edgeSize ;++i)
    {
        int tempA = {}, tempB = {};
        cin >> tempA >> tempB;
        graph[tempA].push_back(tempB);
        graph[tempB].push_back(tempA);
    }
}

void Run(int _curIndex, int _depth)
{
    if (_depth >= 5 || flag)
    {
        flag = true;
        return;
    }

    visited[_curIndex] = true;

    for (auto &next : graph[_curIndex])
    {
        if (!visited[next])
        {
            Run(next, _depth + 1);
        }
    }
    visited[_curIndex] = false;
}

int main()
{
    init();  
    // cout<< DFS();

    for (int i = 0; i < nodeSize; ++i)
    {
        if (!graph[i].empty())
        {
            Run(i, 1);
            if (flag)
            {
                break;
            }
        }
    }
    if (flag)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}
