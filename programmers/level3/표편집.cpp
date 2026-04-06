#include <string>
#include <vector>
#include <stack>

using namespace std;

int prevNode[1'000'001];
int nextNode[1'000'001];
bool alive[1'000'001];

stack<int> st;
int curPoint;

void init(int n, int k)
{
    for(int i = 0 ; i < n ; ++i)
    {
        prevNode[i] = i - 1; // prevNode[0] = - 1 //순환
        nextNode[i] = i + 1;
        alive[i] = true;
    }
    nextNode[n-1] = -1; //순환
    
    curPoint = k;
}

void run(const vector<string>& cmd)
{
    for(const auto& s : cmd)
    {
        if(s[0] == 'U')
        {
            int moveCnt = stoi(s.substr(2));
            while(moveCnt--) curPoint = prevNode[curPoint]; 
        }
        else if(s[0] == 'D')
        {
            int moveCnt = stoi(s.substr(2));
            while(moveCnt--) curPoint = nextNode[curPoint]; 
        }
        else if (s[0] == 'C') {
            st.emplace(curPoint);
            alive[curPoint] = false;

            int p = prevNode[curPoint];
            int n = nextNode[curPoint];

            if (p != -1) nextNode[p] = n;
            if (n != -1) prevNode[n] = p;

            // 다음 위치 이동
            curPoint = (n != -1) ? n : p;
        }
        else if (s[0] == 'Z') {
            int node = st.top();
            st.pop();

            alive[node] = true;

            int p = prevNode[node];
            int n = nextNode[node];

            if (p != -1) nextNode[p] = node;
            if (n != -1) prevNode[n] = node;
        }
    }
}

string draw(int n)
{
    string answer = "";
    for (int i = 0; i < n; i++) {
        answer += alive[i] ? 'O' : 'X';
    }
    return answer;
}

string solution(int n, int k, vector<string> cmd) {
    init(n,k);
    run(cmd);
    return draw(n);
}