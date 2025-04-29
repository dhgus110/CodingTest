//백준 11399

#include <iostream>
#include <vector>
using namespace std;

int PeopleSize = 0;
vector<int> N(1000, 0);
vector<int> S(1000, 0);

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> PeopleSize;
    for (int i = 0; i < PeopleSize; ++i)
    {
        cin >> N[i];
    }
}

void insertSort_Solution()
{
    for (int i = 1; i < PeopleSize; ++i)
    {
        int curValue = N[i];
        int curIndex = i ;

        for (int j = i - 1; j >= 0; --j)
        {
            if( curValue < N[j])
            {
                N[curIndex] = N[j];
                N[j] = curValue;
                curIndex = j ;
            }
            else break;
        }
    }
}

int SumArray_Calculate()
{

    S[0] = N[0];
    int sum =  S[0];
    for(int i = 1 ; i < PeopleSize ; ++i)
    {
        S[i] = S[i-1] + N[i];
        sum += S[i];
    }
    return sum;
}

int main()
{
    init();
    insertSort_Solution();
    cout<< SumArray_Calculate();
    
}