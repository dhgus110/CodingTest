#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> renouncer1 = {1, 2, 3, 4, 5};
vector<int> renouncer2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> renouncer3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] ={0,0,0};
    int max_score=0;
    for(int i=0; i<answers.size();i++){
        if(answers[i]==renouncer1[i%5]) score[0]+=1;
        if(answers[i]==renouncer2[i%8]) score[1]+=1;
        if(answers[i]==renouncer3[i%10]) score[2]+=1;
    }

    max_score= max(max(score[0],score[1]),score[2]);
    for(int i =0; i<3 ;i++)
        if(score[i]==max_score) answer.push_back(i+1);
    return answer;
}

//5   1) 1, 2, 3, 4, 5
//8   2) 2, 1, 2, 3, 2, 4, 2, 5
//10  3) 3, 3, 1, 1, 2, 2, 4, 4, 5, 5