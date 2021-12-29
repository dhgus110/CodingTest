#include <string>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
/*
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

*/

string solution(vector<int> numbers, string hand) {
    string answer = "";
    tuple <int,int,int> handL = make_tuple(3,0,10);
    tuple <int,int,int> handR = make_tuple(3,2,11);

    vector<tuple<int,int,int>> key;
    key.push_back(make_tuple(3,1,0));
    key.push_back(make_tuple(0,0,1));
    key.push_back(make_tuple(0,1,2));
    key.push_back(make_tuple(0,2,3));
    key.push_back(make_tuple(1,0,4));
    key.push_back(make_tuple(1,1,5));
    key.push_back(make_tuple(1,2,6));
    key.push_back(make_tuple(2,0,7));
    key.push_back(make_tuple(2,1,8));
    key.push_back(make_tuple(2,2,9));
    key.push_back(make_tuple(3,0,10));
  
    key.push_back(make_tuple(3,2,11));

    for(auto n : numbers){
        switch (n)
        {
        case 1:
            handL = key[1]; answer +="L"; break;
        case 4:
            handL = key[4]; answer +="L"; break;
        case 7:
            handL = key[7]; answer +="L"; break;
        case 3:
            handR = key[3]; answer +="R"; break;
        case 6:
            handR = key[6]; answer +="R"; break;
        case 9:
            handR = key[9]; answer +="R"; break;
        case 2:          
        case 5:
        case 8:
        case 0:
            int compL = abs(get<0>(handL)-get<0>(key[n]))+ abs(get<1>(handL)-get<1>(key[n]));
            int compR = abs(get<0>(handR)-get<0>(key[n]))+ abs(get<1>(handR)-get<1>(key[n]));
            if(compL==compR){
                if(hand=="left"){
                    handL= key[n];
                    answer +="L";
                }
                else{
                    handR= key[n];
                    answer +="R";
                }
            }
            else if(compL> compR){
                handR= key[n];
                answer +="R";
            }
            else{
                handL= key[n];
                answer +="L";
            }
            break;
        }
    }
    return answer;
}
int main(){
    cout<<solution({7,0,8},"left");
}