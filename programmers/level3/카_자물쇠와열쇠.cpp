#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> virtualLock;
int borderStart,borderEnd;

bool check(int x, int y, vector<vector<int>> const &key)
{
    int startx = x, starty = y;
    int endx = x + key.size(), endy = y + key.size();
    for (int i = borderStart; i < borderEnd + 1; i++)
    {
        for (int j = borderStart; j < borderEnd + 1; j++)
        {
            if (i >= startx && i < endx && j >= starty && j < endy)
            {
                if (virtualLock[i][j] + key[i - startx][j - starty] != 1)
                {
                    return false;
                }
            }
            else{
                if (virtualLock[i][j] != 1)
                    return false;
            }
        } 
    }
    return true;
}

    vector<vector<int>> rotation(vector<vector<int>> const &key)
    {
        vector<vector<int>> rotationKey;

        for (int y = 0; y < key.size(); y++)
        {
            vector<int> dummy;
            for (int x = key.size() - 1; x >= 0; x--)
            {
                dummy.push_back(key[x][y]);
            }
            rotationKey.push_back(dummy);
        }
        return rotationKey;
    }

    bool solution(vector<vector<int>> key, vector<vector<int>> lock)
    {
        bool answer = true;
        int virtualLine = 2 * key.size() + lock.size() - 2;
        borderStart = key.size() - 1;
        borderEnd = key.size() + lock.size() - 2;
        vector<vector<int>> key90(rotation(key));
        vector<vector<int>> key180(rotation(key90));
        vector<vector<int>> key270(rotation(key180));

        for (int x = 0; x < virtualLine; x++)
        {
            vector<int> dummy;
            for (int y = 0; y < virtualLine; y++)
            {
                if (x < borderStart || x > borderEnd || y < borderStart || y > borderEnd)
                {
                    dummy.push_back(-1);
                }
                else
                {
                    dummy.push_back(lock[x - borderStart][y - borderStart]);
                }
            }
            virtualLock.push_back(dummy);
        }

        for (int x = 0; x <= borderEnd; x++)
        {
            for (int y = 0; y <= borderEnd; y++)
            {
                if(check(x,y,key)) return true;
                if (check(x, y, key90)) return true;
                if(check(x,y,key180)) return true;
                if(check(x,y,key270)) return true;
            }
        }
        return false;
    }