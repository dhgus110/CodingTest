//백준 2343번

#include <iostream>
#include <vector>

using namespace std;

int numLesson = {};
int numBlueray = {};
int sumLessonTime = { 0 };
int maxLessonTime = { 0 };
vector<int> lesson(100'000,0);

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> numLesson >> numBlueray;

    for(int i = 0 ; i <numLesson ; ++i)
    {
        cin >> lesson[i];
        sumLessonTime +=lesson[i];
        maxLessonTime = maxLessonTime > lesson[i] ? maxLessonTime : lesson[i];
    }
    
} 

int findMinLessonTime()
{
    int max = sumLessonTime;
    int min = maxLessonTime;
    int mid ={}; //최소 시간을 구해야해 

    while(min + 1 < max)
    {  
        mid = (max + min) /2;

        int eachBluerayTime = {0};
        int cnt = { 0 };

        for(int i = 0 ; i < numLesson ; ++i)
        {
            if(eachBluerayTime + lesson[i] > mid)
            {
                cnt++;
                eachBluerayTime = 0;
            }

            eachBluerayTime += lesson[i];
        }

        if(eachBluerayTime > 0 ) cnt++;

        if( cnt > numBlueray  ) min = mid + 1;
        else max = mid - 1;
    }

    return min;
}

int main()
{
    init();
    cout << findMinLessonTime();
}