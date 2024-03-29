#include <string>
#include <vector>
#include <iostream>
#define PII pair<int,int>

using namespace std;

bool visited[51][51]; //방문한 곳과 테두리 안쪽 좌표만 방문처리 
vector<vector<int>> rec;

// 0 :up , 1:down , 2:right , 3:left
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


//모든 직사각형 안에 좌표가 있는지 전부 검사. (테두리 안쪽으로 이동 했을 시 true)
bool allRectangleInnerCheck(int x,int y){
    for(auto r : rec){
        if (r[0] < x && r[2] > x && r[1] < y && r[3] > y)   
            return true;
    }
    return false;
}

//현재 해당하는 직사각형 변 위에 좌표가 있으면 true
bool isIncludeSides(int x, int y , int cur ){
    int lx = rec[cur][0], ly = rec[cur][1], rx = rec[cur][2], ry = rec[cur][3];
    if ((x == lx || x == rx) && (y >= ly && y <= ry))  return true;
    else if ((y == ly || y == ry) && (x >= lx && x <= rx)) return true;
    return false;
}

//현재 좌표가 어떤 직사각형에 속해 있는지 
vector<int> belongToRectangle(int x, int y)
{
    vector<int> v ;
    for(int i = 0 ; i <rec.size(); i++)
    {
        if( isIncludeSides(x,y,i)) v.push_back(i);
    }
    return v;
}


// 어떤 방향으로 움직여야 하는지
int direction(int x,int y ,int belongTo, int notBelongTo = -1)
{
    for(int i = 0 ; i<4;i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if (isIncludeSides(nx, ny, belongTo) && !allRectangleInnerCheck(nx, ny))
        {
            if (notBelongTo != -1 && isIncludeSides(nx, ny, notBelongTo))
                continue;
            else
                return i;
        }
        return -1;
    }
}

//실행
int run(int startx, int starty, int goalx, int goaly)
{
    int moveCnt1 = 0, moveCnt2 = 0;
    int curx = startx, cury = starty;
    int curRec = -1, dummyRec = -1;

    visited[curx][cury] = true;
    vector<int> v(belongToRectangle(curx, cury));
    curRec= v[0];
    if( v.size() ==2) dummyRec = v[1];

    int dir = direction(curx, cury, curRec, dummyRec);
    if (dir == -1)
        return -1; //오류

    bool otherWay =false;
    int cnt =0 ;
    while (true)
    {
        cnt++;
        if(cnt >60) break;
        cout<<"rec:"<<curRec<<" dir:"<<dir<<"    c: "<< curx<<" "<<cury<<"   m:"<<moveCnt1<<" "<<moveCnt2<<endl; 

        int nx = dx[dir] +curx;
        int ny = dy[dir] +cury;

        //다음 좌표가 현재 직사각형 변 위에 있는지 ? 
        if(isIncludeSides(nx,ny,curRec)){
            //다음 좌표가 다른 직사각형 테두리 안으로 들어갔을 시  -> 직사각형을 바꿔준다.
            if(allRectangleInnerCheck(nx,ny)){
                visited[nx][ny] =true; 
                vector<int > dummy (belongToRectangle(curx,cury));
                curRec = (curRec == dummy[0] ? dummy[1] : dummy[0]);
                dummyRec = (curRec == dummy[0] ? dummy[0] : dummy[1]);
                dir = direction(curx, cury, curRec ,dummyRec);
                if(dir == -1) return -1; //오류
                // if (allRectangleInnerCheck(curx + dx[dir], cury + dy[dir])){
                //     visited[curx + dx[dir]][cury + dy[dir]] = true;
                //     dir = direction(curx, cury, curRec);
                // }
            }
            //그대로 쭉 갈 수 있을 경우
            else{
                visited[nx][ny] =true;
                curx =nx; cury =ny;
                if(!otherWay)moveCnt1++;
                else moveCnt2++;
            }
        }
        //현재 변위에 다음 좌표가 속해있지 않다면  현재 좌표는 꼭지점임
        else{ 
            dir = direction(curx, cury, curRec);
            if(dir == -1) return -1; //오류
        }

        if( curx==startx && cury ==starty && moveCnt2>0) break;
        //목표지점에 도달
        if(curx ==goalx && cury ==goaly ){
             visited[curx][cury] =false;
             otherWay = !otherWay;
        }
        
    }

    int result = moveCnt1< moveCnt2 ? moveCnt1 : moveCnt2;
    return result;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;

    //Init
    for(auto r : rectangle)
    {
        rec.push_back(r);
    }
    fill_n(&visited[0][0],51*51,false);

    answer = run(characterX,characterY,itemX,itemY);
    return answer;
}