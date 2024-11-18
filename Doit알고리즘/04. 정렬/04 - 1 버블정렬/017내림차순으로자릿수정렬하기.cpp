//백준 1427
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>str;
}

void SelectSortStr(){
    for(int i = 0 ; i<str.length() ;i++){
        int max = max_element(str.begin() + i , str.end()) - str.begin();

        char temp = str[i];
        str[i] = str[max];
        str[max] = temp;
    }
}

int main(){
    init();
    // SelectSortStr();
    sort(str.begin(),str.end(),greater<>());
    cout << stoi(str);
}