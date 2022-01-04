#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string str ="";
    unordered_map< string,int> hash;

    for(string s : phone_book){
        str ="";
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        for(int i =0;i<s.size();i++){
            str+=s[i];
            ++hash[str];
        }
    }
    for(const auto& s : phone_book){
        if(hash[s]>1)
        return false;
    }

    return answer;
}