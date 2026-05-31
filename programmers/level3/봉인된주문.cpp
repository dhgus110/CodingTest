#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long banIndex(string ban)
{
    long long res = 0;
    long long multi =1;
    for(int i = ban.size() -1 ; i >= 0 ; --i)
    {
        res += (ban[i] - 'a' + 1) * multi;
        multi *= 26;
    }
    return res;
}

string banString(long long idx)
{
    string res = "";
    while ( idx > 0)
    {
        res += (idx % 26 + 1) + 'a'; 
        idx/=26;
    }

    reverse(res.begin(), res.end());
    return res;
}

string solution(long long n, vector<string> bans) {

    sort(bans.begin(),bans.end(), [](const string& a, const string& b){
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    long long cnt = 0;
    int index = 0;

    while( index < bans.size())
    {
        if(banIndex(bans[index]) < n )
        {
            ++n;
            ++index;
        }
        else break;
    }

    cout<< n<<endl;
    return banString(n);
}