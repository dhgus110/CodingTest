#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> hash ;
    sort(phone_book.begin(),phone_book.end(),greater<>());
    for(auto number: phone_book){
        string s = "";

        if(hash.find(number)!=hash.end()) return false;
        for( auto n : number ){
            s+=n;
            hash.insert(s);
        }
    }
    return true;

    // bool answer = true;
    // string str ="";
    // unordered_map< string,int> hash;

    // for(string s : phone_book){
    //     str ="";
    //     s.erase(remove(s.begin(), s.end(), ' '), s.end());
    //     for(int i =0;i<s.size();i++){
    //         str+=s[i];
    //         ++hash[str];
    //     }
    // }
    // for(const auto& s : phone_book){
    //     if(hash[s]>1)
    //     return false;
    // }

    // return answer;
}