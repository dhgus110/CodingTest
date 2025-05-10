#include <string>
#include <vector>
#include <iostream>

using namespace std;
int sizeN = {};
int result = {};
vector<vector<int>> vecQue;
vector<int> vecAns;

bool distinction(vector<int>* v)
{
    for(int i = 0 ; i < vecAns.size(); ++i)
    {
        int success = 0 ;
        int pointer_1  = 0;
        int pointer_2  = 0;
        
        while(pointer_1 <= 4 && pointer_2 <= 4 )
        {
            if((*v)[pointer_1] == vecQue[i][pointer_2] )
            {
                ++success;
                ++pointer_1;
            }
            else if((*v)[pointer_1] < vecQue[i][pointer_2] ) ++pointer_1;
            else ++pointer_2;
        }
        
        if( success != vecAns[i]) return false;
    }
    
    return true;
}

void make_code(int backIndex, int curOrder, vector<int>* v)
{
    if(curOrder == 4)
    {
        if(distinction(v)) ++result;
        return;
    }
    
    for(int i = backIndex + 1; i <= sizeN ; ++i)
    {
        (*v)[curOrder + 1] = i;
        make_code(i, curOrder + 1 , v);
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    sizeN = n;
    vecQue = q;
    vecAns = ans;
    
    for(int i = 1 ; i <= n ; ++i)
    {
        vector<int> temp(5,0);
        temp[0] = i;
        make_code(i,0,&temp);
    }

    return result;
}
