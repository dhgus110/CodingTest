//백준 11660번

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int matrixSize, questions;
int origin[1025][1025];
int sum[1025][1025]; //특정 [x,y]의 구간합은 [1,1]~[x,y]의 구간합이다.

void init(){
    cin >> matrixSize >> questions;
    fill_n(&origin[0][0], 1025 * 1025, 0);
    fill_n(&sum[0][0], 1025 * 1025, 0);

    for (int i = 1; i <= matrixSize; i++){
        for (int j = 1; j <= matrixSize; j++){
            cin>>origin[i][j];
            //구간합 공식 : s[x,y] = o[x,y] +s[x-1, y] + s[x, y-1] - s[x-1, y-1];
            sum[i][j] = origin[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
}

//[x1,y1]~[x2,y2] 구간합 =s[x2,y2] - s[x1 - 1, y2] - s[x2, y1 - 1] + s[x1 - 1, y1 - 1];
void solution(){
    for (int i = 0; i < questions; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ret = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
        cout<<ret<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();
    
}