#include <string>
#include <vector>
#include <queue>

using namespace std;

int search(int nth,int factor, vector<vector<int>>const& wires) {
    bool visited[100] = { false };
    int cnt = 0;
    int root = wires[nth][factor];

    queue<int> bfs;
    bfs.push(root);
    visited[root] = true;

    while (!bfs.empty()) {
        int target = bfs.front();
        bfs.pop();

        for (int i = 0; i < wires.size(); i++) {
            if (i == nth) continue; //분할된 곳은 건너 뜀
            int w1 = wires[i][0];
            int w2 = wires[i][1];
            if (target == w1 && !visited[w2]) {
                bfs.push(w2);
                visited[w2] = true;
                cnt++;
            }
            else if (target == w2 && !visited[w1]) {
                bfs.push(w1);
                visited[w1] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;

    for (int i = 0; i < wires.size(); i++) {
        int gap = search(i, 0, wires) - search(i, 1, wires);
        gap = gap < 0 ? gap * (-1) : gap; 

        if (gap == 0)return 0;
        answer = answer < gap ? answer : gap;
    }


    return answer;
}