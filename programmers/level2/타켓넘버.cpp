    #include <string>
    #include <vector>
    #include <queue>
    #include <stack>
    #include <iostream>

    using namespace std;

    //DFS 풀이 
    int DFS(const vector<int> &n ,const int target){
        int answer =0;
        stack<pair<int,int>> s;
        s.push({0, n[0]});
        s.push({0, -n[0]});
        while(!s.empty()){
            int index = s.top().first;
            int cal = s.top().second;
            s.pop();

            if (index + 1 == n.size() && cal == target) answer++;
            if( index + 1 < n.size()){
                s.push(make_pair(index + 1, cal + n[index + 1]));
                s.push(make_pair(index + 1, cal - n[index + 1]));
            }   
        }
        return answer;
    }

    //BFS 풀이
    int solution(vector<int> numbers, int target) {
        int answer = 0;
        queue<pair<int,int>> q;
        q.push({0,numbers[0]});
        q.push({0,-numbers[0]});

        while(!q.empty()){
            int index = q.front().first;
            int cal = q.front().second;
            q.pop();
            if(index + 1 == numbers.size()&&cal == target) answer++;
            
            if (index + 1< numbers.size())
            {
                q.push(make_pair(index + 1, cal + numbers[index + 1]));
                q.push(make_pair(index + 1, cal - numbers[index + 1]));
            }
            
        }

        return answer;
        // return DFS(numbers,target);
    }


// int _count = 0;
// int _target;
// void dfs(int sum,int depth, vector<int>& v){
//     if(depth >= v.size()){
//         if(sum == _target) _count++;

//         return;
//     }

//     dfs(sum + v[depth], depth+1, v);
//     dfs(sum - v[depth], depth+1, v);
// }

// int solution(vector<int> numbers, int target) {
//     int answer = 0;
//     _target = target;
//     dfs(0,0,numbers);
//     answer=_count;
//     cout<<endl<<answer;
//     return answer;
// }

// int main(){
//     solution({1, 1, 1, 1, 1},3);
// }