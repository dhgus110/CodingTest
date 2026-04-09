#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int prevNode[500'001];
int nextNode[500'001];
int curPoint;
int N;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1 ; i <= N ; ++i)
    {
        prevNode[i] = i - 1;
        nextNode[i] = i + 1;
    }
    prevNode[1] = N;
    nextNode[N] = 1;

    curPoint = 1;
}

void run1()
{

    for(int i = 0 ; i < N ; ++i)
    {
        //맨 위에 있는 카드 버리기
        prevNode[nextNode[curPoint]] = prevNode[curPoint];
        nextNode[prevNode[curPoint]] = nextNode[curPoint];
        
        //다음 맨 위에 있는 카드 선택 x2
        int nextTop = nextNode[curPoint];
        curPoint = nextNode[nextTop];

        //맨 아래로 이동
        //삭제 후
        prevNode[nextNode[nextTop]] = prevNode[nextTop];
        nextNode[prevNode[nextTop]] = nextNode[nextTop];
        //tail 뒤에 붙이기
        int tail = prevNode[curPoint];
        prevNode[curPoint] = nextTop;
        nextNode[tail] = nextTop;
        prevNode[nextTop] = tail;
        nextNode[nextTop] = curPoint;

    }

    cout << curPoint;
}

void run2()
{
    queue<int> q;

    for (int i = 1; i <= N; i++){
        q.push(i);
    }
    
    int cnt = N;
    while(cnt != 1){
        q.pop();
        int dummy = q.front();
        q.pop();
        q.push(dummy);
        cnt--;
    }

    cout << q.front();
}

int main()
{
    init();
    run1();
}