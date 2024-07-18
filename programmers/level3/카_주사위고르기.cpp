#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void makeCase(int caseNumber, int size, vector<int> const& bSelectDice);

vector<vector<int>> DiceInfo;
vector<vector<int>> ASelectDice; 
vector<int> ACase[252]; // Acase[i] = 각 주사위에서 나올 수 있는 조합의 합을 저장(6^n/2개)
vector<int> BCase[252];
vector<int> VictoryCount;

void print(vector<int> const& v){
    if(v.empty()) return;
    for(auto vv: v){
        cout<<vv<<" ";
    }cout<<endl;
}

//1. A가 가져갈 주사위를 선택하는 부분 -> 최대 10C5 -> 252가지 존재
// 조합
int cArr[5] = { 0, };
void combination(int depth, int next, int size){
    if (depth == size / 2){
        vector<int> dummy;
        for (int i = 0; i < depth; i++){
            dummy.push_back(cArr[i]);
        }
        ASelectDice.push_back(dummy);
        return;
    }
    for(int i = next; i < size; i++){
        cArr[depth] = i;
        combination(depth + 1, i + 1 , size);
    }
}

//2. 가져간 주사위를 굴린 결과를 세는 부분 -> 최대 6^(n/2)
// 중복순열
int sArr[6] = { 0, };
void simulate(int caseNumber, int depth, int size, vector<int> const& bSelectDice){
    if(depth == size / 2){
        makeCase(caseNumber, size , bSelectDice);
        return;
    }

    for (int i = 0; i < 6; i++){
        sArr[depth] =i;
        simulate(caseNumber, depth + 1, size, bSelectDice);
    }
}

void makeCase(int caseNumber, int size, vector<int> const& bSelectDice){
    int aSum = 0, bSum = 0;
    for(int i = 0; i < size / 2; i++){
        aSum += DiceInfo[ASelectDice[caseNumber][i]][sArr[i]];
        bSum += DiceInfo[bSelectDice[i]][sArr[i]];
    }
    ACase[caseNumber].push_back(aSum);
    BCase[caseNumber].push_back(bSum);
}

vector<int> makeBSelectDiceCase(int aCaseNumber,int size){
    vector<int> bSelectDice;
    int dummy[10] ={0,};
    for(auto a : ASelectDice[aCaseNumber]){
        dummy[a]++;
    }
    for (int i = 0; i < size ; i++){
        if(dummy[i]==0) bSelectDice.push_back(i);
    }

    return bSelectDice;
}

void run(int n){
    int bPoint =0;
    int sum = 0; 
    for(auto a: ACase[n]){
        for(int i = bPoint; i<BCase[n].size(); i++){
            if (a <= BCase[n][i]){
                sum += i;
                break;
            }
        }
    }

    VictoryCount.push_back(sum);
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    DiceInfo = dice;
    combination(0, 0, dice.size());

    for (int i = 0; i < ASelectDice.size(); i++){
        simulate(i, 0, dice.size(), makeBSelectDiceCase(i, dice.size()));
    }

    //투 포인터를 하기 위한 정렬 (누적합, 이분탐색으로도 가능함)
    for (int i = 0; i < ASelectDice.size(); i++){
        sort(ACase[i].begin(),ACase[i].end());
        sort(BCase[i].begin(),BCase[i].end());
    }
    
    for (int i = 0; i < ASelectDice.size(); i++){
        run(i);
    }

    int maxIndex = max_element(VictoryCount.begin(), VictoryCount.end()) - VictoryCount.begin();
    // cout<<maxIndex<<endl;
    // print(VictoryCount);
    // for (auto a : ASelectDice){
    //     print(a);
    // }
    // cout<<"--------"<<endl;
    // for(int i = 0 ; i <ASelectDice.size();i++){
    //     print(ACase[i]); cout<<endl;
    // }

    for(auto a : ASelectDice[maxIndex]){
        answer.push_back(a + 1);
    }

    return answer;
}