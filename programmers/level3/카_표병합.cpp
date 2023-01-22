#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
//1. "UPDATE r c value"
//2. "UPDATE value1 value2"
//3. "MERGE r1 c1 r2 c2"
//4. "UNMERGE r c"
//5. "PRINT r c"

void update1(vector<vector<string>> &table, vector<vector<set<pair<int, int>>>> &mergeTable, int r, int c, string value)
{
    string original = table[r][c];

    if (!mergeTable[r][c].empty())
    {
        auto s = mergeTable[r][c];
        for (auto it = s.begin(); it != s.end(); it++)
        {
            table[it->first][it->second] = value;
        }
    }

    table[r][c] = value;
}
void update2(vector<vector<string>> &table, string value1, string value2)
{
    //병합안된 value1를 전부 value2로 변경 (단일)
    for (int x = 1; x < 51; x++)
    {
        for (int y = 1; y < 51; y++)
            if (table[x][y] == value1)
            {
                table[x][y] = value2;
            }
    }
}

//선택한 두 위치의 셀이 같은 셀일 경우 무시합니다.
//두 셀 중 한 셀이 값을 가지고 있을 경우 병합된 셀은 그 값을 가지게 됩니다.
//두 셀 모두 값을 가지고 있을 경우 병합된 셀은 (r1, c1) 위치의 셀 값을 가지게 됩니다.
void merge(vector<vector<string>> &table, vector<vector<set<pair<int, int>>>> &mergeTable, int r1, int c1, int r2, int c2)
{
    string original = table[r1][c1];
    string changed = table[r2][c2];
    string s;
    bool oneChoice = false;
    if (original == "EMPTY")
    {
        s = changed;
        oneChoice = true;
    }
    else if (changed == "EMPTY")
    {
        s = original;
        oneChoice = true;
    }
    auto s1 = mergeTable[r1][c1];
    auto s2 = mergeTable[r2][c2];
    mergeTable[r1][c1].insert({r1, c1});
    mergeTable[r2][c2].insert({r2, c2});

    if (s1.empty() && s2.empty())
    {
        if (oneChoice)
        {
            table[r1][c1] = s;
            table[r2][c2] = s;
        }
        else
            table[r2][c2] = original;

        mergeTable[r1][c1].insert({r2, c2});
        mergeTable[r2][c2].insert({r1, c1});
    }
    else if (s1.empty() && !s2.empty())
    {
        for (auto it = s2.begin(); it != s2.end(); it++)
        {
            if (oneChoice)
                table[it->first][it->second] = s;
            else
                table[it->first][it->second] = original;
            mergeTable[it->first][it->second].insert({r1, c1});
            mergeTable[r1][c1].insert({it->first, it->second});
        }
        if (oneChoice)
            table[r1][c1] = s;
    }
    else if (!s1.empty() && s2.empty())
    {
        if (oneChoice)
            table[r2][c2] = s;
        else
            table[r2][c2] = original;
        for (auto it = s1.begin(); it != s1.end(); it++)
        {
            if (oneChoice)
                table[it->first][it->second] = s;
            mergeTable[it->first][it->second].insert({r2, c2});
            mergeTable[r2][c2].insert({it->first, it->second});
        }
    }
    else if (!s1.empty() && !s2.empty())
    {
        for (auto it2 = s2.begin(); it2 != s2.end(); it2++)
        {
            if (oneChoice)
                table[it2->first][it2->second] = s;
            else
                table[it2->first][it2->second] = original;
            for (auto it1 = s1.begin(); it1 != s1.end(); it1++)
            {
                if (oneChoice)
                    table[it1->first][it1->second] = s;

                mergeTable[it1->first][it1->second].insert({it2->first, it2->second});
                mergeTable[it2->first][it2->second].insert({it1->first, it1->second});
            }
        }
    }

    // for (int x = 1; x < 6; x++)
    // {
    //     for (int y = 1; y < 6; y++)
    //     {
    //         auto s = mergeTable[x][y];
    //         if (!s.empty())
    //         {
    //             cout << "   " << x << y << " : ";
    //             for (auto it = s.begin(); it != s.end(); it++)
    //             {
    //                 cout << it->first << it->second << " ";
    //             }
    //             cout << endl;
    //         }
    //     }
    // }
}
void unmerge(vector<vector<string>> &table, vector<vector<set<pair<int, int>>>> &mergeTable, int r, int c)
{
    string original = table[r][c];
    auto s = mergeTable[r][c];
    for (auto it = s.begin(); it != s.end(); it++)
    {
        table[it->first][it->second] = "EMPTY";
        mergeTable[it->first][it->second].clear();
    }
    mergeTable[r][c].clear();
    table[r][c] = original;
}

vector<string> solution(vector<string> commands)
{
    vector<string> answer;
    vector<vector<string>> table(51, vector<string>(51, "EMPTY"));
    //vector<vector<vector<pair<int, int>>>> mergeTable(51, vector<vector<pair<int, int>>>(51));
    //map<string, set<pair<int, int>>> mergeTable;
    vector<vector<set<pair<int, int>>>> mergeTable(51, vector<set<pair<int, int>>>(51));
    int i = 0;
    for (auto command : commands)
    {
        stringstream ss(command);
        string s1, s2, s3, s4, s5;
        ss >> s1 >> s2 >> s3 >> s4 >> s5;
        if (s1 == "UPDATE")
        {
            if (!s4.empty())
                update1(table, mergeTable, stoi(s2), stoi(s3), s4);
            else
                update2(table, s2, s3);
        }
        else if (s1 == "MERGE")
        {
            merge(table, mergeTable, stoi(s2), stoi(s3), stoi(s4), stoi(s5));
        }
        else if (s1 == "UNMERGE")
        {
            unmerge(table, mergeTable, stoi(s2), stoi(s3));
        }
        else
        {
            answer.push_back(table[stoi(s2)][stoi(s3)]);
            continue;
        }

        // cout << i++ << endl;
        // for (int x = 1; x < 6; x++)
        // {
        //     for (int y = 1; y < 6; y++)
        //     {
        //         cout << table[x][y] << " ";
        //     }
        //     cout << endl;
        // }
    }

    return answer;
}
