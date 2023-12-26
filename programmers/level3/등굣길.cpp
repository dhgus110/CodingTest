#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(n,vector<int>(m,1)); //모든 좌표 1

    for (auto p : puddles)
    {
        if (p[0] == 1) //첫번째 열의 경우
            for (int i = p[1] - 1; i < n; i++)
                map[i][0] = 0;
        else if (p[1] == 1) //첫번째 행의 경우
            for (int i = p[0] - 1; i < m; i++)
                map[0][i] = 0;
        else
            map[p[1] - 1][p[0] - 1] = 0; //물 웅덩이 지역은 0
    }

    for(int i = 1 ; i< m ; i++){
        for(int j = 1; j<n ; j++){
            if(map[j][i] != 0)
                map[j][i] = (map[j - 1][i] + map[j][i - 1]) % 1000000007;
        }
    }
    //int answer = map[n-1][m-1];
    return map[n-1][m-1];

}


// int solution(int m, int n, vector<vector<int>> puddles) {
//     int answer = 0;
//     vector<vector<int>> path(n,vector<int>(m,1));
//     if(!puddles.empty()){
//     for(auto a : puddles){
//         // 첫 번째 열 중 puddles에 해당하는 경우, 첫 번째 열 puddles 이후 전부 0으로 변경
//         if(a.front()-1 ==0){
//             for(int i = a.back()-1; i<n ;i++)
//                 path[i][a.front()-1]=0;
//         }
//         //마찬가지로 첫 번째 행에서 puddles에 해당하는 경우..
//         if(a.back()-1 == 0 ){
//             for(int i = a.front()-1; i<m ;i++)
//                 path[a.back()-1][i]=0;
//         }
//         path[a.back()-1][a.front()-1]=0;
//     }}

//     for(int x =1 ; x<m ; x++){
//         for(int y =1 ; y<n ; y++){
//             if (path[y][x] == 0)
//                 path[y][x] = 0;
//             else
//                  //효율성 테스트 케이스가 넓이와 높이가 크게 설정되어 있는데 그러다 보니 중간 계산과정에서도 long 사이즈를 넘어 overflow가 발생합니다.
//                  //Point = Point의 왼쪽 + Point의 위쪽
//                 path[y][x] = (path[y][x-1] + path[y-1][x])%1000000007; 


//         }
//     }
//     answer = path[n-1][m-1];
//     cout<<answer;
//     return answer;
// }

// int main(){
//     solution(4,3,{{1,2},{2,1}});
// }
