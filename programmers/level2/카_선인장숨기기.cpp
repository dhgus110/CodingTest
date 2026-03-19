#include <string>
#include <vector>
#include <deque>

using namespace std;
constexpr int INF = 1e9;
/*
슬라이딩 윈도우 최소값 + deque 최적화 

    크기 h x w 직사각형 영역마다
    그 영역 안의 최소값 구하기
*/

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<vector<int>> grid (m, vector<int>(n,INF));
    
    for(int i = 0 ; i < drops.size() ; ++i)
        grid[drops[i][0]][drops[i][1]] = i + 1;
    
    //row
    vector<vector<int>> rowMin (m, vector<int>(n - w + 1));
    
    for(int r = 0 ; r < m ; ++r)
    {
        deque<int> dq;
        
        for(int c = 0 ; c < n ; ++c)
        {
            //항상 최솟값이 front에 오도록 유지
            while(!dq.empty() && grid[r][dq.back()] >= grid[r][c])
                dq.pop_back();
            
            dq.emplace_back(c);
            
            if(dq.front() <= c - w)
                dq.pop_front();
            
            //각 행마다 길이 w짜리 구간의 최소값을 구함
            if(c >= w - 1)
                rowMin[r][c-w+1] = grid[r][dq.front()];
        }
    }
    
    //column
    int best = -1;
    int ansR = 0 , ansC = 0;
    
    for(int c = 0; c <= n - w; c++)
    {
        deque<int> dq;

        for(int r = 0; r < m; r++)
        {
            while(!dq.empty() && rowMin[dq.back()][c] >= rowMin[r][c])
                dq.pop_back();

            dq.emplace_back(r);

            if(dq.front() <= r - h)
                dq.pop_front();

            if(r >= h - 1)
            {
                //위에서 만든 rowMin을 이용해서 높이 h짜리 구간 최소값 계산
                int val = rowMin[dq.front()][c];
                int sr = r - h + 1;
                int sc = c;

                if(val > best)
                {
                    best = val;
                    ansR = sr;
                    ansC = sc;
                }
                else if (val == best)
                {
                    if (sr < ansR || (sr == ansR && sc < ansC))
                    {
                        ansR = sr;
                        ansC = sc;
                    }
                }
                    
            }
        }
    }

    return {ansR, ansC};
}