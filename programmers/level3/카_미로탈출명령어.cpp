#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int _n, _m, _r, _c, _k;

bool LimitArea(int cx, int cy) {
    if (cx > _n || cy > _m || cx < 1 || cy < 1)return false;
    return true;
}

bool CheckDistance(int cx, int cy) {
    int distance = abs(cx - _r) + abs(cy - _c);
    if (distance < _k)return true;
    return false;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    _n = n; _m = m; _k = k; _r = r; _c = c;

    int distance = abs(x - r) + abs(y - c);

    if ((distance > k) || ((distance % 2) != (k % 2))) return "impossible";

    while (CheckDistance(x, y)) {
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
    if (xr > 0)  for (int i = 0; i < xr; i++) answer += "u";

    return answer;
}