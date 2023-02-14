#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> res;

void f(int length, vector<pair<int, int>> d, vector<int>const& elements) {
    vector<pair<int, int>> dummy;
    length += 1;
    for (int i = 0; i < elements.size() ; i++) {
        int elem = d[i].first;
        int last = d[i].second;
        int newLast = (last + 1) == elements.size() ? 0 : last + 1;
        int newElem = elem + elements[newLast];
        dummy.push_back({ newElem,newLast });
        res.insert(newElem);
    }

    if (length != elements.size()) f(length, dummy, elements);
}

int solution(vector<int> elements) {
    int answer = 0;
    vector<pair<int, int>> dummy;
    for (int i = 0; i < elements.size(); i++) {
        dummy.push_back({ elements[i],i });
        res.insert(elements[i]);
    }

    f(1, dummy, elements);

    return res.size();
}