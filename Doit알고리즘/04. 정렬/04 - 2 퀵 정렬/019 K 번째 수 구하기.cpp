//백준 11004번

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dataSize = 0;
int k = 0;
int myArray[5'000'000];

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> dataSize >> k;

    for (int i = 0; i < dataSize; ++i)
        cin >> myArray[i];
}

void QuickSort(int _start , int _end)
{
    if( _start >= _end) return;

    int i = _start;
    int j = _end - 1;
    int pivot = _end;



    while(i <= j)
    {
        while ( i + 1 <= j && myArray[i] < myArray[pivot] ) ++i;
        while ( i <= j - 1 && myArray[j] > myArray[pivot] ) --j;

       if(i >= j)
       {
        swap(myArray[i],myArray[pivot]);
        break;
       }
       else
       {
        swap(myArray[i],myArray[j]);
       }

    }

    QuickSort(_start, i - 1 );
    QuickSort(  i + 1, _end);
}

void QuickSelect()
{
    
}

int Easy_Solution()
{
    //배열에서 k 번째 수 찾기    O(n)
    nth_element(myArray, myArray + k - 1, myArray + dataSize);
    return myArray[k-1];
}

int main()
{
    init();

    QuickSort(0, dataSize - 1);

    cout<<myArray[k-1];

    //cout<<Easy_Solution();
}