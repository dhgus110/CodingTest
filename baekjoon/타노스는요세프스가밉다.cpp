//백준 28066번

#include <iostream>

using namespace std;

int prevNode[1'000'001];
int nextNode[1'000'001];
int curPoint;
int N , K;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 1 ; i <= N ; ++i)
    {
        prevNode[i] = i - 1;
        nextNode[i] = i + 1;
    }
    prevNode[1] = N;
    nextNode[N] = 1;
    curPoint = 1;
}

void run()
{
    int remainCnt = N;
    bool firstFlag = true;

    while(remainCnt - 1 >= K)
    {
        curPoint = nextNode[curPoint];

        //선택된 녀석 빼고 삭제 = K - 1
        for(int i = 0 ; i < K - 1 ; ++i)
        {
            //cout<< "삭제 :"<< curPoint<<endl;
            prevNode[nextNode[curPoint]] = prevNode[curPoint]; 
            nextNode[prevNode[curPoint]] = nextNode[curPoint]; 
            
            curPoint = nextNode[curPoint];
            --remainCnt;
        }
        //cout<<"--------------"<<endl;
    }

    cout << curPoint;
}

int main()
{
    init();
    run();
}
