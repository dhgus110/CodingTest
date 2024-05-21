#include <string>
#include <vector>
#include <queue>

using namespace std;
int isVisited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int boardWidthSize, boardHightSize;
pair<int,int> robotStartPos, goalPos;


void init(vector<string>const& board){
    fill_n(&isVisited[0][0], 101 * 101, -1);
    boardWidthSize = board[0].length();
    boardHightSize = board.size();

    for (int i = 0; i < boardHightSize; i++){
        for(int j = 0 ;j< boardWidthSize ; j++){
            if(board[i][j]=='R') robotStartPos = make_pair(i,j);
            if(board[i][j]=='G') goalPos = make_pair(i,j);
        }
    }
}

bool safeArea(int x, int y){
    if (x >= 0 && y >= 0 && x < boardHightSize && y < boardWidthSize) return true;
    return false;
}


pair<int,int> moveStraightGetPos(pair<int,int> robotPos , int dir, vector<string>const& board){
    int x = robotPos.first;
    int y = robotPos.second;
    while(true){
        int nextx = x + dx[dir];
        int nexty = y + dy[dir];
        if (safeArea(nextx, nexty)){
            if(board[nextx][nexty]=='D'){
                return make_pair(x,y);
            }
            else{
                x= nextx; y =nexty;
            }
        }
        else{
            return make_pair(x,y);
        }
    }
}

//bfs 방식
int run(vector<string>const& board){
    queue<pair<int,int>> q ;
    q.push(robotStartPos);
    isVisited[robotStartPos.first][robotStartPos.second] +=1;

    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();

        for(int dir = 0 ; dir <4; dir++){
            pair<int,int> nextPos = moveStraightGetPos(pos, dir ,board);
            if (isVisited[nextPos.first][nextPos.second] == -1){
                isVisited[nextPos.first][nextPos.second]
                 = isVisited[pos.first][pos.second] + 1;

                 q.push(nextPos);
            }
            if(board[nextPos.first][nextPos.second]=='G'){
                return isVisited[nextPos.first][nextPos.second];
            }
        }

    }
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;

    init(board);
    answer = run(board);

    return answer;
}