#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, wave = 0 ,index = 0;
    int range = 2 * w + 1;
    
    if(!stations.empty() && stations[index] - w <= 1)
        wave = stations[index++] + w;


    while(n > wave)
    {
        //cout<< " 시작 " << wave<<endl;

        int beginStation = stations[index] - w;
        int endStation = stations[index] + w;
        while( wave >= endStation && index < stations.size())
        {
            ++index;
            if( index >= stations.size()) break;

            beginStation = stations[index] - w;
            endStation = stations[index] + w;
        }

        while(beginStation - 1 <= wave && wave <= endStation && index < stations.size())
        {
            wave = endStation;
            //cout<< " 기지국 " << wave<<endl;

            ++index;
            if( index >= stations.size()) break;

            beginStation = stations[index] - w;
            endStation = stations[index] + w;
        }

        if(index >= stations.size() && n > wave)
        {
            int remain = n - wave ;
            int dummy = (remain % range) > 0 ? 1 : 0;
            answer += (remain/range) + dummy;
            //cout<< " 나머지 " << wave + remain <<endl;

            break;
        }

        if( n > wave)
        {
            wave += range;
            ++answer;   
        }
       // cout<< " 한칸 " << wave<<endl;

    }

    return answer;
}
