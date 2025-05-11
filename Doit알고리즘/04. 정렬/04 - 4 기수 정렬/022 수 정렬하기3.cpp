#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int sizeData = {};
int dataMaxSize = {};
vector<int> vecData; // 기수 정렬렬

vector<int> vecCount(10'001,0); //계수 정렬

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> sizeData;

    int tempNum = 0;
    vector<int> vecTemp(sizeData, 0);
    vecData = vecTemp;

    for (int i = 0; i < sizeData; ++i)
    {
        cin >> tempNum;

        vecData[i] = tempNum;
        
        //data >= 1 이므로 log10(0) 처리 안해도 됨
        dataMaxSize = max(dataMaxSize, static_cast<int>(log10(vecData[i])) + 1);

        vecCount[tempNum]++;
    }
}

inline int GetDigitAt(int num, int pos)
{
    for (int i = 1; i < pos; ++i)
        num /= 10;
    return num % 10;
}

void Radix_Sort()
{
    for (int i = 0; i < dataMaxSize; ++i)
    {
        queue<int> radix[10];

        for (int j = 0; j < 10; ++j)
        {
            for (auto &data : vecData)
            {
                if (GetDigitAt(data, i + 1) == j)
                    radix[j].push(data);
            }
        }

        int index = 0 ;
        for (int j = 0; j < 10; ++j)
        {
            while(!radix[j].empty())
            {
                vecData[index++] = radix[j].front();
                radix[j].pop();
            }
        }
    }
}

int main()
{
    init();

    //기수 정렬 
    Radix_Sort();

    // 계수 정렬
    for (int i = 1; i <= 10'000; ++i)
    {
        if(vecCount[i] > 0)
            for (int j = 0; j < vecCount[i]; ++j)
                cout << i <<'\n';
    }
}