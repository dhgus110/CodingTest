#include <string>
#include <vector>
#include <set>
#include <map>


using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    //report �ߺ� ���� �� �� ���� �����ϴ� ���������, unique�� �پ��ִ� ��ҵ鸸 ���� �����ϴ�..(�����ؼ� ����ؾ� �� ��)
    //report.erase(unique(report.begin(), report.end()), report.end()); 

    set <string> s_report(report.begin(),report.end()); //report �ߺ� ����

    map<string, vector<string>> m_user; //������ �������� �Ű��ߴ��� <-�׳� vector���°� ��������...?
    map<string, int > m_report; //�Ű���� ������ �Ű���� Ƚ��


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

        map<string, vector<string>>::iterator it = m_user.find(id); //m_user���� ������ ã�Ƽ�
        if (it != m_user.end()) {
            for (auto ss : it->second) {  //m_user value�� vector<string> Ž�� �� (�������� �Ű��ߴ���)
                map<string, int >::iterator it2 = m_report.find(ss); // m_report�� value�� k���� ũ�� mail++
                if (it2 != m_report.end())
                    if(it2->second >k-1) mail++; 
            }
        }

        answer.push_back(mail);
    }


    return answer;
}
