#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<int, int>> intersection;

    //���� ���ϱ�
    for (int i = 0; i < line.size(); i++) {
        for (int j = i + 1; j < line.size(); j++) {
            long long a = line[i][0], b = line[i][1], e = line[i][2];
            long long c= line[j][0], d = line[j][1], f = line[j][2];

            if (a * d - b * c == 0) continue; // �� ���� ���� ��
            int isNegativeX = 0, isNegativeY = 0; //�������� �˻�
            long long upx = b * f - e * d;
            if (upx < 0) {
                upx *= -1;
                isNegativeX++;
            }
            long long downx = a * d - b * c; 
            if (downx < 0) {
                downx *= -1;
                isNegativeX++;
            }
            if(upx != 0)
            if (downx == 0 || upx < downx || upx % downx != 0) continue; //���ں��� �и� �� ũ�ų� ������ �ƴϸ�
            
            long long upy = e * c - a * f;
            if (upy < 0) {
                upy *= -1;
                isNegativeY++;
            }
            long long downy = a * d - b * c;
            if (downy < 0) {
                downy *= -1;
                isNegativeY++;
            }
            if (upy != 0)
            if (downy == 0 || upy < downy || upy % downy != 0) continue; //���ں��� �и� �� ũ�ų� ������ �ƴϸ�
            int x = isNegativeX == 1 ? upx / downx * -1 : upx / downx;
            int y = isNegativeY == 1 ? upy / downy * -1 : upy / downy;
            intersection.push_back(make_pair(x, y));
        }
    }
    if (!intersection.empty()) {
        
        int minx = intersection[0].first, maxx = intersection[0].first;
        int miny = intersection[0].second, maxy = intersection[0].second;

        for (auto i : intersection) {
            minx = minx > i.first ? i.first : minx;
            maxx = maxx > i.first ? maxx : i.first;
            miny = miny > i.second ? i.second : miny;
            maxy = maxy > i.second ? maxy : i.second;
        }
        sort(intersection.begin(), intersection.end(),cmp);
        intersection.erase(unique(intersection.begin(), intersection.end()), intersection.end());

        // vector<string> answer(yLen, string(xLen, '.')); .�� ������
        // erase,unique,sort ��������ʰ� set<,> ����ؼ� for�� ������ * ��°͵� ������ ��
        int i = 0;
        for (int y = maxy; y >= miny; y--) {
            string s = "";
            for (int x = minx; x <= maxx; x++) {
                if (intersection[i].first == x && intersection[i].second == y) {
                    s += '*';
                    i++;
                }
                else
                    s += ".";
            }
            answer.push_back(s);
        }
    }
    return answer;
}
