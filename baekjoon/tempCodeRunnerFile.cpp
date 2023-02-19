#include <iostream>
#include <string>
#include <queue>

using namespace std;
// D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
// S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
// L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
// R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.

int original,target;
bool visited[10'001];
string table[10'001];
string d[4]={"D","S","L","R"};

int DSLR(int index, int type)
{
    string s = to_string(index);
    while (s.length() != 4)
    {
        s = "0" + s;
    }
    char s0 = s[0];
    char s1 =s[1];
    char s2 =s[2];
    char s3 = s[3];

    switch (type)
    {
    case 0: //D
        index = (2 * index) % 10'000;
        break;
    case 1: //S
        index = index == 0 ? 9'999 : index - 1;
        break;
    case 2: //L
        s[0] = s1;
        s[1] = s2;
        s[2] = s3;
        s[3] = s0;
        index = stoi(s);
        break;
    case 3: //R
        s[0] = s3;
        s[1] = s0;
        s[2] = s1;
        s[3] = s2;
        index = stoi(s);
        break;
    }
    return index;
}

void bfs()
{
    queue<pair<int, string>> q;
    q.push({original, ""});
    visited[original] = true;

    while (!q.empty())
    {
        int curIndex = q.front().first;
        string curStr = q.front().second;
        q.pop();

        if (curIndex == target) break;

        for (int i = 0; i < 4; i++)
        {
            int nextIndex = DSLR(curIndex, i);
            string nextStr = curStr + d[i];
            if (!visited[nextIndex])
            {
                q.push({nextIndex, nextStr});
                visited[nextIndex] = true;
                table[nextIndex] = nextStr;
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> original >> target;
        fill_n(visited, 10'001, false);
        fill_n(table, 10'001, "");
        bfs();
        cout << table[target] << '\n';
    }
}