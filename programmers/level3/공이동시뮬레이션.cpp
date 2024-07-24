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
#include <cstdlib>

#define ll long long

using namespace std;

ll border[4] = {0, 0, 0, 0}; //왼쪽, 오른쪽, 아래쪽, 위쪽 마지막 면
ll movex =0, movey =0; // 총 이동 거리

void print(vector<int>const& v){
    for(auto vv : v){
        cout<<vv<<" ";
    }cout<<endl;
}

//todo  dx가 점과 진행방향의 벽 사이의 거리보다 크다면 아무의미도 없으니 어떻게 처리할까....
pair<ll,ll> run(ll x, ll y, vector<vector<int>>const& queries){
    for(auto q: queries){
        //왼쪽으로 이동
        if(q[0] == 0){

            //이동한 공이 경계면에서 벗어 났을 때
            if( x - q[1] < border[q[0]]){
                border[q[0]] = border[q[0]] + q[1] - (x - border[q[0]]);
                x = border[q[0]];
            }

            //이공한 공이 경계면에서 벗어 나지 않았을 때
            else x -= q[1];

            //이동한 공이 반대벽과 만났을 시
            if(x > border[1]) x = border[q[0]] = border[1];
            movex -= q[1];
        }
        //오른쪽으로 이동
        else if (q[0] == 1){
            if( x + q[1] > border[q[0]]){
                border[q[0]] = border[q[0]] - (q[1] - (border[q[0]] - x));
                x = border[q[0]];
            }
            else x += q[1];
            if(x < border[0]) x = border[q[0]] = border[0];
            movex += q[1];
        }
        //아래로 이동
        else if (q[0] == 2){
            if (y - q[1] < border[q[0]]){
                border[q[0]] = border[q[0]] + q[1] - (y - border[q[0]]);
                y = border[q[0]];
            }
            else y -= q[1];
            if(y > border[3]) y = border[q[0]] = border[3];
            movey -= q[1];
        }
        //위로 이동
        else if (q[0] == 3){
            if( y + q[1] > border[q[0]]){
                border[q[0]] = border[q[0]] - (q[1] - (border[q[0]] - y));
                y = border[q[0]];
            }
            else y += q[1];
            if(y < border[2]) y = border[q[0]] = border[2];
            movey += q[1];
        }
    }

    return {x,y};
}

ll operation(pair<ll, ll> pos, int n, int m){
    ll foldx = 1, foldy = 1;
    ll curx = pos.first;
    ll cury = pos.second;

    if (curx <= border[0] && curx < border[1]) foldx = border[0] + 1;
    else if (curx > border[0] && curx >= border[1]) foldx = m - border[1] + 1;
    else if (border[0] == border[1]) foldx = m;

    if (cury <= border[2] && cury < border[3]) foldy = border[2] + 1;
    else if (cury > border[2] && cury >= border[3]) foldy = n - border[3] + 1;
    else if (border[2] == border[3]) foldy = n;
 

    for(int i = 0 ; i <4; i++) cout<<border[i]<<" ";
    cout<<endl<<endl;
    cout<<"현재 점의 위치 : "<<curx<<" "<<cury<<endl;
    cout<<"접힘 수 : "<<foldx<<" "<<foldy<<endl;
    cout<<"총 이동 거리 : "<< movex<<" "<<movey<<endl;

    return foldx * foldy;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    //init
    border[1] = m - 1;
    border[3] = n - 1;
    reverse(queries.begin(),queries.end());

    //쿼리를 거꾸로 실행 후 점의 위치와 경계면들의 접힘의 정도
    auto position = run(y, x, queries);

    //시작점으로 있을 수 있는 위치들을 계산
    answer = operation(position, n ,m);

    return answer;
}