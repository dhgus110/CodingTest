#include <string>
#include <vector>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

vector<int> solution(string command) {
    vector<int> answer;
    int x = 0;
    int y = 0;
    int curDir = 0;

    for (auto c : command) {
        switch (c)
        {
        case 'R':
            curDir++;
            if (curDir == 4) curDir = 0; 
            break;
        case 'L':
            curDir--;
            if (curDir == -1) curDir = 3;
            break;
        case 'G':
            x += dx[curDir];
            y += dy[curDir];
            break;
        case 'B':
            x -= dx[curDir];
            y -= dy[curDir];
            break;
        }
    }
    answer.push_back(x);
    answer.push_back(y);

    return answer;
}
