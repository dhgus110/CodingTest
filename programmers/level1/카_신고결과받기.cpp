#include <string>
#include <vector>
#include <set>
#include <map>


using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    //report 중복 삭제 및 빈 공간 삭제하는 방법이지만, unique는 붙어있는 요소들만 제거 가능하다..(정렬해서 사용해야 할 듯)
    //report.erase(unique(report.begin(), report.end()), report.end()); 

    set <string> s_report(report.begin(),report.end()); //report 중복 삭제

    map<string, vector<string>> m_user; //유저가 누구누구 신고했는지 <-그냥 vector쓰는게 좋았을듯...?
    map<string, int > m_report; //신고당한 유저의 신고당한 횟수


    for (auto s : s_report) {
        size_t pos = s.find(' ');
        string key = s.substr(0, pos);
        string value = s.substr(pos + 1);

        m_user[key].push_back(value);

        if (m_report.find(value) != m_report.end()) m_report[value]++;
        else m_report[value] = 1;

       // if (m.find(key) != m.end()) m[key].push_back(value); 
       //else m[key] = { value };

    }

    for (auto id : id_list) {
        int mail = 0;

        map<string, vector<string>>::iterator it = m_user.find(id); //m_user에서 유저를 찾아서
        if (it != m_user.end()) {
            for (auto ss : it->second) {  //m_user value인 vector<string> 탐색 후 (누구누구 신고했는지)
                map<string, int >::iterator it2 = m_report.find(ss); // m_report에 value가 k보다 크면 mail++
                if (it2 != m_report.end())
                    if(it2->second >k-1) mail++; 
            }
        }

        answer.push_back(mail);
    }


    return answer;
}
