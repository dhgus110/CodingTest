#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class HEAP {
    int size;
    T *heapArr;
private:
    void pushSwap(int n){
        if( n ==1) return; //최상위 노드
        int parent = n /2 ;
        if(heapArr[parent] <heapArr[n]){ //부모노드보다 자식노드가 크면
            T tmp =heapArr[parent];
            heapArr[parent] = heapArr[n];
            heapArr[n] = tmp;

            pushSwap(parent);
        }
    }
    void popSwap(int n){
        int leftChild = (n * 2 <= size ? n * 2 : -1);
        int rightChild = (n * 2 + 1 <= size ? n * 2 + 1 : -1);
        int child; 
        if(leftChild == -1 && rightChild == -1 ) child = -1;  //자식이 둘 다 없을 때
        else if (leftChild != -1 && rightChild == -1 ) child = leftChild ; //왼쪽 자식만 있을 때 (오른쪽만 있는 경우는 당연히 없다)
        else child = (heapArr[leftChild]> heapArr[rightChild] ? leftChild : rightChild) ; //자식이 둘 다 있을 때

        if(child == -1) return;
        if(heapArr[child] > heapArr[n]){ //자식이 더 크다면
            T tmp =heapArr[child];
            heapArr[child] = heapArr[n];
            heapArr[n] = tmp;

            popSwap(child);
        }
    }
public:
    HEAP(int n){
        size=0;
        heapArr =new int[n+1];
    }
    ~HEAP(){
        delete[] heapArr;
    }
    bool empty(){
        if(size == 0 ) return true;
        return false;
    }
    int amount(){
        return size;
    }
    T top(){
        return  empty() ? -1 : heapArr[1];
    }
    void push(int value){
        heapArr[++size]=value;
        pushSwap(size);
    }
    void pop(){
        if (empty())  // !size ==0 이면 pop할 것이 없으니 return 
            return;
 
        heapArr[1] = heapArr[size--];
        popSwap(1);
    }
    void show(){
        for(int i =1 ; i< size+1 ; i++){
            cout<<heapArr[i]<<", ";
        }
        cout<<endl;
    }
    void clear(){
        size =0;
    }
};

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    HEAP<int> maxh(operations.size()) ;
    HEAP<int> minh(operations.size()) ;
    int i =0;
    for(string s : operations){
        if(s[0]=='I'){
            maxh.push(stoi(s.substr(2)));
            minh.push(stoi(s.substr(2))*-1);
            i++;
        }
        else if(s=="D 1"&& i >0){
            maxh.pop();
            i--;
        }
        else if(s=="D -1"&& i >0){
            minh.pop();
            i--;
        }
        if( i ==0){
            maxh.clear();
            minh.clear();
        }
        // h.show();
    }
    if(i<=0)
        answer = {0, 0};
    else
        answer = { maxh.top(), minh.top()*-1};
    // cout<<answer[0]<<" " <<answer[1];
    return answer;
}