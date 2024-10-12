//백준 1874번
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> v(100'001);
vector<char> result;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
}

bool run(){
    stack<int> s;
    int num =1;

    for (int i = 0; i < n; i++){
        if(v[i] >= num){
            while(v[i] >= num){
                s.push(num++);
                result.push_back('+');
            }

            s.pop();
            result.push_back('-');
        }
        else if( v[i] == s.top()){
            s.pop();
            result.push_back('-');
        }
        else{
            return false;
        }

    }

    return true;
}

int main(){
    init();

    if(run()){
        for(auto r: result){
            cout<<r<<'\n';
        }
    }
    else{
        cout<<"NO";
    }
}
