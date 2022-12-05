#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp( string const& a, string const& b){
    return a.length() < b.length();
}

int len;
bool pos(string s){return s.length()==len;}

int backSearch(vector<string> const &words, string query)
{
    int result = 0;
    int wordLength = query.length();

    //한글자이면서 ? 일 때
    if( wordLength ==1){
        for(int i = 0 ; i <27 ; i++) //알파벳은 총 26자이다
        {
            if(words[i].length()==1)
                result++;
            else
                return result;
        }
    }
  

    string back = query.substr(query.rfind('?') + 1, wordLength); // ??awd에서 awd 만들기
    int gap = wordLength - back.length(); // 물음표 수  
    len = wordLength;
    int start = find_if(words.begin(),words.end(),pos)-words.begin(); //wordLenth 길이부터 시작하는 단어 찾기
    
    //전부 ? 일 때
    if (query[wordLength - 1] == '?')
    {
        while (1)
        {
            if (start > words.size() || words[start].length() > wordLength) //start가 word.size를 넘어가거나, 찾고있는 단어가 더 길어진다면
                break;
            result++;
        }
    }
    else //일부만 ? 일 때
    {
        while (1)
        {
            if (start > words.size() || words[start].length() > wordLength) //start가 word.size를 넘어가거나, 찾고있는 단어가 더 길어진다면
                break;
            if (words[start++].substr(gap, wordLength) == back)
                result++;
        }
    }
    return result;
}

int forwordSearch(vector<string> const &words, string query)
{
    int result = 0;
    int wordLength = query.length();

    string forword = query.substr(0, query.find('?', 0)); // awd??에서 awd 만들기
    int wildcardLength = wordLength - forword.length();
    string dummy = forword; // awd??의 마지막단어 awdzz 만들기
    for (int i = 0; i < wildcardLength; i++)
    {
        dummy += 'z';
    }

    int start, end;
    start = lower_bound(words.begin(), words.end(), forword) - words.begin();
    end = upper_bound(words.begin(), words.end(), dummy) - words.begin();

    for (int i = start; i < end; i++)
    {
        if (words[i].length() == wordLength)
            result++;
    }

    return result;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> wordsLengthSort = words;
    sort(words.begin(),words.end());
    sort(wordsLengthSort.begin(),wordsLengthSort.end(),cmp);
    
    for(auto q: queries){
        if(q[0]=='?')
            answer.push_back(backSearch(wordsLengthSort,q));
        else
            answer.push_back(forwordSearch(words,q));
        
    }

    return answer;
}