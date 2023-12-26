#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <iostream>

using namespace std;

int solution(int N, int number)
{
    vector<set<int>> dp(9);

    for(int i = 1 ; i<9 ; i ++){
        dp[i].insert((pow(10,i)-1)/9 * N); // N , NN, NNN, NNNN ,... 저장
        for(int x = 1; x<i ; x++){
            for(int y = 1 ; y<i ; y++){
                if(x+y == i){ //N의 갯수가 i만큼 나와야 insert
                    for(int nx : dp[x]){
                        for(int ny : dp[y]){
                            dp[i].insert(nx+ny);
                            dp[i].insert(nx*ny);
                            if(nx / ny >0)
                                dp[i].insert(nx/ny);
                            if(nx - ny >0)
                                dp[i].insert(nx-ny);
                        }
                    }
                }
            }
        }
        if(dp[i].count(number)) return i;
        
    }

    return -1;
}

// int solution(int N, int number)
// {
//     vector<set<int>> dp(9);
//     for (int i = 1; i < 9; i++){
//         dp[i].insert((pow(10, i) - 1) / 9 * N);
//             for(int x =1 ; x <i ;x++){
//                 for(int y =1 ; y<i; y++){
//                     if(x+y == i){
//                         for (int s1 : dp[x]){  
//                             for (int s2 : dp[y]){
//                                 dp[i].insert(s1 + s2);
//                                 dp[i].insert(s1 * s2);
//                                 if ((s1 - s2) > 0)
//                                     dp[i].insert(s1 - s2);
//                                 if ((s1 / s2) > 0)
//                                     dp[i].insert(s1 / s2);
//                             }
//                         }
//                     }
//                 }
//             }
//         if (dp[i].count(number)) return i;
//     }
//     return -1;
// }