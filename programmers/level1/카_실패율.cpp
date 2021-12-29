#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

bool cmp(const pair<int, double> &a, const pair<int, double> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> failureLate; //스테이지, 실패율
    vector<int> user(N);
    int users = stages.size();

    for(auto s : stages){
        if(s==N+1) continue;
        user[s-1]++;
    }
    for(int i = 0; i<user.size(); i++){
        double fail = (double)user[i]/(double)users;
        if(user[i] ==0) fail =0.0;
        failureLate.push_back(make_pair(i+1,fail ));
        users -=user[i];
    }

    sort(failureLate.begin(),failureLate.end(),cmp);
    for(auto f :failureLate){
        answer.push_back(f.first);
    }

    return answer;
}


int main(){
    // vector<int> v = solution(5, {2, 1, 2, 6, 2, 4, 3, 3}); //1 2 2 2 3 3 4 6    
    vector<int> v = solution(4, {2,2,2,4}); //1 2 2 2 3 3 4 6    

    for(auto vv : v){
        cout<<vv<<" ";
    }
}