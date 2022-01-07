#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include<iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<int,int> maxOrder; //course수, 코스에 해당하는 최대 수
    map<int, vector<string>> kindOfOrders; //코스수, 조합된 음식 종류

    //orders 요소마다 정렬시키기
    for(int i = 0 ; i <orders.size() ; i++){
        sort(orders[i].begin(),orders[i].end());
    }

    //course 수에 따른 변수 초기화 시켜주기
    for(int i =0; i <course.size();i++){
        maxOrder[course[i]]=1;
        vector<string> tmp;
        kindOfOrders[course[i]]= tmp;
    }

    //orders가 전부 없어 질때 까지 돌거야
    while(orders.size()){
        // orders 처음 요소를 옮기고 삭제시켜주기.
        string cloneOrder = orders[0];
        int cloneOrderSize = cloneOrder.size();
        orders.erase(orders.begin());
        //조합수
        vector<int> tmp(cloneOrderSize,0);

        for(int co =0 ; co<course.size() ; co++){
            int c = course[co];
            // 만들려는 코스 수가 더 크면 건너띄기
            if(cloneOrderSize < c) continue;

            //조합 수 만들기  ex) 3C2 ->  {0,1,1}
            for(int i =cloneOrderSize-1 ; i>= cloneOrderSize-c ; i--){
                tmp[i] =1;
            }

            //tmp 순열 돌기
            do
            {
                //조합 수에 따른 메뉴 저장
                string menu = "";
                for (int i = 0; i < tmp.size(); i++){
                    if (tmp[i] == 1)
                        menu += cloneOrder[i];
                }

                int check = 1;
                //orders를 돌면서 조합수에따라만든 menu가 들어가 있는지 검사 ex) {ord : ABCD} {menu : AC} -> true
                for (auto ord : orders){
                    if (includes(ord.begin(), ord.end(), menu.begin(), menu.end())){
                        check++;
                    }
                }

                //겹치는게 없으면 건너띄기 (단 한개 뿐인 메뉴라는거임)
                if (check == 1)
                    continue;

                // check가 더 크다는 것은 가장 많이 찾은 메뉴라는 뜻..기존에 있던걸 clear하고 저장 시켜주자.
                if (maxOrder[c] < check){
                    kindOfOrders[c].clear();
                    kindOfOrders[c].push_back(menu);
                    maxOrder[c] = check;
                }else if (maxOrder[c] == check)
                    kindOfOrders[c].push_back(menu);

            } while (next_permutation(tmp.begin(), tmp.end()));
        }
    }

    for(auto ki : kindOfOrders){
        for(auto k : ki.second){
            answer.push_back(k);
        }
    }

    sort(answer.begin(),answer.end());
    return answer;
}

int main(){

    solution({ "ABCDE", "AB", "CDAB", "ABDE", "XABYZ", "ABXYZ", "ABCD", "ABCDE", "ABCDE", "ABCDE", "AB", "AB", "AB", "AB", "AB", "AB", "AB", "AB", "AB", "AB"},{2});
}


/*  // nCr 조합 구하기 (재귀)
void combination(int n, int r, int k=1)
{
    
    if (comb.size() == r)
    {
        string s= "";
        for (int i = 0; i < comb.size(); i++)
            s+= to_string(comb[i]);
        comb1.push_back(s);
    }
    else if (k == n + 1)
    {
    }
    else
    {
        comb.push_back(k);
        combination(n, r, k + 1);
        comb.pop_back();
        combination(n, r, k + 1);
    }
}*/
/* //순열사용한 조합 
set<string> combin(string order,int num){
    set<string> s;
    // ex: {1,1,0,0}  orders가 4자리 수이면 그 중에서 c 개만 뽑기
    vector<int> temp(order.size());
    for (int j = 0; j < num; j++)
    {
        temp[j] = 1;
    }
    //조합 (combination)구하기
    do
    {
        string menu = "";
        for (int j = 0; j < order.size(); j++)
        {
            if (temp[j] == 1)
            {
                menu += order[j];
            }
            else
                break;
        }
        // ex) CBA -> ABC로 정렬해서 저장
        sort(menu.begin(), menu.end());
        s.insert(menu);

    } while (next_permutation(order.begin(), order.end()));

    return s;
}
*/
//includes 사용법


