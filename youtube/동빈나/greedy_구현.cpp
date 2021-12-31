#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <queue>

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


//문제 : 시각
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

//문제 : 왕실의 나이트
int isPath(int x, int y){
    int goX[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
    int goY[8] = {-1, 1, -1, 1, -2, 2, -2, 2};
    int cnt= 8;
    for(int i = 0 ;i <8; i++){
        int px = x + goX[i];
        int py = y + goY[i];
        if (px < 1 || px > 8 || py < 1 || py > 8)
            cnt--;
    }
    return cnt;
}

int solution3(string s){
    int result=0;
    result = isPath((int)(s[0]-'a')+1, s[1]-'0');
    return result;
}


//문제 : 문자열 재정렬
string solution4(string s){
    regex re("([A-Z]*)([0-9]*)");

    sregex_iterator it(s.begin(), s.end(), re);
    sregex_iterator end;

    string str = "";
    string dig = "";
    string result = "";

    while(it != end){
        smatch sm =*it;
         for (int i = 0; i < sm.size(); i++)
        {
            if(i==1) str += sm[i];
            else if( i==2) dig += sm[i];

            // cout << "i: " << i << " .." << sm[i] << "  type : "<<typeid(sm[i]).name() <<endl;
        }
        it++;
    }
    sort(str.begin(),str.end());
    sort(dig.begin(),dig.end());
    result += str;
    result += dig;
    return result;
}


int main(){
    cout<< solution4("K1VIG352AAAAAAAA4FID244S2G4");
}