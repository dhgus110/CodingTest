#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

bool check[102];
int d[102];
int reafTable[102];
vector<vector<int>> reEdges(103);
string orders, order;
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

vector<int> solution(vector<vector<int>> edges, vector<int> target)
{
    vector<int> answer;
    vector<int> dummy;
    edges.push_back({1'000, 1'000}); //reEdges 마지막 벡터 채우기위한 용도
    reEdges.push_back({0});          // reEdges[0]는 무시하기
    sort(edges.begin(), edges.end());
    int curParent = edges[0][0]; // =1
    bool dummyCheck = true;
    int totalMax = accumulate(target.begin(), target.end(), 0);

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

    //순서(규칙)상에서 각 원소가 총 몇 번나왔는지
    int prePos = 0;
    int pos = orders.find('.');
    while (true)
    {
        string cur = order.substr(prePos, pos - prePos);
        d[stoi(cur)]++;
        prePos = pos + 1;
        if (pos == order.length())
            break;
        pos = orders.find('.', prePos);
    }



    return answer;
}

//리프 최대 100 각각 34
//3400 ?

//4 8 7 9 4 10 7 8 4 9 7 10