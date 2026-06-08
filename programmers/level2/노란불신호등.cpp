#include <string>
#include <vector>
#include <numeric>

using namespace std;


int solution(vector<vector<int>> signals) {
    int signalSize = signals.size();
    int yellow[5][2];
    int interval[5];

    for(int i = 0 ; i < signalSize ; ++i)
    {
        yellow[i][0] = signals[i][0] + 1;
        yellow[i][1] = signals[i][0]  + signals[i][1];
        interval[i] = signals[i][0] + signals[i][1] + signals[i][2];
    }
    
    vector<int> times(10'000'000,0);
    
    int check = 0;
    bool isFinish[5] ={false,false,false,false,false};
    
    while(check != signalSize)
    {
        for(int i = 0 ; i < signalSize ; ++i)
        {
            if( yellow[i][0] >= 10'000'000)
            {
                if(!isFinish[i])
                {
                    isFinish[i] = true;
                    ++check;
                }
                continue;
            } 
            for(int j = yellow[i][0] ; j <= yellow[i][1] ; ++j)
            {
                if(++times[j] == signalSize) return j;
            }
            yellow[i][0] += interval[i];
            yellow[i][1] += interval[i];
        }   
    }

    
    return -1;
}


int solution2(vector<vector<int>> signals) {
    int signalSize = signals.size();
    int L = 1;
    int allTime[5];
    int yellow[5][2];
    for(int i = 0 ; i < signalSize ; ++i)
    {
        yellow[i][0] = signals[i][0];
        yellow[i][1] = signals[i][0] + signals[i][1];
        allTime[i] = signals[i][0] + signals[i][1] + signals[i][2];
        L = lcm(L, allTime[i]);
    }
    
    for(int t = 1; t <= L ; ++t)
    {
        bool allYellow = true;
        for(int i = 0 ; i < signalSize ; ++i)
        {
            int check = (t - 1) % allTime[i];
            if(!(check >= yellow[i][0] && check < yellow[i][1])) 
            {
                allYellow = false;
                break;
            }
        }
        if(allYellow) return t;
    }

    return -1;
}