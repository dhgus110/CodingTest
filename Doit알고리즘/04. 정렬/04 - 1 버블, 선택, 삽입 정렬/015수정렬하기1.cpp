//백준 2750번
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<int> A(1000,0);

void init(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }
}

int main(){
    init();

    for(int i = 0 ; i < N - 1 ; i++){
        for(int j = 0 ; j < N - 1 ; j++){
            if(A[j] > A[j+1]){
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        cout << A[i] << '\n';
    }

}