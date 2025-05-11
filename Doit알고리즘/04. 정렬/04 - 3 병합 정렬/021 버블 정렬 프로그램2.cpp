//백준 1517번번
//문제 이름은 버블 정렬이지만 , 범위가 500'000 이므로  
//최대 O(nlogn)으로 풀어야 제한 시간안에 풀 수 있으므로 병합정렬를 이용.

#include <iostream>

using namespace std;

int ArraySize = {};
int MyArray[500'001] = {} ;
int temp[500'001] = {};

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> ArraySize;

    for(int i = 1 ; i <= ArraySize ; ++i)
        cin >> MyArray[i];

}

void Merge_Sort(const int _start, const int _end, long long *_result)
{
    if (_end - _start <= 0) return;

    int mid = _start + (_end - _start) / 2;

    Merge_Sort(_start, mid, _result);
    Merge_Sort(mid + 1, _end, _result);

    for (int i = _start; i <= _end; ++i)
        temp[i] = MyArray[i];

    int key = _start;
    int pointer_1 = _start;
    int pointer_2 = mid + 1;

    while (pointer_1 <= mid && pointer_2 <= _end)
    {
        if( temp[pointer_1] > temp[pointer_2])  {
            //버블 정렬할 때 버블 횟수를 물어보는 문제
            //pointer_2의 데이터들은 pointer_1의 데이터들보다 뒤에 있고
            //버블소트에서의 스왑 횟수를 계산해야하므로 뒤쪽 데이터 값이 더 작으면 앞으로 몇 칸 이동했는지 계산해서서 같은 효과를 볼 수 있음.
            (*_result) += (pointer_2 - key);
            MyArray[key++] = temp[pointer_2++];
        }
        else
        {
            MyArray[key++] = temp[pointer_1++];
        }
    }

    while(pointer_1 <= mid )
    {
        MyArray[key++] = temp[pointer_1++];
    }
    
    while (pointer_2 <= _end)
    {
        MyArray[key++] = temp[pointer_2++];
    }
    


}

int main()
{
    long long result(0);

    init();

    Merge_Sort(1, ArraySize , &result);

    cout << result;
}