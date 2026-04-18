
/*
배열 기반 이중 연결 리스트 구현
중간 삭제를 하면 prev와 next를 연결해서 바로 다음 index를 찾을 수 있게 만듦
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, K ;
int prevNode[5001];
int nextNode[5001];
int curPoint;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K ;

    for(int i = 1 ; i <= N ; ++i)
    {
        prevNode[i] = i - 1;
        nextNode[i] = i + 1;
    }
    prevNode[1] = N;
    nextNode[N] = 1;

    curPoint = K;
}

void run()
{
    vector<int> res;
    
    for(int i = 1 ; i <= N ; ++i)
    {
        res.emplace_back(curPoint);

        prevNode[nextNode[curPoint]] = prevNode[curPoint]; 
        nextNode[prevNode[curPoint]] = nextNode[curPoint];

        // int moveCnt = (N - i >= K) ? K : 1;
        int moveCnt = K;
        while(moveCnt--)
            curPoint = nextNode[curPoint];
    }

    cout<<"<";
    for(int i = 0 ; i < res.size() ; ++i)
    {
        cout<<res[i];
        if(i != res.size() - 1)
            cout<<", ";
    }
    cout<<">";
}

int main()
{
    init();
    run();
}
