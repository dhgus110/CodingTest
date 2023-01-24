#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int _n, _m, _r, _c, _k;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,-1,1,0 };
char d[4] = { 'd','l','r','u' };
string answer = "";
bool check = false;

bool LimitArea(int cx, int cy) {
    if (cx > _n || cy > _m || cx < 1 || cy < 1)return false;
    return true;
}

bool CheckDistance(int cx, int cy, int ck) {
    int distance = abs(cx - _r) + abs(cy - _c);
    if (distance > ck)return true;
    return false;
}

void dfs(int curx, int cury, int curk, string path) {
    if (curk == 0 && curx == _r && cury == _c) {
        check = true;
        answer = path;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int gox = curx + dx[i];
        int goy = cury + dy[i];
        if (!LimitArea(gox, goy)) continue;
        if (CheckDistance(gox, goy, curk - 1)) continue;
        dfs(gox, goy, curk - 1, path + d[i]);
        if (check)return;
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {

    _n = n; _m = m; _k = k; _r = r; _c = c;

    int distance = abs(x - r) + abs(y - c);

    if ((distance > k) || ((distance % 2) != (k % 2))) return "impossible";
    dfs(x, y, k, "");

    /*while (CheckDistance(x, y)) {
        if (LimitArea(x + 1, y)) {
            x += 1;
            answer += "d";
        }
        else if (LimitArea(x, y - 1)) {
            y -= 1;
            answer += "l";
        }
        else if (LimitArea(x, y + 1)) {
            y += 1;
            answer += "r";
        }
        else if (LimitArea(x - 1, y)) {
            x -= 1;
            answer += "u";
        }
        _k -= 1;

        if (x == r && y == c) {
            if (LimitArea(x + 1, y))
                for (int i = 0; i < _k / 2; i++)
                    answer += "du";
            else if (LimitArea(x, y - 1))
                for (int i = 0; i < _k / 2; i++)
                    answer += "lr";
            else if (LimitArea(x, y + 1))
                for (int i = 0; i < _k / 2; i++)
                    answer += "rl";

            return answer;
        }
    }

    int xr = x - r;
    int yc = y - c;
    if (xr < 0)  for (int i = 0; i < abs(xr); i++) answer += "d";
    if (yc > 0)  for (int i = 0; i < yc; i++) answer += "l";
    if (yc < 0)  for (int i = 0; i < abs(yc); i++) answer += "r";
    if (xr > 0)  for (int i = 0; i < xr; i++) answer += "u";*/

    return answer;
}
