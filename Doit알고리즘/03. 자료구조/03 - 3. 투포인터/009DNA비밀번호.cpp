//백준 12891번
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int ret;
string dna;
int dnaLength, passwordLength;
int minA, minC, minG, minT;

struct DNAINFO{
    int A;
    int C;
    int G;
    int T;
    // string DNA;

    void add(char c){
        if(c=='A')this->A++;
        else if(c=='C')this->C++;
        else if(c=='G')this->G++;
        else if(c=='T')this->T++;
        // DNA += c;
    }

    void remove(char c){
        if(c=='A')this->A--;
        else if(c=='C')this->C--;
        else if(c=='G')this->G--;
        else if(c=='T')this->T--;
        // DNA = DNA.substr(1);
    }

    bool check(){
        if (this->A >= minA && this->C >= minC && this->G >= minG && this->T >= minT)
            return true;
        return false;
    }
};

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> dnaLength >> passwordLength;
    cin >> dna;
    cin >> minA >> minC >> minG >> minT;
}

void run(){
    DNAINFO cur = {0, 0, 0, 0};
    //초기 부분 초기화
    for (int i = 0; i < passwordLength; i++){
        cur.add(dna[i]);
    }
    if(cur.check())ret++;

    for (int end = passwordLength; end < dnaLength; end++){
        int start = end - passwordLength;

        cur.add(dna[end]);
        cur.remove(dna[start]);

        if (cur.check()){
            ret++;
            // cout<<cur.DNA<<endl;
        }
    }
}

int main(){
    init();
    run();
    cout << ret << endl;
}