/*
ID: gsliu.t1
LANG: C++11
TASK: gift1
*/
#include<map>
#include<string>
#include<fstream>
#include<iostream>
#include<unordered_map>
using namespace std;
map <string, int> mp;
const int N = 10 + 7;
string s, a[N], t;
int n, t1, t2, temp;
int main(){
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    fin >> n;
    for(int i = 1;i <= n;i ++){
        fin >> s;
        a[i] = s;
        mp[s];
    }
    for(int i = 1;i <= n;i ++){
        fin >> s >> t1 >> t2;
        if(! t2)
            continue ;
        mp[s] = mp[s] + t1 % t2 - t1;
        temp = t1 / t2;
        //cout << "//" << temp << "//" << endl;
        for(int j = 1;j <= t2;j ++){
            fin >> t;
            mp[t] += temp;
        }
    }
    for(int i = 1;i <= n;i ++)
        fout << a[i] << ' ' << mp[a[i]] << endl;
    return 0;
}
