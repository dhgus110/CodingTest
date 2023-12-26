//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int minimumMovement2(vector<int> obstacleLanes) {
    int move = 0 ;
    int curNum= 0;
    int pos =2;
    int n1 =0;
    int n2 =0;
    int n3 =0;
    for(int i = 0 ; i <obstacleLanes.size();i++ ){
        if(obstacleLanes[i]==2){
            move++;
            curNum = i ;
            break;
        }
    }
    for(int i = curNum + 1 ; i <obstacleLanes.size();i++ ){
        if(obstacleLanes[i]==1) n1++;
        else if( obstacleLanes[i]==2) n2++;
        else if(obstacleLanes[i]==3) n3++;

        if(pos ==2 ){
            if(n1>0&&n3>0){
                move++;
                pos= obstacleLanes[i];
                n1=0;n2=0;n3=0;
            }
        }
         if(pos ==1 ){
            if(n2>0&&n3>0){
                move++;
                pos= obstacleLanes[i];
                n1=0;n2=0;n3=0;
            }
        }
         if(pos ==3 ){
            if(n1>0&&n2>0){
                move++;
                pos= obstacleLanes[i];
                n1=0;n2=0;n3=0;
            }
        }
    }
    return move;
}

vector<vector<int>> getMergedLineSegments(vector<vector<int>> lineSegments) {
    vector<vector<int>> res ;
    sort(lineSegments.begin(),lineSegments.end());
    int start =lineSegments[0][0];
    int end =lineSegments[0][1];

    for(auto  se : lineSegments){
        if(end<se[0]){
            res.push_back({start,end});
            start=se[0];
            end =se[1];
        }
        if(end<se[1]) end =se[1];
    }
    res.push_back({start,end});

    return res;
}


int GetMaxTime(vector<int> initialEnergy, long th) {
    sort(initialEnergy.begin(),initialEnergy.end(),greater<>());
    long long sum = accumulate(initialEnergy.begin(),initialEnergy.end(),0);
    int size = initialEnergy.size();
    int time =0;
    int index =0;
    while(true){
        if(sum<th) return time;
        time++;
        if(find(initialEnergy.begin(),initialEnergy.end(),time-1)!=initialEnergy.end()){
            index =size - (find(initialEnergy.begin(),initialEnergy.end(),time)-initialEnergy.begin())-1;  
        }
        sum =sum -size +index;
    }
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string obstacleLanes_count_temp;
    getline(cin, obstacleLanes_count_temp);

    int obstacleLanes_count = stoi(ltrim(rtrim(obstacleLanes_count_temp)));

    vector<int> obstacleLanes(obstacleLanes_count);

    for (int i = 0; i < obstacleLanes_count; i++) {
        string obstacleLanes_item_temp;
        getline(cin, obstacleLanes_item_temp);

        int obstacleLanes_item = stoi(ltrim(rtrim(obstacleLanes_item_temp)));

        obstacleLanes[i] = obstacleLanes_item;
    }

    int result = minimumMovement(obstacleLanes);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
