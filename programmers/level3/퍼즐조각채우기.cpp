#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <numeric>

using namespace std;

vector<vector<vector<int>>> samplingT; //table 퍼즐 조각크기에 맞춰 카드 만들기
vector<vector<vector<int>>> samplingB; //Board 퍼즐 조각크기에 맞춰 카드 만들기
bool visitedTable[51][51];
bool visitedBoard[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int lenght = 0;

//90도 회전
void rotationPuzzle(vector<vector<int>> & v){
    vector<vector<int>> temp(v[0].size(), (vector<int>(v.size(), 0)));
    for(int y = 0 ; y<temp.size();y++){
        for(int x = 0 ;x< temp[0].size();x++){
            temp[y][x] = v[x][temp.size() -1 -y];
        }
    }
    v.assign(temp.begin(),temp.end());
}

// 빈칸 최소한으로 샘플링 만들기
void makeSampling(int x, int y, bool table){
    queue<vector<int>> q ;
    vector<pair<int,int>> virPos; //가상좌표 더미
    int minx = 0, maxx = 0, miny = 0, maxy = 0;

    virPos.push_back(make_pair(0,0));
    q.push({x,y,0,0}); //실제좌표 , 가상좌표
    if(table) visitedTable[y][x] =false;
    else visitedBoard[y][x] =false;

    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int vx = q.front()[2];
        int vy = q.front()[3];
        q.pop();

        for(int i = 0 ; i <4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nvx = vx + dx[i];
            int nvy = vy + dy[i];
            bool check =false;

            if (nx < 0 || nx >= lenght || ny < 0 || ny >= lenght)
                continue;

            if (table && visitedTable[ny][nx])
            {
                q.push({nx, ny, nvx, nvy});
                virPos.push_back(make_pair(nvx, nvy));
                visitedTable[ny][nx] = false;
                check = true;
                }
                else if (!table && visitedBoard[ny][nx])
                {
                    q.push({nx, ny, nvx, nvy});
                    virPos.push_back(make_pair(nvx, nvy));
                    visitedBoard[ny][nx] = false;
                    check = true;
                }
            if(check){
                maxy = maxy < nvy ? nvy : maxy;
                miny = miny > nvy ? nvy : miny;
                maxx = maxx < nvx ? nvx : maxx;
                minx = minx > nvx ? nvx : minx;
            }

        }
    }

    vector<vector<int>> dummy(maxy - miny + 1, vector<int>(maxx - minx + 1, 0));
    for(auto v : virPos){
        dummy[v.second - miny][v.first - minx] = 1;
    }
    if(table) samplingT.push_back(dummy);
    else samplingB.push_back(dummy);
}

//2차원 벡터 비교
bool isEqual(vector<vector<int>> const &v1, vector<vector<int>> const &v2)
{
    auto pair = mismatch(v1.begin(), v1.end(), v2.begin());
    return (pair.first == v1.end() && pair.second == v2.end());
}

int compare(){
    int sum = 0;
    set<int> list;
    for(auto board : samplingB){
        int b_ysize = board.size();
        int b_xsize = board[0].size();

        for (int a = 0; a < samplingT.size(); a++){
            if(list.find(a) != list.end()) continue;
            bool check =false;
            for(int i = 0 ; i< 4; i++){
                rotationPuzzle(samplingT[a]);
                int t_ysize = samplingT[a].size();
                int t_xsize = samplingT[a][0].size();
                if( b_ysize != t_ysize || b_xsize != t_xsize) continue;
                if(isEqual(board,samplingT[a])){
                    for(auto b :board){
                        sum += accumulate(b.begin(),b.end(),0);
                    }
                    check = true;
                    list.insert(a);
                    break;
                }
            }
            if(check) break;
        }
    }
    return sum;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;

    //init
    fill_n(&visitedTable[0][0], 51 * 51, false);
    fill_n(&visitedBoard[0][0], 51 * 51, false);
    for(int y = 0 ; y<table.size() ; y++){
        for(int x = 0 ; x<table.size() ; x++){
            if(game_board[y][x] == 0 ){
                 visitedBoard[y][x] =true;
            }
            if(table[y][x]== 1) visitedTable[y][x] =true ;
        }
    }
    lenght = table.size();

    //sampling
    for (int y = 0; y < table.size(); y++){
        for (int x = 0; x < table.size(); x++){
            if (table[y][x] == 1 && visitedTable[y][x]) makeSampling(x, y, true);
            if (game_board[y][x] == 0 && visitedBoard[y][x]) makeSampling(x, y, false);
        }
    }

    // compare and count
    answer += compare();

    return answer;
}