#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<pair<int,int>> miningLevel; // 다이아 많은 순으로 그 후 철 많은 순 <level,index>
vector<vector<int>> miningFatigue;

const int FATIGUE_1 = 1;
const int FATIGUE_5 = 5;
const int FATIGUE_25 = 25;
const int DIAMOND_LEVEL= 25;
const int IRON_LEVEL = 5;
const int STONE_LEVEL = 1;

void dig(vector<int>const& picks,vector<string>const& minerals){
    int s = min(2,3);
    int digCount = min((int)minerals.size(), (picks[0] + picks[1] + picks[2]) * 5);

    int levelSum=0;
    int diamondFatigueSum = 0, ironFatigueSum = 0, stoneFatigueSum = 0;
    int cycle = 0;

    for(int i = 0 ; i<digCount ; i++){
        if( i != 0 && i%5==0){
            miningLevel.push_back(make_pair(levelSum, i / 5 - 1));
            miningFatigue[0].push_back({diamondFatigueSum});
            miningFatigue[1].push_back({ironFatigueSum});
            miningFatigue[2].push_back({stoneFatigueSum});

            levelSum = 0;
            diamondFatigueSum = 0, ironFatigueSum = 0, stoneFatigueSum = 0;
            cycle++;
        }
        if(minerals[i]=="diamond"){
            levelSum += DIAMOND_LEVEL;

            diamondFatigueSum += FATIGUE_1;
            ironFatigueSum += FATIGUE_5;
            stoneFatigueSum += FATIGUE_25;
        }
        if (minerals[i] == "iron"){
            levelSum += IRON_LEVEL;
            diamondFatigueSum += FATIGUE_1;
            ironFatigueSum += FATIGUE_1;
            stoneFatigueSum += FATIGUE_5;
        }
         if (minerals[i] == "stone"){
            levelSum += STONE_LEVEL;
            diamondFatigueSum += FATIGUE_1;
            ironFatigueSum += FATIGUE_1;
            stoneFatigueSum += FATIGUE_1;
        }
    }
    if( diamondFatigueSum != 0){
        miningLevel.push_back(make_pair(levelSum, digCount / 5));
        miningFatigue[0].push_back({diamondFatigueSum});
        miningFatigue[1].push_back({ironFatigueSum});
        miningFatigue[2].push_back({stoneFatigueSum});
    }
}
int run(vector<int>const& picks){
    int diamond = picks[0], iron = picks[1], stone = picks[2];
    int minSum =0;
    sort(miningLevel.begin(),miningLevel.end(),greater<pair<int,int>>());

    for(auto m : miningLevel){
        if(diamond>0){
            minSum += miningFatigue[0][m.second];
            diamond--;
        }
        else if(iron>0){
            minSum += miningFatigue[1][m.second];
            iron--;
        }
         else if(stone>0){
            minSum += miningFatigue[2][m.second];
            stone--;
        }
    }

    return minSum;
}

int solution(vector<int> picks, vector<string> minerals){
    int answer = 0 ;
    miningFatigue.resize(3,vector<int>(0));
    dig(picks, minerals);
    answer = run(picks);
    return answer;
}


/*
// int** pickaxsFatigability;
// int mineralSize;

// void digMinerals(vector<string>const& minerals, vector<int>const& picks){
//     int diamondPickax = 0;
//     int ironPickax = 0;
//     int stonePickax = 0;
//     int cycle =0;
//     int pickaxs = picks[0] + picks[1] + picks[2];
//     int pickaxsAndMineralsCmp = mineralSize / 5 + 1 > pickaxs ? pickaxs : mineralSize / 5 + 1;

//     for (int i = 0; i < minerals.size(); i++){
//         if (i != 0 && i % 5 == 0){
//             pickaxsFatigability[0][i/5 - 1] = diamondPickax;
//             pickaxsFatigability[1][i/5 - 1] = ironPickax;
//             pickaxsFatigability[2][i/5 - 1] = stonePickax;

//             diamondPickax = 0;
//             ironPickax = 0;
//             stonePickax = 0;

//             cycle = i/5 - 1;
//             pickaxsAndMineralsCmp--;
            
//             if(pickaxsAndMineralsCmp ==0) break;
//         }

//         diamondPickax +=1;
//         if(minerals[i] == "diamond"){
//             ironPickax += 5;
//             stonePickax += 25;
//         }
//         else if (minerals[i] == "iron"){
//             ironPickax += 1;
//             stonePickax += 5;
//         }
//         else{
//             ironPickax += 1;
//             stonePickax += 1;
//         }
//     }
//     if (diamondPickax != 0){
//         pickaxsFatigability[0][cycle + 1] = diamondPickax;
//         pickaxsFatigability[1][cycle + 1] = ironPickax;
//         pickaxsFatigability[2][cycle + 1] = stonePickax;
//    }

// }

// int getMinFatigability(vector<int>const& picks){
//     int numberOfDiamondPickax = picks[0];
//     int numberOfIronPickax = picks[1];
//     int numberOfStonePickax = picks[2];
//     int pickaxs = picks[0] + picks[1] + picks[2];
//     int cycle = mineralSize / 5 + 1 > pickaxs ? pickaxs : mineralSize / 5 + 1 ;
//     int minSum = 0;
//     // int tail = mineralSize % 5;

//     priority_queue<pair<int,int>> pq;

//     // vector<pair<int,int>> v;
//     // for(int i =0 ; i <cycle;i++){
//     //     v.push_back(make_pair(pickaxsFatigability[2][i],i));
//     // }
//     // sort(v.begin(),v.end(),greater<pair<int,int>>());

//     // for(int i =0 ; i < cycle ;i++){
//     //     if (numberOfDiamondPickax-- > 0){
//     //         minSum += pickaxsFatigability[0][v[i].second];
//     //     }
//     //     else if (numberOfIronPickax-- > 0){
//     //         minSum += pickaxsFatigability[1][v[i].second];
//     //     }
//     //     else if (numberOfStonePickax-- > 0){
//     //         minSum += pickaxsFatigability[2][v[i].second];
//     //     }
//     // }

//     return minSum;
// }

// int solution(vector<int> picks, vector<string> minerals) {
//     int answer = 0;
//     mineralSize = minerals.size();
//     int pickaxs = picks[0] + picks[1] + picks[2];
//     pickaxsFatigability = new int*[3];
//     for (int i = 0; i < 3; i++)
//         pickaxsFatigability[i] = new int[mineralSize / 5 + 1 > pickaxs ? pickaxs : mineralSize / 5 + 1];

//     digMinerals(minerals, picks);
//     answer = getMinFatigability(picks);

//     return answer;
// }
*/
