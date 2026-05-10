#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    sort(works.begin(), works.end(), greater<int>());
    
    int index = 1;
    while(true)
    {
        if( n == 0) break;
        if(works[0] > works[index] && works[0] > 0)
        {
            for(int i = 0 ; i < index && n > 0 ;++i)
            {
                --works[i];
                --n;
            }
        }
        else if ( index < works.size()  && works[0] == works[index])
        {
            ++index;
        }
        else if ( index == works.size())
        {
            while( n != 0)
            {
                for(int i = 0 ; i < works.size() ; ++i)
                {
                    if( n == 0 ) break;
                    if( works[i] > 0)
                    {
                        --works[i];
                        --n;
                    }
                }
                if(works.back()==0) return 0;
            }
        }
    }

    for( int w : works)
    {
        answer += 1LL * w*w;
    }
    
    return answer;
}