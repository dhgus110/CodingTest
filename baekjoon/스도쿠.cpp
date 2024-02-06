#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

int gameCount;
bool visited[101][6][6]; // '-'존재하면 false
string candidate[101][6][6];
string map[101][6][6];

//후보값 만들기
void makeCandidate()
{
    for (int order = 1; order <= gameCount; order++)
    {
        for (int row = 0; row < 6; row++)
        {
            for (int col = 0; col < 6; col++)
            {
                if(visited[order][row][col]) continue;

                int check[10]={0,};
                //x,y axis check
                for(int i = 0 ; i <6;i++){
                    if (i != col)
                    {
                        check[map[order][row][i][0] -'0']++;
                        if(map[order][row][i].size()>1)
                            check[map[order][row][i][2] -'0']++;
                    }
                    if(i!=row){
                        check[map[order][i][col][0]-'0']++;
                        if(map[order][i][col].size()>1)
                            check[map[order][i][col][2] -'0']++;
                    }
                }

                //3x2 sector check 
                int minY = (row & 1) == 1 ? row - 1 : row;
                int maxY = minY + 1;
                int minX = col == 0 ? 0 : (col / 3 == 0 ? 0 : 3);
                int maxX = minX + 2;
                for (int y = minY; y <= maxY; y++)
                {
                    for (int x = minX; x <= maxX; x++)
                    {
                        if (y == row && x == col) continue;
                        check[map[order][y][x][0] - '0']++;
                        if (map[order][y][x].size() > 1)
                            check[map[order][y][x][2] - '0']++;
                    }
                }

                for(int i = 1 ; i< 10; i++){
                    if (check[i] == 0) candidate[order][row][col] += to_string(i);
                }
            }
        }
    }
}

void makeSudoku(){
    for(int order = 1 ; order <= gameCount; order++){
        queue<pair<int,int>>  pos;
        for(int a = 0 ;a<6;a++){
            for(int b = 0 ;b<6;b++){
                if(!visited[order][a][b]){
                    pos.push(make_pair(a,b));
                }
            }
        }
        int bb=0;
        while(!pos.empty()){
            bb++;
            if(bb>62)break;
            int row =pos.front().first;
            int col = pos.front().second;
            pos.pop();
            int blankCount = count(map[order][row][col].begin(),map[order][row][col].end(),'-');
            int pivot = 0; // ex)  -/5 일 때  -자리에 5보다 작은 수가 들어가야함 pivot =5 ,updown=false
            bool updown =false; // down-false, up-true
            if(blankCount==1 && map[order][row][col].size()>1){
                if(map[order][row][col][0]=='-'){
                    pivot =map[order][row][col][2] -'0';
                }else{
                    pivot =map[order][row][col][0] -'0';
                    updown =true;
                }
            }

            //1. 후보값을 pivot과 비교하기
            //2. map에 저장되어 있는 값을 x,y축 , 3x2칸 들과 비교하기
            //3. 값이 정해지면 map에 저장
            //4. 정해지지 않았으면 cur을 다시 queue에 push

            //후보값 살아남으면 양수
            int val[10]={0,}; 
            for(auto cand :candidate[order][row][col]){
                val[cand-'0']++;
            }

            // 1.
            if(pivot != 0){
                if(updown)
                    for(int p = 0; p <= pivot; p++) val[p]--;
                else 
                    for(int p = pivot; p < 10; p++) val[p]--;

            }

            //2.
            //x,y axis check
            for(int i = 0 ; i <6;i++){
                if (i != col)
                {
                    // 숫자가 아닌 문자를 -'0'할 시 값은 0이 나옴
                    val[map[order][row][i][0] -'0']--;
                    if(map[order][row][i].size()>1)
                        val[map[order][row][i][2] -'0']--;
                }
                if(i!=row){
                    val[map[order][i][col][0]-'0']--;
                    if(map[order][i][col].size()>1)
                        val[map[order][i][col][2] -'0']--;
                }
            }
            //3x2 sector check 
            int minY = (row & 1) == 1 ? row - 1 : row;
            int maxY = minY + 1;
            int minX = col == 0 ? 0 : (col / 3 == 0 ? 0 : 3);
            int maxX = minX + 2;
            for (int y = minY; y <= maxY; y++)
            {
                for (int x = minX; x <= maxX; x++)
                {
                    if (y == row && x == col) continue;
                    val[map[order][y][x][0] - '0']--;
                    if (map[order][y][x].size() > 1)
                        val[map[order][y][x][2] - '0']--;
                }
            }

            //3.
            bool isSucces=false;
            int cnt = 0, val1 = 0, val2 = 0;
            for (int i = 1 ; i<10 ;i++)
            {
                if (val[i] > 0)
                {
                    cnt++;
                    if(val1 == 0) val1 = i;
                    else if(val2 == 0) val2 = i;
                }
            }
            if(blankCount == cnt){
                isSucces =true;
                if( map[order][row][col].size() ==1){
                   map[order][row][col][0] = val1 + '0';
                }else{
                   if(map[order][row][col][0]=='-'&&map[order][row][col][2]!='-'){
                        map[order][row][col][0] = val1 + '0';
                   }
                   else if(map[order][row][col][0]!='-'&&map[order][row][col][2]=='-'){
                        map[order][row][col][2] = val1 + '0';
                   }
                   else{
                        map[order][row][col][0] = val1 + '0';
                        map[order][row][col][2] = val2 + '0';
                   }
                }
                // cout<<"row :"<<row<<" col :"<<col<<" cnt:"<<cnt<<" ->"<<val1<<val2<<": "<<map[order][row][col]<<endl;
            }

            //4.
            if(!isSucces){
                pos.push(make_pair(row,col));
            }
        }
        cout<<"pos size: "<<pos.size()<<endl;
    }
}

int main()
{
    //input
    cin >> gameCount;

    for (int i = 0; i < gameCount; i++)
    {
        int order; //게임 순서
        cin >> order;
        cin.ignore();

        string x;
        for (int row = 0; row < 6; row++)
        {
            getline(cin, x);
            istringstream ss(x);
            string temp;
            int col = 0;

            while (getline(ss, temp, ' '))
            {
                if (temp.find("-") != string::npos)
                    visited[order][row][col] = false;
                else
                    visited[order][row][col] = true;
                map[order][row][col] = temp;
                col++;
            }
        }
    }

    //run
    makeCandidate();
    makeSudoku();

    //output
    for(int cnt =1 ; cnt <= gameCount ;cnt++){
        cout<<cnt<<endl;
        for (int row = 0; row < 6; row++){
            for (int col = 0; col < 6; col++){
                cout<< map[cnt][row][col]<<" ";
            }
            cout<<endl;
        }
    }
    
}


/* 입력 예시
1
1
- -/- -/- -/5 3 7
1/- - - 2 4/8 6/-
-/- - - - -/- -/-
- -/5 1/2 6/9 - -
- 2/7 6/9 4/- - -
-/- - - - -/- -/-
*/
