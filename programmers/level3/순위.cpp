#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool visited[101];

//부모노드+자식노드 = n-1 이면 랭크를 확인 할 수 있음
int isChecked(int check,vector<vector<int>> const& results){
    stack<int> parents; //부모노드
    stack<int> childrens; //자식 노드
    visited[check] =true;
    int cnt = 0;

    for (auto r : results)
    {
        if (r[0] == check)  //check가 이겼을 때
        {
            childrens.push(r[1]); //자식 노드 저장
            visited[r[1]] = true; //자식노드 방문 처리
            cnt++;
        }
        else if (r[1] == check)// check가 졌을 때
        {
            parents.push(r[0]); //부모 노드 저장
            visited[r[0]] = true; //부모 노드 방문 처리
            cnt++;
        }
    }
    while ( !(childrens.empty() && parents.empty()) )
    {
        int parent;
        int children;
        if (!parents.empty())
        {
            parent = parents.top();
            parents.pop();
        }
        if (!childrens.empty())
        {
            children = childrens.top();
            childrens.pop();
        }
        for (auto r : results)
        {
            if (r[1] == parent && !visited[r[0]]) //부모 노드 확인
            {
                parents.push(r[0]);
                visited[r[0]] = true;
                cnt++;
            }
            else if(r[0] == children && !visited[r[1]]) //자식 노드 확인
            {
                childrens.push(r[1]);
                visited[r[1]] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        if (isChecked(i, results) == n - 1)
            answer++;
        fill_n(visited,101,false);
    }
    return answer;
}

//최악 1'000'000
