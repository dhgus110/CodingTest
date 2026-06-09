#include <string>
#include <vector>

using namespace std;

extern string submit(int);

int conversion(const vector<int>& v)
{
    return v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
}

int solution(int n) {

    int pivot = 1;
    vector<int> inclusionNum;
    while(true)
    {
        if(submit(pivot * 1111) == "0S 0B")
            break;
        
        inclusionNum.emplace_back(pivot);
        ++pivot;
    }
    
    int standardNum = pivot;
    vector<int> res(4, standardNum);
    vector<bool> check(4,false);
    int cnt = 0;
    
    for(int i = 0 ; i < inclusionNum.size() ; ++i)
    {
        int prev = -1;
        for(int j = 0 ; j < 3 ; ++j)
        {
            if(check[j]) continue;
            if(prev != -1) res[prev] = standardNum;

            res[j] = inclusionNum[i];
            
            string strRes = submit(conversion(res));
            int curStrike = strRes[0] - '0';
            if( cnt + 1 == curStrike )
            {
                check[j] = true;
                ++cnt;
                break;
            }
            prev = j;               
        }
    }
    
    ++pivot;
    
    while(cnt != 4)
    {
        int prev = -1;
        for(int i = 0 ; i < 4 ; ++i)
        {
            if(check[i] || (i == 0 && pivot ==0)) continue;
            if(prev != -1) res[prev] = standardNum;
            
            res[i] = pivot;
            string strRes = submit(conversion(res));
            int curStrike = strRes[0] - '0';
            if(curStrike == 4)
            {
                cnt = 4;
                break;
            }
            else if( cnt + 1 == curStrike )
            {
                check[i] = true;
                ++cnt;
                break;
            }
            prev = i;
        }
        pivot = pivot + 1 == 10 ? 0 : pivot + 1;
    }
    
    return conversion(res);
    
}
