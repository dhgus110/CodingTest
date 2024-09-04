//백준 11657번
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int nodeSize, edgeSize;
int table[101][101];

void init(){
    cin >> nodeSize >> edgeSize;
    fill_n(&table[0][0], 101 * 101, INF);

    for(int i = 1 ; i <= nodeSize ; i++){
        table[i][i] =0;
    }

    for (int i = 0; i < edgeSize; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        table[start][end] = weight;
    }
}

void floydwarshall(){
    for (int mid = 1; mid <= nodeSize; mid++){
        for (int start = 1; start <= nodeSize; start++){
            for (int end = 1; end <= nodeSize; end++){
                if (table[start][end] > table[start][mid] + table[mid][end])
                    table[start][end] = table[start][mid] + table[mid][end];
            }
        }
    }
}

void print(){
    for (int i = 1; i < nodeSize; i++){
        for (int j = 1; j < nodeSize; j++){
            if (table[i][j] == INF)
                cout << "0 ";
            else
                cout << table[i][j] << " ";
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    floydwarshall();
}