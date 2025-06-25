//백준 1253번

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
int numSize ={0};


void init()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> numSize;
    int temp = {};
    for (int i = 0; i < numSize; ++i)
    {
        cin >> temp;
        numbers.push_back(temp);
    }

    sort(numbers.begin(), numbers.end());
}

// bool binarySearch(const int& target ,int start, int end){
//     if(start > end) return false;

//     int mid = (start + end) / 2;

//     if (numbers[mid] > target)
//         return binarySearch(target, start, mid - 1);

//     else if (numbers[mid] < target)
//         return binarySearch(target, mid + 1, end);

//     else if (numbers[mid] == target) return true;
    
// }

// bool binaryAdd(const int& target ,int start, int end){
//     if(start >= end) return false;

//     int mid = (start + end) / 2;
//     int value =numbers[start] + numbers[end];

//     if (value > target)
//         return binaryAdd(target, start, mid );

//     else if (value < target)
//         return binaryAdd(target, mid, end);

//     else if (value == target) return true;
    
// }

int twoPointerMove()
{
    int cnt = {0};

    for (int i = 0; i < numSize; ++i)
    {
        int left = {0}, right = {numSize - 1};

        while (left < right)
        {
            if(left ==i) left++;
            if(right ==i) right--;
            if(left >= right) break;
            if (numbers[i] == numbers[left] + numbers[right])
            {
                cnt++;
                break;
            }
            else if (numbers[i] > numbers[left] + numbers[right])
                left++;
            else 
                right--;

        }
    }

    return cnt;
}

int main()
{
    init();
    cout<< twoPointerMove();
}