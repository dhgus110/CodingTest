//백준 2751

#include <iostream>
#include <stack>

using namespace std;

int dataSize;
int myArray[1'000'000];
int temp[1'000'000];

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> dataSize;
    for (int i = 0; i < dataSize; i++)
        cin >> myArray[i];
}

//재귀
void Merge_Sort1(int _start, int _end)
{
    if(_end - _start < 1 ) return;

    int mid = _start + ( _end - _start) / 2;

    Merge_Sort1(_start, mid);
    Merge_Sort1(mid + 1, _end);

    for(int i = _start ; i <= _end ; ++i)
    {
        temp[i] = myArray[i];
    }

    int key = _start;
    int pointer_1 = _start;
    int pointer_2 = mid + 1;

    //투 포인터를 이용한 두 부분 집합의 정렬
    while(pointer_1 <= mid && pointer_2 <= _end)
    {
        if (temp[pointer_1] < temp[pointer_2])
            myArray[key++] = temp[pointer_1++];
        else
            myArray[key++] = temp[pointer_2++];
    }

    // 나머지 저장
    while (pointer_1 <= mid)
    {
        myArray[key++] = temp[pointer_1++];
    }

    while (pointer_2 <= _end)
    {
        myArray[key++] = temp[pointer_2++];
    }
}

struct Frame{
    int start, end;
    bool merged;
};

//스택으로 풀어 봤는데 재귀보다 더 오래걸림. stack은 내부적으로 vector or deque를 사용해서 push/pop연산해서 비용이 더 나가나봄.
void Merge_Sort2(int _start, int _end)
{
    stack<Frame> s;
    s.push({_start, _end, false});

    while(!s.empty())
    {
        Frame f = s.top();
        s.pop();

        int mid = f.start + (f.end - f.start)/2;

        if(!f.merged)
        {
            s.push({f.start, f.end, true}); 

            if( f.end - f.start < 1) continue;

            s.push({f.start, mid, false});
            s.push({mid + 1, f.end, false});
        }
        else
        {
            for(int i = f.start ; i <=  f.end ; ++i)
                temp[i] = myArray[i];
            
            int key =f.start;
            int pointer_1 = f.start;
            int pointer_2 = mid + 1;

            while(pointer_1 <= mid && pointer_2 <= f.end)
            {
                if(temp[pointer_1] < temp[pointer_2])
                    myArray[key++] = temp[pointer_1++];
                else
                    myArray[key++] = temp[pointer_2++];
            }

            while (pointer_1 <= mid)
                myArray[key++] = temp[pointer_1++];

            while (pointer_2 <= f.end)
                myArray[key++] = temp[pointer_2++];
        }
    }
}

void print_Array()
{
    for (int i = 0; i < dataSize; ++i)
        cout << myArray[i] << "\n";
}
int main()
{
    Init();
    Merge_Sort1(0, dataSize - 1 );
    //Merge_Sort2(0, dataSize - 1 );

    print_Array();
}