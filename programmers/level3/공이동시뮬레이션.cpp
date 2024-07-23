/*
    n행 m열 격자라 치고
    1. 공이 격자 밖으로 이동 시 공 바로 뒤에 공을 하나 더 생성
    (오른쪽경계선에서 +1 이동 한다 -> 기존 공은 그대로 있고 (n-1,y)에 공 하나 더 생성.. 이런식으로 계속 공을 생성)
    이건 공이 엄청 많이 생성 될 수도 있으므로 비효율적인 듯
    
    2. 공이 격자 밖으로 이동 시 격자를 접는 발상.
    (오른쪽경계선에서 +1 이동 한다 -> 기존 공은 (n-1,y)로 이동하고 격자 n열 과 n-1열을 합친다. )
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int border[4] = {0, 0, 0, 0}; //오른쪽,왼쪽,아래,위 경계선

void print(vector<int>const& v){
    for(auto vv : v){
        cout<<vv<<" ";
    }cout<<endl;
}

void run(int x, int y, vector<vector<int>>const& queries){
    for(auto q: queries){
        //왼쪽으로 이동
        if(q[0] == 0){
            //벗어 났을 때
            if( x - q[1] < border[q[0]]){
                border[q[0]] = q[1] - (x - border[q[0]]);
                x = border[q[0]];
            }
            //벗어 나지 않았을 때
            else{
                x -= q[1];
            }
            //이동한 공이 반대벽과 만났을 시
            if(x > border[1]) x = border[1];
        }
        //오른쪽으로 이동
        else if (q[0] == 1){
            if( x + q[1] > border[q[0]]){
                 border[q[0]] += border[q[0]] - (x + q[1]);
                 x = border[q[0]];
            }
            else x += q[1];
            if(x < border[0]) x = border[0];
        }
        //아래로 이동
        else if (q[0] == 2){
            if(y+q[1] >border[q[0]]){
                border[q[0]] = q[1] - (y - border[q[0]]);
                y = border[q[0]];
            }
            else y -= q[1];
            if(y > border[3]) y = border[3];

        }
        //위로 이동
        else if (q[0] == 3){
            if( y + q[1] > border[q[0]]){
                 border[q[0]] += border[q[0]] - (y + q[1]);
                 y = border[q[0]];
            }
            else y += q[1];
            if(y < border[2]) y = border[2];

        }
    }
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    //init
    border[1] = m ;
    border[3] = n ;
    reverse(queries.begin(),queries.end());

    run(x, y, queries);

    for(int i = 0 ;i<4 ;i++){
        cout<< border[i]<<" ";
    }
    long long foldx = border[1] - border[0] <= 1 ? m : m - (border[1] - border[0]) + 1;
    long long foldy = border[3] - border[2] <= 1 ? n : n - (border[3] - border[2]) + 1;

    return foldx * foldy;
}