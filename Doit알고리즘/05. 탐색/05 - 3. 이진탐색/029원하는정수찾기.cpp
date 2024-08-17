//백준 1920번
// lower_bound : 찾으려는 key 값보다 [같거나 큰] 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
// upper_bound : 찾으려는 key 값을 [초과하는] 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;

void binarySearch(int target){
    int front = 0, pivot, end = v.size() - 1;
    bool flag = false; // target을 찾았으면 true

    while(front <= end){
        pivot = (front + end) / 2;

        if( v[pivot] == target){
            flag =true;
            break;
        }
        else if(v[pivot] < target ){
            front = pivot + 1;
        }
        else if( v[pivot] > target){
            end = pivot - 1;
        }
    }
    if(flag) cout<<"1"<<endl;
    else cout<<"0"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arraySize ,findSize;
    cin >> arraySize;

    v.resize(arraySize);
    for(int i =0; i<arraySize; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    cin >> findSize;

    for (int i = 0; i < findSize; i++){
        int target;
        cin >> target;
        binarySearch(target);
    }
}