#include <iostream>
#include <string>
#include <vector>

using namespace std;

//문제 : 상하좌우
bool check(int x, int y, int size){
    if(x<1 || y<1 || x >size || y>size) return false;
    return true;
}
vector<int> solution1(int N, string path){

    vector<int> result;
    int dx[4],dy[4];
    dx[0]= 1; dy[0] = 0; //R
    dx[1]=-1; dy[1] = 0; //L
    dx[2]= 0; dy[2] = 1; //U
    dx[3]= 0; dy[3] =-1; //D

    int startX =1 ,startY =1;
    
    for(auto p : path){
        int go;
        switch (p)
        {
        case 'R':
            go = 0;
            break;
        case 'L':
            go = 1;
            break;
        case 'U':
            go = 2;
            break;
        case 'D':
            go = 3;
            break;
        }
        if(check(startX+dx[go],startY+dy[go],N)){
            startX += dx[go];
            startY += dy[go];
        }

    }
    result.push_back(startX);
    result.push_back(startY);

    return result;
}


//시각
int solution2(int N){
    int cnt =0;
    for (int hour = 0; hour < N+1; hour++)
    {
        for (int min = 0; min < 60; min++)
        {
            for (int sec = 0; sec < 60; sec++)
            {
                if (sec / 10 ==3) cnt++;
                else if (sec % 10 ==3) cnt++;
                else if (min / 10 ==3) cnt++;
                else if (min % 10 ==3) cnt++;
                else if (hour % 10 ==3) cnt++;
            }
        }
    }
    return cnt;
}


int main(){
    cout<< solution2(5);
}