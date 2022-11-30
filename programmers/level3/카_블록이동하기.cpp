#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node{
    public:
    int posX1;
    int posY1;
    int posX2;
    int posY2;
    Node(int posX1,int posY1,int posX2,int posY2){
        this->posX1=posX1;
        this->posY1=posY1;
        this->posX2=posX2;
        this->posY2=posY2;
    }
};

vector<Node> getNextPos(Node pos,vector<vector<int>> const& newBoard){
    vector<Node> getPos;

    //상하좌우 이동
    int dx[] ={0,0,1,-1};
    int dy[] = {-1,1,0,0};
    for(int i =0; i<4 ;i++){
        int posNextX1 = pos.posX1+dx[i];
        int posNextY1 = pos.posY1+dy[i];
        int posNextX2 = pos.posX2+dx[i];
        int posNextY2 = pos.posY2+dy[i];
        if (newBoard[posNextX1][posNextY1] == 0 && newBoard[posNextX2][posNextY2] == 0){
            getPos.push_back(Node(posNextX1,posNextY1,posNextX2,posNextY2));
        }
    }

    //회전
    int move[] = {1,-1};
    //현재 로봇이 가로로 놓여 있는 경우
    if(pos.posX1 == pos.posX2){
        for(int i=0;i<2;i++){
            if(newBoard[pos.posX1+move[i]][pos.posY1]==0&&newBoard[pos.posX2+move[i]][pos.posY2]==0){
            getPos.push_back(Node(pos.posX1,pos.posY1,pos.posX1+move[i],pos.posY1));
            getPos.push_back(Node(pos.posX2,pos.posY2,pos.posX2+move[i],pos.posY2));
            }
        }
    }
    //현재 로봇이 세로로 놓여 있는 경우
    if(pos.posY1 == pos.posY2){
        for(int i=0;i<2;i++){
            if(newBoard[pos.posX1][pos.posY1+move[i]]==0&&newBoard[pos.posX2][pos.posY2+move[i]]==0){
            getPos.push_back(Node(pos.posX1,pos.posY1,pos.posX1,pos.posY1+move[i]));
            getPos.push_back(Node(pos.posX2,pos.posY2,pos.posX2,pos.posY2+move[i]));
            }
        }
    }

    return getPos;
}

int solution(vector<vector<int>> board) {
    //맵 외곽에 벽을 두는 형태
    int n = board.size();
    vector<vector<int> > newBoard(n + 2, vector<int>(n + 2, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newBoard[i + 1][j + 1] = board[i][j];
        }
    }

    queue<pair<Node,int>> q;
    vector<Node> visited;
    Node pos={1,1,1,2}; //시작 위치

    q.push({pos,0}); //시작 위치 큐에 삽입
    visited.push_back(pos); //방문처리
    
    while(!q.empty()){
        Node curPos = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        //도착지점 도달 시 리턴
        if ((curPos.posX1 == n && curPos.posY1 == n) || (curPos.posX2 == n && curPos.posY2 == n))
            return cost;
        
        //이동 가능한 좌표
        vector<Node> nextPos =getNextPos(curPos,newBoard);
        for(int i = 0; i<nextPos.size();i++){
            // 아직 방문하지 않은 위치라면 큐에 삽입하고 방문 처리
            bool check = true;
            Node pos = nextPos[i];
            for (int j = 0; j < visited.size(); j++) {
                if (pos.posX1 == visited[j].posX1 && pos.posY1 == visited[j].posY1 && pos.posX2 == visited[j].posX2 && pos.posY2 == visited[j].posY2) {
                    check = false;
                    break;
                }
            }
            if (check) {
                q.push({pos, cost + 1});
                visited.push_back(pos);
            }
        }

    }

    return 0;
}

//bfs
//큐 사용
//visited, cost 이용
//