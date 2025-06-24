#include <iostream>
#include <algorithm>
#include <vector>

#define    INTERVAL     10'000'000
using namespace std;

int cardSet[20'000'001];
int cardSize ={0};
int findNum = { 0 };


void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(cardSet, cardSet+ 20'000'001 ,0);

    cin>> cardSize;

    int temp = { 0 };
    for(int i = 0 ; i <cardSize ; ++i)
    {
        cin>>temp;
        ++cardSet[temp + INTERVAL];
    }

    cin>> findNum ;

}

int main()
{
    init();
    
    int temp = { 0 };
    for(int i = 0 ; i <findNum ; ++i)
    {
        cin>> temp;
        cout<<cardSet[temp+ INTERVAL];
    }
    
}