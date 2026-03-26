/*
문제 분석 
 0 <= dist_limit <= 10^9
 1 <= split_limit <= 10^9 

 제한사항에서 10^9라 할지라도
 각 단계에서  2 or 3 배수로 분기 
 -> 완전 탐색 가능

 2^10 = 1024 = 약 10^3
 2^30 = 약 10^9  
 -> 최대 깊이 30~40 

*/
#include <string>
#include <vector>

typedef long long ll;
using namespace std;

int maxLeafNodeCnt = 0 ; 
int splitLimit;

/*
 split: 현재까지 사용한 총 노드 수
 parentNodeCnt: 현재 확장 가능한 부모 노드 수
 remainNodeCnt: 남은 depth (확장 가능 횟수)
 leafNodes: 현재 리프 노드 개수
*/
void dfs(ll split, ll parentNodeCnt, ll remainNodeCnt, ll leaveNodes)
{
    maxLeafNodeCnt = maxLeafNodeCnt < leaveNodes ? leaveNodes : maxLeafNodeCnt;

    if( parentNodeCnt == 0  && remainNodeCnt == 0) return;
    ll nodes = min(parentNodeCnt, remainNodeCnt); //가능한 만큼만 확장 

    if( split *2 <= splitLimit)
        dfs(split * 2, nodes * 2, remainNodeCnt - nodes, leaveNodes + nodes );

    
    if( split *3 <= splitLimit)
        dfs(split * 3, nodes * 3, remainNodeCnt - nodes, leaveNodes + nodes*2 );
}

int solution(int dist_limit, int split_limit) {
    splitLimit = split_limit;
    dfs(1, 1, dist_limit, 1);
    return maxLeafNodeCnt;
}
