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
    char dummyL= s[0];
    char dummyR = s.back();
    switch (type)
    {
    case 0: //D
        index *= 2;
        if (index > 9'999)
            index %= 10'000;
        break;
    case 1: //S
        index -= 1;
        if (index == 0)
            index = 9'999;
        break;
    case 2: //L
        if (index < 10)
            break;
        
        for (int i = 0; i < s.length() - 1; i++)
        {
            s[i] = s[i + 1];
        }
        s[s.length() - 1] = dummyL;
        index = stoi(s);
        break;
    case 3: //R
        if (index < 10)
            break;
        for (int i = s.length() -1 ; i < 0; i--)
        {
            s[i] = s[i+1];
        }
        s[0] = dummyR;
        index = stoi(s);
        break;
    }
    return index;
}

void bfs()
{
    string answer = "";
    queue<pair<int, string>> q;
    q.push({original, ""});
    visited[original] = true;
    while (!q.empty())
    {
        if(q.front().first==target) break;
        int curI = q.front().first;
        string curS = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ni = DSLR(curI, i);
            string ns = curS + d[i];
            if (!visited[ni])
            {
                q.push({ni, ns});
                visited[ni]=true;
                table[ni] = ns;
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>original>>target;
        fill_n(visited,10'001,false);
        fill_n(table,10'001,"");
        bfs();
        cout<<table[target]<<endl;
    }
}