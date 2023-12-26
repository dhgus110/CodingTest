#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    for (int i = 0; i < number.size() && k != 0; i++) {
        if (number[i] < number[i + 1]) {
            number.erase(i, 1);
            if (i == 0)      i -= 1;
            else            i -= 2;
            k--;
        }
    }
    if (k > 0)
        number.erase(number.size() - k, k);
    return number;
}

string solution2(string number, int k) {
    for(int i =0; i<number.size() - 1 && k !=0 ; i++){
        if(number[i]<number[i+1]){
            number.erase(i,1);
            if(i==0)i--;
            else i-=2;
            k--;
        }
    }
    if(k>0)
        number.erase(number.size() - k, k);
    return number;
}
