#include <string>
#include <vector>
#define INF 1e9
using namespace std;
//S: ���� ����
//E : �ⱸ
//L : ����
//O : ���
//X : ��
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int table[10001][10001];


int solution(vector<string> maps) {
    int answer = 0;
    int h = maps.size();
    int w = maps[0].size();
    int no = h * w; //����� ����
    //Init
    for (int i = 0; i < 10001; i++) {
        fill(table[i], table[i] + 10001, INF);
    }

    //�ڱ� �ڽ����� ���� ��� 0
    for (int i = 0; i < no; i++) {
        table[i][i] = 0;
    }

    //���� ���� ���
    for (int i = 0; i < maps.size(); i++) {

    }


    return answer;
}