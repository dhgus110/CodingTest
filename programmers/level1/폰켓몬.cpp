#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s(nums.begin(),nums.end());
    if(nums.size()/2 < s.size())return nums.size()/2;
    else return s.size();


    // unordered_map<int, int> hash;

    // for (auto num: nums) {
    //     hash[num] += 1;
    // }

    // return min(hash.size(), nums.size() / 2);

}
/*
- 3) Unordered Associative Container (비정렬 연관 컨테이너)
Unordered Associative Container 이 컨테이너들은 해시화가 된 key 를 기반으로 자료에 접근하는 것이 특징이다.
이 경우도 Associative Container 와 유사하게 두 종류로 나뉜다

- Key 가 unique 한 경우
: unordered_set, unordered_map

- Key 가 하나이지만 중복된 value 가 허용되는 경우
: unordered_multiset, unordered_multimap

* 위에서 언급한 "Key 가 하나이지만 중복된 value 가 허용되는 경우" 란 컨테이너의 이름을 보면 추측이 가능하지만,
 동일한 키에 여러개의 값이 들어 갈 수 있다는 의미이다. 예를들면 DB 에서 주민등록번호는 Unique Key, Primary Key 로 칠 수 있지만,
  이름은 그렇지 않다. 이름이 바로 value 가 중복되어 허용되는 경우라 볼 수 있다.
https://sdy-study.tistory.com/59?category=962735
*/