//백준 2023번 

#include <iostream>
#include <vector>

using namespace std;

int sizeNum={};

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> sizeNum;
}

bool IsPrimeNumber(const int& num)
{
        if (num == 0 || num == 1)
        return false;
    for (int i = 2; i <= num / 2; ++i)
        if (num % i == 0)
            return false;
    return true;
}

void DFS(int curNum, int curSize, vector<int>* result)
{
    if (curSize > sizeNum || !IsPrimeNumber(curNum))
        return;

    if(curSize == sizeNum)
    {
        result->push_back(curNum);
        return;
    }

    for(int i = 1 ; i<= 9 ; ++i)
    {
        DFS(curNum * 10 + i, curSize + 1, result);
    }
    
}

int main()
{
    vector<int> result;
    init();

    for(int i = 1 ; i<= 9 ; ++i)
        DFS(i, 1, &result);

    for(auto& num : result)
        cout << num << '\n';
}