#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int n,m; //n=도시 , m=버스
int gragh[100][100]; //2차원 그래프) 도시a에서 도시b로 가는 비용 그래프

int main(){
    cin >> n >> m;

    //바용 그래프 무한값으로 초기화
    for(int i =0; i<100 ; i++){
        fill(gragh[i],gragh[i]+100 ,INF);
    }

    //자기 자신에서 자기 자신으로 가는 비용 0
    for(int x = 0; x<n; x++){
        for( int y= 0; y<n ;y++){
            if(x==y) gragh[x][y] =0;
        }
    }
    
    for(int i = 0 ; i <m ;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (c < gragh[a-1][b-1]) //최단 간선 정보만 저장
            gragh[a-1][b-1] = c;
    }

    //플로이드 워셜 알고리즘
    // k: 거쳐가는 노드, a: 출발 노드, b: 도착 노드
    for (int k = 0; k < n; k++){
        for (int a = 0; a < n; a++){
            for (int b = 0; b < n; b++){
                gragh[a][b] = min(gragh[a][b], gragh[a][k] + gragh[k][b]);
            }
        }
    }

    //출력
    for(int a = 0; a < n ; a++){
        for(int b = 0 ; b < n ; b++){
            if( gragh[a][b]==INF) cout<<0<<' '; //도달할 수 없을 경우 0 
            else cout<<gragh[a][b]<<' ';
        }
        cout<<'\n';
    }

}