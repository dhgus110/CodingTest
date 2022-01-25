#include <iostream> 
#include <string>
#include <regex>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

int cArr[7];

vector<int> comb;
void combination(int n, int r, int k=1)
{
    
    if (comb.size() == r)
    {
        for (int i = 0; i < comb.size(); i++)
            cout << comb[i] << " ";
        cout << endl;
    }
    else if (k == n + 1)
    {
    }
    else
    {
        comb.push_back(k);
        combination(n, r, k + 1);
        comb.pop_back();
        combination(n, r, k + 1);
    }
}
int main(){
    combination(3,2,1);
    for(auto c :cArr){
        cout<<c<<" ";
    }
    cout<<endl<<endl;

    int aa= 0;
    int a= 2147483647;
    // cout<< 1/2;

    string s= "";
    s+='c';
    cout<<s<<" "<<s.size()<<endl;

    if(isdigit('2')) cout<<"굿"<<endl;
    else cout<<"ㄴㄴ"<<endl;

    if(0) cout<<"0"<<endl;
    if(a) cout<<"2^32 -1 "<<endl;

    string sreg = "2~D3~T#10~S*";
    regex e("([0-6]+)(\\~)(S|D|T)(\\*|#)*");

    sregex_iterator it(sreg.begin(), sreg.end(), e);
    sregex_iterator end;

    string sss ="";

    while (it != end)
    {
        smatch sm = *it;
        for (int i = 0; i < sm.size(); i++)
        {
            // cout << "i: " << i << " .." << sm[i] << "  type : "<<typeid(sm[i]).name() <<endl;
            sss+=sm[i];
        }
        it++;
    }
    cout<<sss<<endl;

    // string d ="N~F=2N~F=4";
    // regex re("(A|C|F|J|M|N|R|T)(\\~)(A|C|F|J|M|N|R|T)(\\=)([0-6])*");

    // sregex_iterator it2(d.begin(), d.end(), re);
    // sregex_iterator end2;

    // while (it2 != end2)
    // {
    //     smatch sm = *it2;
    //     for (int i = 0; i < sm.size(); i++)
    //     {
    //         cout << "i: " << i << " .." << sm[i] << endl;
    //     }
    //     it2++;
    // }

    int fato =tgamma(3);
    cout<<fato<<endl;

      vector <int> playernum(8);
    vector <char> player = {'A','C','F','J','M','N','R','T'};
    for(int i = 0; i <8 ; i++){
        playernum[i]=i;
    }
    for(auto p1 : playernum){
        cout<<p1<<" ";
    }
    cout<<endl;
    for(auto p2 : player){
        cout<<p2<<" ";
    }
    cout<<endl;
    
    char cc= '4';
    int i3 =4;
    int i4 = i3-cc;  //false;
    int ctoi =cc-'0';  //true
    cout<< int(cc-'0')<<endl;

    cout<<"~~~~~~~~~~~~~~~~~~"<<endl;
    string nexts = "123";
    do
    {
        cout<<nexts<<endl;
    } while (next_permutation(nexts.begin(),nexts.end()));

    string sortS = "ATRBa";
    sort(sortS.begin(),sortS.end());
    cout<<sortS<<", "<<sortS.size()<<endl;

    map <int, vector<string>> testMap;
    for(int i = 0; i <5; i++){
        vector<string> tmp ={"ss","as"};
        testMap[i] = tmp;
    }
    for(auto m : testMap){
        cout<< m.first<< " : " <<m.second[1]<<endl;
    }
    char cha  = 'a'+1;
    cout<< (int)('a'-'a')<<endl;
    if(0) cout<<"00000"<<endl;
    else cout<<"111"<<endl;

    vector<vector<int>> vvi(5);
    vvi.push_back({2,2});
    vvi.push_back({3,3,3});
    cout<<vvi.size()<<endl;
    cout<<vvi[5].size()<<endl;
    for(int asi = 0 ; asi <vvi.size() ; asi++){
        for(int asj = 0 ; asj < vvi[asi].size(); asj++){
            cout<<vvi[asi][asj]<<" ";
        }
    }
    cout<<"-----------------------"<<endl;
    vector<set<int>> gr(2);
    set<int> sett;
    sett.insert(4);
    gr.push_back(sett);
    gr[1].insert(3);
    gr[1].insert(2);

    for(auto g1 : gr){
        for(auto g2 : g1){
            cout<<g2<<" ";
        }cout<<endl;
    }
   
}
