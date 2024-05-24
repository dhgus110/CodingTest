#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<vector<int>,string>> convertMinPlans; // {{start, playtime}, name}

void init(vector<vector<string>>const& plans){
    for(auto p : plans){
        int min = (p[1][0] - '0') * 600 + (p[1][1] - '0') * 60 + (p[1][3] - '0') * 10 + (p[1][4] - '0');
        int play = stoi(p[2]);
        vector<int> dummy = {min, play};
        convertMinPlans.push_back(make_pair(dummy,p[0]));
    }
}

void SortAsc(){
    sort(convertMinPlans.begin(),convertMinPlans.end());
}

vector<string> run (){
    vector<string> result;
    stack<pair<vector<int>,string>> s ;
    int curOrder = 0;
    s.push(convertMinPlans[curOrder]);
    int i = 0 ;

    while(!s.empty()){

        int curJobStartTime = s.top().first[0];
        int curjobProcessTime = s.top().first[1];
        int curJobFinishTime = curJobStartTime + curjobProcessTime;
        string cur =s.top().second;
        s.pop();

        if (curOrder + 1 < convertMinPlans.size())
        {
            int nextJobStartTime = convertMinPlans[curOrder + 1].first[0];

            if (curJobFinishTime == nextJobStartTime)
            {
                result.push_back(cur);
                s.push(convertMinPlans[++curOrder]);
            }
            else if(curJobFinishTime > nextJobStartTime)
            {
                curjobProcessTime -= (nextJobStartTime -curJobStartTime);
                s.push(make_pair(vector{curJobStartTime, curjobProcessTime}, cur));
                s.push(convertMinPlans[++curOrder]);
            }
            else if (curJobFinishTime < nextJobStartTime)
            {
                int gapTime = nextJobStartTime - curJobFinishTime ;
                result.push_back(cur);
                while(gapTime > 0 ){
                    if(s.empty()){
                        s.push(convertMinPlans[++curOrder]);
                        break;
                    }
                    else if(gapTime > s.top().first[1]){
                        result.push_back(s.top().second);
                        s.pop();
                        if(!s.empty())
                            gapTime -= s.top().first[1];
                    }
                    else if ( gapTime == s.top().first[1]){
                        result.push_back(s.top().second);
                        s.pop();
                        s.push(convertMinPlans[++curOrder]);
                        gapTime = 0 ;
                    }
                    else if(gapTime < s.top().first[1]){
                        s.top().first[1] -= gapTime;
                        s.push(convertMinPlans[++curOrder]);
                        gapTime = 0 ;
                    }
                }
            }

        }
        else
        {
            result.push_back(s.top().second);
            s.pop();
        }
    }

    return result;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    init(plans);
    SortAsc();

    return run();
}