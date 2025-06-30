//백준 1654

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> dataSet(10'000,0);
int dataSize =  { };
int requireCnt =  { };
long long dataSum = { 0 };

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>> dataSize >> requireCnt;

    for(int i = 0 ; i <dataSize ; ++i)
    {
        cin>>dataSet[i];
        dataSum += dataSet[i];
    }
    
}

int findLength()
{
   long long max = dataSum/ dataSize +1;
   long long min = 1 ;
   long long mid = (max + min) /2 ; 

   if( max == 0 ) return 0;

   while( min + 1 < max )
   {
        int cnt = 0 ; 

        for(int i = 0 ; i< dataSize ;++i)
            cnt += dataSet[i] / mid;

        if (cnt >= requireCnt) min = mid;
		else max = mid;

		mid = (max + min) / 2;
   }

   return mid;
}

int main()
{
    init();

    cout<< findLength();
}