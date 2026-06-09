
/*  Knuth의 5-guess 문제 

전체 후보군S 을 만들어서 소거시키기.

소거 방법
    guess = 고유 번호 "1234"같은걸로 시작(추측).
    반복.
        1. (s,b) = submit(guess) //스트라이크,볼 둘다 파싱
            if(s==4) return guess
        2. S 필터링 : 전체 후보군 S에서  1번 guess에 해당하는  (s,b)만 남기기.
        3. 남은 후보군 S에서 최악값중 가장 작은 최악을 구하기.
*/

#include <string>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

extern string submit(int);

vector<int> s;
vector<int> allS;

void init()
{
    s.reserve(3024);
    for (int a = 1; a <= 9; ++a)
    {
        for (int b = 1; b <= 9; ++b)
        {
            if( a == b) continue;
            for (int c = 1; c <= 9; ++c)
            {
                if (c == a || c == b) continue;
                for (int d = 1; d <= 9; ++d)
                {
                    if (d == a || d == b || d == c) continue;
                    s.emplace_back(a * 1000 + b * 100 + c * 10 + d);
                }
            }
        }
    }

    allS = s;
}

pair<int,int> feedback(int a, int b)
{
    int strike = 0, ball = 0;
    array<int, 4> array_a = {a/1000, (a/100)%10, (a/10)%10, a%10};
    array<int, 4> array_b = {b/1000, (b/100)%10, (b/10)%10, b%10};

    for (int j = 0; j < 4; j++)
    {
        if (array_a[j] == array_b[j]) ++strike;
        else if (count(array_a.begin(), array_a.end(), array_b[j])) ++ball;
    }

    return {strike, ball};
}

int choiceGuess()
{
    int bestWorst = INT_MAX , bestGuess = -1;
    bool bestInS = false;

    for(int i = 0 ; i < 3024 ; ++i)
    {
        /*
         정답 가능성이 있는 후보만 던진다. -> 약하다.
         이미 후보에서 탈락한 숫자라도, 남은 후보 s를 더 잘게 쪼개는 "정보용 추측"으로 사용하자.
         이것 때문에 n = 6 테스트케이스에서 걸림. 운 안좋게 n = 7까지 가서
        */
        //if(s[i] == 0) continue;
        
        map<pair<int,int>,int> groups;
        bool gInS = (s[i] != 0); //아직 후보군에 남아있으면 참.

        for (int j = 0 ; j < 3024 ; ++j)
        {
            if(s[j] == 0) continue;
            ++groups[feedback(allS[i], s[j])];
        }

        int worst = 0;
        for( auto [fb, cnt] : groups) worst = max(worst, cnt);

        //worst 작은게 우선, 같으면 정갑 가능성이 있는 후보군 우선 
        if(worst < bestWorst || (worst == bestWorst && gInS && !bestInS))
        {
            bestWorst = worst;
            bestGuess = allS[i];
            bestInS = gInS;
        }
    }

    return bestGuess;
}

int solution(int n) {
    init();

    int guess = 1234;

    while(true)
    {
        string strGuess = submit(guess);
        pair<int,int> score = {strGuess[0] - '0', strGuess[3] - '0'};
        if( score.first == 4) return guess;

        for(int i = 0 ; i < 3024 ; ++i)
        {
            if( s[i] == 0) continue;
            pair<int,int> fb = feedback(s[i], guess);
            if( fb != score) s[i] = 0;
        }

        guess = choiceGuess();
    }

    return 0;
}

