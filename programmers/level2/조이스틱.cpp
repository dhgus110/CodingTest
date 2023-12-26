#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.size();
    string start(size,'A');

    queue <pair<pair<string,int>,int>> q;  //[[문자열, 문자열 인덱스], 카운터]
    q.push({{start,0},0});

    while(!q.empty()){
        string s = q.front().first.first;
        int index =q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(s[index] != name[index]){
            if(name[index]<'N')
                cnt += (name[index] - 'A');
            else
                cnt += 26 -(name[index] - 'A');

            s[index] = name[index];
        }

        if(s==name){
            answer =cnt;
            break;
        }

        int left = index - 1, right = index + 1;
        if (left < 0)
            left = size - 1;
        if (right >= size)
            right = 0;

        q.push({{s, left}, cnt + 1});
        q.push({{s, right}, cnt + 1});
    }
    return answer;
 }

//A B A B A A A B A