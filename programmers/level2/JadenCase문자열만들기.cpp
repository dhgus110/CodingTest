#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag =false;
    char gap = ('A' - 'a');
    
    if( 'a'<= s[0] && s[0] <='z')
        answer += s[0] + gap;
    else
        answer += s[0];
    
    for(size_t i = 1 ; i < s.size() ; ++i )
    {
        char c = s[i];
        
        if( !flag && 'A'<= c && c <='Z')
            c = c - gap;
        
        if( flag && 'a'<= c && c <='z')
        {
            flag = false;
            c = c + gap ;
        }
        
        if(flag && ('a'> c || (c > 'z' && 'A' > c) || c >'Z'))
            flag = false;
        
        if(c == ' ')
            flag = true;
        
        answer += c;
    }
    
    return answer;
}