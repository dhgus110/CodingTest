#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>
#include <map>

using namespace std;

bool check[102];
//int d[102]; // 리프노드 순서상에서 리프노드가 몇 번 나왔는지
// int num[3]={1,2,3};
//int reafTable[102];
vector<vector<int>> reEdges(103);
string orders;
string order; // <-ㄹㅣ프노드 순서 저장
vector<int> vOrders;


void GetReafNodeOrder(int parent)
{
    //리프노드
    if (reEdges[parent].empty())
    {
        vOrders.push_back(parent);
        orders += to_string(parent);
        orders.push_back('.');
    }
    else
        for (int i = 0; i < reEdges[parent].size(); i++)
        {
            if (check[reEdges[parent][i]])
            {
                check[reEdges[parent][i]] = false;
                int next = i == reEdges[parent].size() - 1 ? 0 : i + 1;
                check[reEdges[parent][next]] = true;
                GetReafNodeOrder(reEdges[parent][i]);
                break;
            }
        }
}

int cnt =0;
bool cntCheck =false;

vector<int> customSort(vector<int>const&v)
{
    vector<int> re;
    int n[4]={0,0,0,0};
    for (int i = 0; i < v.size(); i++)
    {
        n[v[i]]++;
    }
    while(n[0] != 0){
        if(n[3]>0){
            n[0] -=1;
            n[3] -=1;
            n[1] +=1;
            n[2] +=2;
        }else if(n[2]>0){
            n[0] -=1;
            n[2] -=1;
            n[1] +=2;
        }
        else{
            re.push_back(-1);
            cntCheck = true;
            break; //실패 
        }
    }
    for(int i = 0 ;i <4 ; i++){
        for(int j = 0 ; j<n[i];j++){
            re.push_back(i);
            cnt++;
        }
        
    }
    return re;
}

map<int, vector<int>> getM(vector<int> const &target)
{
    vector<int> searchTarget(target.size());
    map<int, vector<int>> m;
    // int targetMax = accumulate(target.begin(), target.end(), 0);
    // int curSum = 0;

    int prePos = 0;
    int pos = order.find('.');
    int firstdot =pos;
    while (true)
    {
        if(searchTarget==target)break;
    
        string cur = order.substr(prePos, pos - prePos);
        int curNum = stoi(cur);
        if (target[curNum - 1] - searchTarget[curNum - 1] >= 3)
        {
            m[curNum].push_back(3);
            searchTarget[curNum-1] +=3;
        }
        else if (target[curNum - 1] - searchTarget[curNum - 1] == 2)
        {
            m[curNum].push_back(2);
            searchTarget[curNum-1] +=2;
        }
        else if (target[curNum - 1] - searchTarget[curNum - 1] == 1)
        {
            m[curNum].push_back(1);
            searchTarget[curNum-1] +=1;
        }
        else if (target[curNum - 1] - searchTarget[curNum - 1] == 0)
        {
            m[curNum].push_back(0);
        }

        if (pos == order.length() - 1)
        {
            prePos = 0;
            pos = firstdot;
        }
        else
        {
            prePos = pos + 1;
            pos = order.find('.', prePos);
        }
    }

    for(auto m1 : m){
        m[m1.first] = customSort(m1.second);
    }

    return m;
}


vector<int> solution(vector<vector<int>> edges, vector<int> target)
{
    vector<int> answer;
    vector<int> dummy;
    vector<int> searchTarget(target.size());
    edges.push_back({1'000, 1'000}); //reEdges 마지막 벡터 채우기위한 용도
    reEdges.push_back({0});          // reEdges[0]는 무시하기
    sort(edges.begin(), edges.end());
    int curParent = edges[0][0]; // =1
    bool dummyCheck = true;


    //테이블 만들기
    for (auto e : edges)
    {
        if (curParent != e[0])
        {
            reEdges[curParent] = dummy;
            dummy.clear();
            curParent = e[0];
            dummyCheck = true;
        }
        //길인 간선 true
        if (dummyCheck)
        {
            check[e[1]] = true;
            dummyCheck = false;
        }
        dummy.push_back(e[1]);
    }

    //fall & 리프 노드 규칙 구하기
    GetReafNodeOrder(1);
    GetReafNodeOrder(1);
    int left = orders.find('.');
    int right = orders.find('.', left);
    while(true)
    {
        GetReafNodeOrder(1);
        GetReafNodeOrder(1);
        string leftOrder = orders.substr(0, left);
        string rightOrder = orders.substr(left + 1, right);
        if (leftOrder == rightOrder)
        {
            order = leftOrder;
            break;
        }
        left = orders.find('.', left + 1);
        right = orders.find('.', right + 1);
    }
    order +=".";

    //순서(규칙)상에서 각 원소가 총 몇 번나왔는지
    // int prePos = 0;
    // int pos = orders.find('.');
    // while (true)
    // {
    //     string cur = order.substr(prePos, pos - prePos);
    //     d[stoi(cur)]++;
    //     prePos = pos + 1;
    //     if (pos == order.length())
    //         break;
    //     pos = orders.find('.', prePos);
    // }
    map<int, vector<int>> m = getM(target);
    if(cntCheck) return{-1};

    int prePos = 0;
    int pos = order.find('.');
    int firstdot =pos;
    int d[102];
    fill_n(d,102,0);
    int nCnt =0;
    
    while (true)
    {
        string cur = order.substr(prePos, pos - prePos);
        int curNum = stoi(cur);

        if(m[curNum][d[curNum]]==-1 || d[curNum]== m[curNum].size()) return {-1};
        if(nCnt ==cnt)break;
        answer.push_back(m[curNum][d[curNum]]);
        d[curNum] +=1; 
        nCnt+=1;
         if (pos == order.length() - 1)
        {
            prePos = 0;
            pos = firstdot;
        }
        else
        {
            prePos = pos + 1;
            pos = order.find('.', prePos);
        }
    }
    answer.pop_back();
    return answer;
}

//4.8.7.9.4.10.7.8.4.9.7.10.
//[0, 0, 0, 3, 0, 0, 5, 1, 2, 3]

//3 1 5 2 3 3

//3 1 3 2 0 3 2
//1 1 3 2 2 3
