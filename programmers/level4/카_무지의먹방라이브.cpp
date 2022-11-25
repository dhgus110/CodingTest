#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool cmp(pair<int, int>const& a, pair<int, int>const& b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long sum = 0;
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < food_times.size(); i++) {
        //C++11 이상의 emplace 계열 함수는 객체 생성자의 인자들을 넘겨,
        //컨테이너 내부에서 생성 후 추가하는 방식을 사용하기에, 
        //임시 객체를 아예 생기지 않게 하거나, 그 횟수를 줄일 수 있습니다.
        pq.emplace(-food_times[i], i+1); //소비시간이 작은 순으로 큐에 넣음(마이너스 사용)
        sum += food_times[i];
    }
    if (sum <= k) return -1;
    
    sum = 0; //소비되는 시간
    long long curFood , preFood = 0; //현재음식, 이전음식
    long long length = food_times.size(); //음식 개수

    while (sum + (-pq.top().first - preFood) * length <=k) { //k되기 직전에 멈춤
        curFood = -pq.top().first;
        pq.pop();
        //소비하는 시간이 작은 음식만큼 사이클을 한 바퀴 돈다.
        //curFood-preFood -> 이전 음식에서 소비하는 시간만큼을 이미 돌았으니 빼준다.
        sum = sum + (curFood-preFood)*length;
        length--;
        preFood = curFood;
    }
    vector<pair<int, int>> scraps; //남은 음식
    while (!pq.empty()) {
        scraps.push_back({ -pq.top().first, pq.top().second });
        pq.pop();
    }
    sort(scraps.begin(), scraps.end(), cmp);
    answer = scraps[(k - sum)%length].second; //남아있는시간만큼 이동

    return answer;
}