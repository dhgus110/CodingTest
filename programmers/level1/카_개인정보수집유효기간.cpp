#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string calculateDate(string date, int expirationDate) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    string day = date.substr(8, 2);

    int addYear = expirationDate / 12+ year;
    int addMonth = expirationDate % 12 + month;
    if (addMonth > 12) {
        addYear += 1;
        addMonth -= 12;
    }
    string sMonth = addMonth >= 10 ? to_string(addMonth) : '0' + to_string(addMonth);
    string expiredDate = to_string(addYear) + sMonth  + day;
    return expiredDate;

}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> mTerms;
    //문자열에서 특정 문자만 제거
    today.erase(remove(today.begin(), today.end(), '.'), today.end());
    cout << today << endl;
    for (auto t : terms) {
        char  term= t[0];
        int  month = stoi(t.substr(2));
        mTerms.insert({ term,month });
    }

;    for (int i = 0; i < privacies.size();i++) {
        char  term = privacies[i][11];
        string date = privacies[i].substr(0, 11);
        string expiredDate = calculateDate(date, mTerms[term]);
        cout << expiredDate << endl;
        if (today >= expiredDate) answer.push_back(i + 1);
    }
    return answer;
}