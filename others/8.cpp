/*
ID: gsliu.t1
LANG: C++11
TASK: namenum
*/
#include<map>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
const int N = 1e3 + 7;
string s, t, ans[N];
map <string, int> mp;
struct str{
    char a, b, c;
}arr[N];
int idx = 0;
void dfs(int step, string ss){
    if(step == s.size()){
        if(mp.count(ss))
            ans[++ idx] = ss;
        return ;
    }
    int temp = int(s[step]) - int('0');
    dfs(step + 1, ss + arr[temp].a);
    dfs(step + 1, ss + arr[temp].b);
    dfs(step + 1, ss + arr[temp].c);
}
int main(){
    ifstream fin("namenum.in");
    ifstream din("dict.txt");
    ofstream fout("namenum.out");
    fin >> s;
    while(din >> t)
        mp[t] = 1;
    int temp = 0;
    for(int i = 2;i <= 9;i ++){
        char c = char((i - 2) * 3 + 'A' + temp);
        arr[i].a = c;
        if(c == 'P'){
            temp = 1;
            c = 'Q';
        }
        arr[i].b = char(int(c) + 1);
        arr[i].c = char(int(c) + 2);
    }
    dfs(0, "");
    if(!idx)
        fout << "NONE" << endl;
    else
        for(int i = 1;i <= idx;i ++)
            fout << ans[i] << endl;
    return 0;
}