/*
**QuickSelect**는 퀵정렬의 아이디어를 활용해 전체를 정렬하지 않고도 k번째로 작은 원소만 빠르게 찾을 수 있는 알고리즘.

     정렬은 O(NlogN), QuickSelect는 평균 O(N)


✅ QuickSelect 개념
    퀵정렬처럼 피벗을 고르고, 좌우로 분할합니다.
    다만, 정렬처럼 양쪽을 모두 재귀호출하지 않고, k번째 원소가 포함된 쪽만 재귀 호출합니다.
    이 과정을 반복하면 원하는 위치의 원소를 빠르게 찾을 수 있습니다.


✅ 함수 기능 제공해줌 -	O(N)
    nth_element()


*/

#include <algorithm>

int QuickSelect(int arr[], int left, int right, int k) {
    if (left == right)
        return arr[left];

    int pivotIndex = right;
    int pivotValue = arr[pivotIndex];

    // Partition
    int i = left;
    for (int j = left; j < right; ++j) {
        if (arr[j] < pivotValue)
            std::swap(arr[i++], arr[j]);
    }
    std::swap(arr[i], arr[right]); // move pivot to its correct place

    int order = i - left + 1; // 몇 번째 작은 수인가?

    if (order == k)
        return arr[i];
    else if (k < order)
        return QuickSelect(arr, left, i - 1, k);
    else
        return QuickSelect(arr, i + 1, right, k - order);
}