//백준 1253번

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int mian(){
    int size;
    cin >> size;
    int n[size];
    for (int i = 0; i < size; i++){
        cin >> n[i];
    }

    sort(n, n + size);

    int answer = 0;
    for (int i = 0; i < size; i++){
        int find = n[i];
        int start = 0, end = n[size - 1];

        while(start<end){
            if (n[start] + n[end] == find){
                if(start != i && end != i){
                    answer++;
                    break;
                }
                else if(start == i){
                    start++;
                }
                else if(end ==i){
                    end--;
                }
            }
            else if(n[start] + n[end] < find){
                start++;
            }
            else{
                end--;
            }
        }
    }

    cout << answer;
}