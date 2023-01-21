#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
//1. "UPDATE r c value"
//2. "UPDATE value1 value2"
//3. "MERGE r1 c1 r2 c2"
//4. "UNMERGE r c"
//5. "PRINT r c"

void update1(vector<vector<string>>& table, int r, int c, string value) {
    table[r][c] = value;
}
void update2(vector<vector<string>>& table, string value1, string value2) {
    for (int x = 1; x < 51; x++) {
        for (int y = 1; y < 51; y++)
            if (table[x][y] == value1)table[x][y] = value2;
    }
}
void merge(vector<vector<string>>& table, vector<pair<string, vector<pair<int, int>>>>& mergeTable, int r1, int c1, int r2, int c2) {
    string original = table[r1][c1];
    string change = table[r2][c2];
    bool check = false;

    table[r2][c2] = table[r1][c1];

    for (int i = 0; i < mergeTable.size(); i++) {
        if (mergeTable[i].first == original) {
            mergeTable[i].second.push_back({ r2,c2 });
            check = true;
            break;
        }
    }
    if (!check) {
        mergeTable.push_back({ original,{{r1,c1},{r2,c2}} });
    }

}
void unmerge(vector<vector<string>>& table, vector<pair<string, vector<pair<int, int>>>>const& mergeTable, int r, int c) {
   /* for (auto m : mergeTable[r][c]) {
        table[m.first][m.second] = "EMPTY";
    }*/
}


vector<string> solution(vector<string> commands) {
    vector<string> answer;
    vector<vector<string>> table(51,vector<string>(51,"EMPTY"));
    //vector<vector<vector<pair<int, int>>>> mergeTable(51, vector<vector<pair<int, int>>>(51));
    vector<pair<string, vector<pair<int,int>>>> mergeTable;
    for (auto command : commands) {
        stringstream ss(command);
        string s1, s2, s3, s4, s5;
        ss >> s1 >> s2 >> s3 >> s4 >> s5;
        if (s1 == "UPDATE") {
            if (!s4.empty()) update1(table, stoi(s2), stoi(s3), s4);
            else update2(table, s2, s3);
        }
        else if (s1 == "MERGE") {
            merge(table, mergeTable, stoi(s2), stoi(s3), stoi(s4), stoi(s5));
        }
        else if (s1 == "UNMERGE") {
            unmerge(table, mergeTable, stoi(s2), stoi(s3));
        }
        else {
            answer.push_back(table[stoi(s2)][stoi(s3)]);
        }
    }
    //for (auto ta : table) {
    //    for (auto t : ta) {
    //        if (t == "EMPTY") cout << " ";
    //        else cout << t << " ";
    //    }cout << endl;
    //}


    return answer;
}