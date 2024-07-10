
#include <string>
#include <vector>
#include <iostream>
#define INF 1e9

using namespace std;

int DP[181][181]; //[목표 알고력][목표 코딩력]
int GoalAlp;
int GoalCop;

void init(int alp, int cop, vector<vector<int>>const& problems){
    fill_n(&DP[0][0], 181 * 181, INF);
    DP[alp][cop] = 0;

    GoalAlp = alp;
    GoalCop = cop;
    for(auto p : problems){
        GoalAlp = GoalAlp < p[0] ? p[0] : GoalAlp;
        GoalCop = GoalCop < p[1] ? p[1] : GoalCop;
    }
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    problems.push_back({0,0,1,0,1});
    problems.push_back({0,0,0,1,1});
    init(alp, cop, problems);

    if (GoalAlp <= alp && GoalCop <= cop)
        return 0;

    // 코딩력, 알고력 중 하나만 이미 목표에 달성한 경우
    if(alp>GoalAlp) alp = GoalAlp;
    if(cop>GoalCop) cop = GoalCop;

    for(int a = alp ; a <= GoalAlp; a++){
        for (int c = cop; c <= GoalCop; c++){
            for(auto p : problems){
                // //알고리즘을 공부하여 알고력을 1 높이는 경우:
                // if (a + 1 <= GoalAlp)
                //     DP[a + 1][c] = min(DP[a + 1][c], DP[a][c] + 1);

                // //코딩을 공부하여 코딩력을 1 높이는 경우
                // if (c + 1 <= GoalCop)
                //     DP[a][c + 1] = min(DP[a][c + 1], DP[a][c] + 1);

                //문제 하나를 선택하여 알고력과 코딩력을 높이는 경우
                if (a >= p[0] && c >= p[1]){
                    int ma = min(a + p[2], GoalAlp);
                    int mc = min(c + p[3], GoalCop);
                    DP[ma][mc] = min(DP[ma][mc], DP[min(a, GoalAlp)][min(c, GoalCop)] + p[4]);
                }
            }
        }
    }

    return DP[GoalAlp][GoalCop];
}