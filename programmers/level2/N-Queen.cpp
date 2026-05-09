#include <string>
#include <vector>

using namespace std;

int answer = 0;
int N ;

bool check(const vector<int>& queen , int cx, int cy)
{
    for(int y = 0 ; y < queen.size() ; ++y){
        int x = queen[y];
        // x축 검사
        if(x == cx) return false;
        
        //왼 대각 검사
        for(int i = 1 ; i <= N ; ++i)
        {
            int nx = x - i;
            int ny = y + i;
            if(nx < 0 ) break;
            if( nx == cx && ny == cy) return false;
        }
        //오 대각 검사
        for(int i = 1 ; i <= N ; ++i)
        {
            int nx = x + i;
            int ny = y + i;
            if(nx >= N ) break;
            if( nx == cx && ny == cy) return false;
        }
    }
    return true;
}

void dfs(vector<int> queen)
{
    int ny = queen.size();
    
    if(ny == N) {
        ++answer;
        return;
    }
    
    for(int nx = 0 ; nx < N ; ++nx)
    {
        if(check(queen, nx, ny))
        {
            queen.emplace_back(nx);
            dfs(queen);
            queen.pop_back();
        }
    }
}

int solution(int n) {
    N = n;
    for(int x = 0 ; x < n ; ++x)
    {
        vector<int> queen;
        queen.emplace_back(x);
        dfs(queen);
    }

    return answer;
}