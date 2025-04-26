#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
vector <int> ch[N];
int n, idx = 1, cnt, x, t;
int size[N], a[N], p[N], s[N], c[N], f[N];
void build(int x, int v){
    ch[x].push_back(++ idx);
    size[idx] = size[x] + 1;
    p[v] = idx;
    f[idx] = x;
}
void dfs(int x, int last){
    s[x] = last;
    c[x] = ch[x].size();
    for(int i = 0;i < ch[x].size();i ++){
        if(ch[x].size() > 1)
            dfs(ch[x][i], x);
        else
            dfs(ch[x][i], last);
    }
}
int find(int x){
    if(x == 1)
        return 1;
    //cout << x << ' ' << c[x] << "// ";
    if(c[x] >= 2)
        return size[x];
    return find(s[x]);
}
int main(){
    scanf("%d", &n);
    p[0] = 1;
    for(int i = 1;i <= n;i ++){
        scanf("%d", &a[i]);
        build(p[a[i]], i);
    }
    dfs(1, 1);
    for(int i = 1;i <= idx;i ++){
        //cout << ch[i].size() << ' ' << s[i] << ' ' << c[i] << endl;
        //cout << size[i] << ' ' << c[i] << endl;
        if(!ch[i].size())
            cnt ++;
    }
    t = cnt;
    for(int i = 1;i <= cnt;i ++){
        cin >> x;
        if(i == cnt){
            cout << '0' << endl;
            break;
        }
        // for(int i = 1;i <= n;i ++) 
        //     cout << c[i] << ' ';
        // cout << endl;
        int add = 0;
        if(c[s[s[x]]] >= 2)
            add = 1;
        cout << find(s[p[x]]) + add << endl;
        c[s[p[x]]] --;
    }
    return 0;
}