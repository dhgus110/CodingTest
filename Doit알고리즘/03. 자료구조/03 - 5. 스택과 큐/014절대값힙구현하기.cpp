//백준 11286번
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

//절대값 최소힙 +(절대값이 같은 경우 더 작은 값을 루트값으로)
template<typename T>
class HEAP {
    int size;
    T *heapArr;
private:
    void pushSwap(int n){
        if(n == 1) return;
        int parent = n / 2;
        //절대값으로 자식보다 부모가 더 크면 swap (최소힙)
        if (abs(heapArr[parent]) > abs(heapArr[n])){
            T tmp = heapArr[parent];
            heapArr[parent] = heapArr[n];
            heapArr[n] = tmp;

            pushSwap(parent);
        }
        else if (heapArr[parent] == -heapArr[n] && heapArr[parent] > heapArr[n]){
                T tmp = heapArr[parent];
                heapArr[parent] = heapArr[n];
                heapArr[n] = tmp;
        }
    }
    void popSwap(int n){
        int leftChild = (n * 2 <= size ? n * 2 : -1);
        int rightChild = (n * 2 + 1 <= size ? n * 2 + 1 : -1);
        int child;
        if (leftChild == -1 && rightChild == -1) child = -1;
        else if(leftChild != -1 && rightChild == -1) child = leftChild;
        else if(abs(heapArr[leftChild]) == abs(heapArr[rightChild])){
            child = heapArr[leftChild] < heapArr[rightChild] ? leftChild : rightChild;
        }
        else child = abs(heapArr[leftChild]) < abs(heapArr[rightChild]) ? leftChild : rightChild;

        if(child == -1) return;
        if(abs(heapArr[child]) < abs(heapArr[n])){
            T tmp = heapArr[child];
            heapArr[child] = heapArr[n];
            heapArr[n] = tmp;

            popSwap(child);
        }
        else if(heapArr[child] == -heapArr[n] && heapArr[child] < heapArr[n]){
            T tmp = heapArr[child];
            heapArr[child] = heapArr[n];
            heapArr[n] = tmp;
        }
    }
public:
    HEAP(int n){
        size = 0;
        heapArr = new int(n + 1);
    }
    ~HEAP(){
        delete[] heapArr;
    }
    bool empty(){
        if(size == 0 )return true;
        return false;
    }
    int amount(){
        return size;
    }
    T top(){
        return empty() ? 0 : heapArr[1];
    }
    void push(int value){
        heapArr[++size] = value;
        pushSwap(size);
    }
    void pop(){
        if(empty()) return;
        heapArr[1] = heapArr[size--];
        popSwap(1);
    }
    void show(){
        for (int i = 1; i < size + 1; i++){
            cout << heapArr[i] << ", ";
        }
        cout << endl;
    }
    void clear(){
        size = 0;
    }
};


int N;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
}

//왜 런타임 에러가 나지;;
void run1(){
    HEAP<int> myHeap(N);
    for (int i = 0; i < N; i++){
        int val;
        cin >> val;
        if(val == 0){
            cout << myHeap.top() << '\n';
            myHeap.pop();
        }else{
            myHeap.push(val);
        }
    }
}

// 우선순위큐를 이용한 방법
struct compare{
    bool operator()(int n1, int n2){
        int abs1 = abs(n1);
        int abs2 = abs(n2);
        if(abs1 == abs2)return n1 > n2;
        else return abs1 > abs2;
    }
};

void run2(){
    priority_queue<int, vector<int>, compare> pq;
    for (int i = 0; i < N; i++){
        int val;
        cin >> val;
        if(val == 0){
            if(pq.empty()) cout << "0\n";
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }else{
            pq.push(val);
        }
    }
}

int main(){
    init();
    // run1();
    run2();
}
