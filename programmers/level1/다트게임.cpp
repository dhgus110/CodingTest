#include <string>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int previousDart = 0;
    
    for(int i = 0; i <dartResult.size(); i++){ // 10 d # 5  i = 0 1 2 3
        int num=0;
        string snum="";
        //한자리 수인지 2자리 수인지
        snum.push_back(dartResult[i]);
        if(isdigit(dartResult[i+1])){
            snum.push_back(dartResult[i+1]);
            i++;
        }
        //step1
        num = stoi(snum); //숫자 추출

        //step2
        if (dartResult[i + 1] == 'D')
            num = num * num;
        else if (dartResult[i + 1] == 'T')
            num = num * num * num;
        i++;

        //step3
        if (dartResult[i + 1] == '*')
        {
            num *= 2;
            answer -= previousDart;
            answer += previousDart *2;
            i++;
        }
        if (dartResult[i + 1] == '#')
        {
            if(num !=0)
                num *= (-1);
            i++;
        }

        previousDart = num;
        answer += num;
        // cout<<num<<endl;
    }

    return answer;
}

int main(){
    cout<< solution("1S2D*3T")<<endl;
    // cout<< solution("1S*2D*3T*")<<endl;  // 1x2 x2 + 2^2x2 x2
}