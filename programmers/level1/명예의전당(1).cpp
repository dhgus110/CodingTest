#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//vector�� ���԰� ���ÿ� ���� (�������� ���� upper_bound ����ص� ����������)
void insert_sorted(vector<int>& v, const int& index)
{
    const auto insert_pos(lower_bound(v.begin(), v.end(), index));
    v.insert(insert_pos, index);
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> ranks;
    for (auto s : score) {
        insert_sorted(ranks, s);
        int size = ranks.size();
        if (size < k)
            answer.push_back(ranks.front());
        else
            answer.push_back(ranks[size -k]);

        for (auto r : ranks)
            cout << r << " ";
        cout << endl;
    }

    return answer;
}