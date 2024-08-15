//백준 11659번

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int mian(){
    int size, questions;
    cin >> size >> questions;

    int sum[100'001];
    for(int i = 1 ; i<=size; i++){
        int temp;
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }

    for (int i = 0; i < questions; i++){
        int start, end;
        cin >> start >> end;
        cout << sum[end] - sum[start - 1] << endl;
    }
}