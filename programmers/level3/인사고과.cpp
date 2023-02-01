#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//�ٹ� �µ� ����(v[0])�� �������� ���� �� ����(v[1])�� ������������
bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}
int solution(vector<vector<int>> scores) {
    int answer = 1;
    auto pivot = scores[0];
    int pivotValue = scores[0][0] + scores[0][1];
    sort(scores.begin(), scores.end(), cmp);
    int max = 0;

    // �� �տ� ������������ ������ ��������� �Ѹ��̶� ������ Ż�� (max�� �Ǻ�)
    // �ٹ��µ� �������� ��� ������ �������� �Ͽ����Ƿ� ������� �ʾƵ� ��
    for (auto s : scores) {
        if (s[0] > pivot[0] && s[1] > pivot[1])
            return -1;
        if (s[0] + s[1] > pivotValue && max <= s[1]) {
            answer++;
            max = s[1];
        }
    }
    return answer;
}