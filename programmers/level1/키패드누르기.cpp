#include <string>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int rightH[2] = {3, 0};
    int leftH[2] = {3, 2};
    int key[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 0, 11}};

    for (int n : numbers)
    {
        int z, a, f = 0;
        bool endflag = 0;
        switch (n)
        {
        case 1:
        case 4:
        case 7:
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    if (key[y][x] == n)
                    {
                        z = abs(leftH[0] - y) + abs(leftH[1] - x);
                        leftH[0] = y;
                        leftH[1] = x;
                        endflag = 1;
                        break;
                    }
                }
                if (endflag)
                    break;
            }
            answer += "L";
            break;
        case 3:
        case 6:
        case 9:
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    if (key[y][x] == n)
                    {
                        z = abs(rightH[0] - y) + abs(rightH[1] - x);
                        rightH[0] = y;
                        rightH[1] = x;
                        endflag = 1;
                        break;
                    }
                }
                if (endflag)
                    break;
            }
            answer += "R";
            break;
        case 2:
        case 5:
        case 8:
        case 0:
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    if (key[y][x] == n)
                    {
                        a = abs(leftH[0] - y) + abs(leftH[1] - x);
                        z = abs(rightH[0] - y) + abs(rightH[1] - x);
                        if (a > z)
                        {
                            rightH[0] = y;
                            rightH[1] = x;
                            endflag = 1;
                            answer += "R";
                            break;
                        }
                        else if (a < z)
                        {
                            leftH[0] = y;
                            leftH[1] = x;
                            endflag = 1;
                            answer += "L";
                            break;
                        }
                        else
                        {
                            if (hand == "right")
                            {
                                rightH[0] = y;
                                rightH[1] = x;
                                endflag = 1;
                                answer += "R";
                                break;
                            }
                            else
                            {
                                leftH[0] = y;
                                leftH[1] = x;
                                endflag = 1;
                                answer += "L";
                                break;
                            }
                        }
                    }
                }
                if (endflag)
                    break;
            }
            break;
        }
    }

    return answer;
}

int main(){
   string s= solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}	,"right");
   cout<<s<<endl;
}

// tuple<int, int, int> t(int hand[], int key[4][3], int n)
// {
//     int z;
//     bool endflag = 0;
//     for (int y = 0; y < 4; y++)
//     {
//         for (int x = 0; x < 3; x++)
//         {
//             if (key[y][x] == n)
//             {
//                 z = abs(hand[0] - y) + abs(hand[1] - x);
//                 hand[0] = y;
//                 hand[1] = x;
//                 endflag = 1;
//                 break;
//             }
//         }
//         if (endflag)
//             break;
//     }
//     return make_tuple(z,hand[0],hand[1]);
// }
