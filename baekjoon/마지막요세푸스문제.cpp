#include <iostream>

using namespace std;

// 0-index 기준 요세푸스
long long josephus(long long n, long long k)
{
    if (n == 1) return 0;
    if (k == 1) return n - 1;

    // k가 n보다 크면 1개만 제거되는 케이스 → 일반 점화식
    if (k > n)
        return (josephus(n - 1, k) + k) % n;

    // 한 바퀴에서 제거되는 수
    long long cnt = n / k;

    // 제거 후 남은 문제로 축소
    long long res = josephus(n - cnt, k);

    // 인덱스 보정
    res -= n % k;
    if (res < 0)
        res += n;
    else
        res += res / (k - 1);

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    // 1-index로 변환
    cout << josephus(n, k) + 1 << '\n';
}