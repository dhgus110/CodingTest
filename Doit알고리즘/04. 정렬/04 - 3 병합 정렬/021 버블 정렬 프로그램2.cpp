//백준 1517번번
//문제 이름은 버블 정렬이지만 , 범위가 500'000 이므로  
//최대 O(nlogn)으로 풀어야 제한 시간안에 풀 수 있으므로 병합정렬를 이용.

#include <iostream>

using namespace std;

int ArraySize = {};
int MyArray[500'001] = {};
int temp[500'001] = {};

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> ArraySize;

    for(int i = 0 ; i< ArraySize ; ++i)
        cin >> MyArray[i];
}

void Merge_Sort(const int _start, const int _end, int *_result)
{
    if (_end - _start < 1) return;

    int mid = _start + (_end - _start) / 2;

    Merge_Sort(_start, mid, _result);
    Merge_Sort(mid + 1, _end, _result);

    for(int i = _start ; i <= _end; ++i)
        temp[i] = MyArray[i];   

    int key = _start;
    int pointer_1 = _start;
    int pointer_2 = mid + 1;

    while(key <= _end)
    {
        if(temp[pointer_1] < temp[pointer_2])  {
           // MyArray[key++] = temp[pointer_1++];
            ++(*_result);
        } 
        else if( temp[pointer_1] > temp[pointer_2])  {
            //MyArray[key++] = temp[pointer_2++];
            ++(*_result);
        } 
    }


    // while(pointer_1 <= mid + 1)
    // {
    //     MyArray[key++] = temp[pointer_1++];
    // }
    
    // while (pointer_2 <= _end)
    // {
    //     MyArray[key++] = temp[pointer_2++];
    // }

}

int main()
{
    int result(0);

    init();

    Merge_Sort(0, ArraySize - 1 , &result);

    cout << result;
}