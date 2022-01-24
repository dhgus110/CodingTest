#include <iostream>

using namespace std;

//서로소집합
int v, e; // v : 노드의 수 , e : 간선(Union연산)의 수
int parent[100000]; //부모 테이블 최대 100,000개라고 과정

int findParent(int x){
    if(x == parent[x])
        return x;
    return findParent(parent[x]);
}
//압축 find 함수 (더 빠르다).
int findParent2(int x){
    if(x == parent[x])
        return x;
    return parent[x]= findParent2(parent[x]); //바로 부모노드를 갱신
}

void unionParent(int a, int b){
    int parentA = findParent(a);
    int parentB = findParent(b);
    if (parentA < parentB) parent[b]= parentA;
    else parent[a] = parentB;
}



//서로소 집합 사이클
int main(){
    bool cycle = false;

    for (int i = 0; i < e; i++)
    { //간선 수 만큼
        int a, b; //확인 할 노드 넣기
        if (findParent2(a) == findParent2(b))
        {
            cycle = true;
            break;
        }
        else
        {
            unionParent(a, b);
        }
    }
}