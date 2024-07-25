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

vector<vector<ll>> ballPosition(4,vector<ll>(2,0));

void print(vector<int>const& v){
    for(auto vv : v){
        cout<<vv<<" ";
    }cout<<endl;
}

void run(int n , int m, vector<vector<int>>const& queries){
    for(auto q :queries){
        switch(q[0])
        {
            case 0:
                ballPosition[0][0] -=  q[1];// 왼쪽
                ballPosition[1][0] -=  q[1];// 오른쪽
                break;
            case 1:
                ballPosition[0][0] +=  q[1];// 왼쪽
                ballPosition[1][0] +=  q[1];// 오른쪽
                break;
            case 2:
                ballPosition[2][0] -=  q[1];// 위쪽
                ballPosition[3][0] -=  q[1];// 아래쪽
                break;
            case 3:
                ballPosition[2][0] +=  q[1];// 위쪽
                ballPosition[3][0] +=  q[1];// 아래쪽
                break;
        }
        // 격자 map 를 나가는 경우 나간 만큼 접으면서 곂침 처리
        if(ballPosition[0][0] < 0)
        {
            ballPosition[0][1] += ( - ballPosition[0][0]);
            ballPosition[0][0] = 0;
        }
        if(ballPosition[0][0] >= m)
        {
            ballPosition[0][1] = m;
            ballPosition[0][0] = m-1;
        }
        if(ballPosition[1][0] >= m)
        {
            ballPosition[1][1] += (ballPosition[1][0] - m + 1);
            ballPosition[1][0] = m-1;
        }
        if(ballPosition[1][0] < 0)
        {
            ballPosition[0][1] = m;
            ballPosition[1][0] = 0;
        }
        if(ballPosition[2][0] < 0)
        {
            ballPosition[2][1] += ( - ballPosition[2][0]);
            ballPosition[2][0] = 0;
        }
        if(ballPosition[2][0] >= n)
        {
            ballPosition[2][1] = n;
            ballPosition[2][0] = n-1;
        }
        if(ballPosition[3][0] >= n)
        {
            ballPosition[3][1] += (ballPosition[3][0] - n + 1);
            ballPosition[3][0] = n-1;
        }
        if(ballPosition[3][0] < 0)
        {
            ballPosition[3][1] = n;
            ballPosition[3][0]  = 0;
        }
    }

    // 격자 맵 크기보다 큰 경우 격자 크기로 조절
    if(ballPosition[0][1] > m) ballPosition[0][1] = m;
    if(ballPosition[1][1] > m) ballPosition[1][1] = m;
    if(ballPosition[2][1] > n) ballPosition[2][1] = n;
    if(ballPosition[3][1] > n) ballPosition[3][1] = n;
}

ll operation(int n, int m, int x, int y){
    ll answer = -1;
    
    // 접힌 배열의 l,r,u,d 좌표
    ll  sy = ballPosition[0][0];
    ll  ey = ballPosition[1][0];
    ll  sx = ballPosition[2][0];
    ll  ex = ballPosition[3][0];

    // 접힌 배열이 x,y 에 없는 경우 0 리턴
    if( (sx <= x && sy <= y) && 
        (ex >= x && ey >= y) )
    {
        answer = m*n;
    } else
    {
        return 0;
    }

    // 접힌 곂침 수 추출
    ll  sym = ballPosition[0][1];
    ll  eym = ballPosition[1][1];
    ll  sxm = ballPosition[2][1];
    ll  exm = ballPosition[3][1];

    // 곂쳐진 x 값이 1개이면 곂침 수를 n 으로 통일
    if(sx == ex) 
    {
        sxm = n;
        exm = n;        
    }
    // 곂쳐진 y 값이 1개이면 곂침 수를 m 으로 통일
    if(sy == ey) 
    {
        sym = m;
        eym = m;
    }

    if(x == sx && y == sy)
    {
        // x,y 가 왼쪽 위 모서리인 경우
        answer = sxm * sym;
    } else if(x == sx && y == ey)
    {
        // x,y 가 오른쪽 위 모서리인 경우
        answer = sxm * eym;
    } else if(x == ex && y == sy)
    {
        // x,y 가 왼쪽 아래 모서리인 경우
        answer = exm * sym;
    } else if(x == ex && y == ey)
    {
        // x,y 가 오른쪽 아래 모서리인 경우
        answer = exm * eym;
    } else if(x == sx && (y > sy && y < ey) )
    {
        // x,y 가 위쪽 변인 경우
        answer = sxm;
    } else if(x == ex && (y > sy && y < ey) )
    {
        // x,y 가 아래쪽 변인 경우
        answer = exm;
    } else if(y == sy && (x > sx && x < ex) )
    {
        // x,y 가 왼쪽 변인 경우
        answer = sym;
    } else if(y == ey && (x > sx && x < ex) )
    {
        // x,y 가 오른쪽 변인 경우
        answer = eym;
    } else
    {
        // x,y 가 접히지 않은 위치인 경우
        answer = 1;
    }

    return answer;
}


long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    //init
    ballPosition[0][0] = 0;
    ballPosition[1][0] = m - 1;
    ballPosition[2][0] = 0;
    ballPosition[3][0] = n - 1;
    for(int i=0;i<4;i++)
    {
        ballPosition[i][1] = 1;
    }
    // reverse(queries.begin(),queries.end());

    //점의 위치와 경계면들의 접힘의 정도
    // auto position = run(y, x, queries);
    run(n, m, queries);

    return operation(n,m,x,y);
}