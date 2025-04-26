/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, m, cnt[N], ch[N][26], idx = 0;
char s[N];
void insert(char s[]){
    int p = 0;
    for(int i = 0;s[i];i ++){
        int x = s[i] - 'a';
        if(!ch[p][x])
            ch[p][x] = ++idx;
        p = ch[p][x];
    }
    cnt[p] ++;
}
int query(char s[]){
    int p = 0;
    for(int i = 0;s[i];i ++){
        int x = s[i] - 'a';
        if(!ch[p][x])
            return 0;
        p = ch[p][x];
    }
    return cnt[p];
}
int main(){
    scanf("%d", &n);
    while(n --){
        scanf("%s", &s);
        insert(s);
    }
    scanf("%d", &m);
    while(m --){
        scanf("%s", &s);
        printf("%d\n", query(s));
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int cnt[N], ch[N][10], n, t, idx;
string s;
bool insert(string s){
    bool f1 = false, f2 = false;
    int p = 0, vis = 0;
    for(int i = 0;i < s.size();i ++){
        int x = s[i] - '0';
        if(!ch[p][x]){
            ch[p][x] = ++idx;
            f1 = true;
        }
        p = ch[p][x];
        if(cnt[p] != 0)
            f2 = true;
    }
    cnt[p] ++;
    return (f1 == false) || f2;
}
void prep(){
    cin >> n;
    memset(ch, 0, sizeof(ch));
    memset(cnt, 0, sizeof(cnt));
    idx = 0;
}
int main(){
    cin.tie();
    cin >> t;
    while(t --){
        prep();
        bool ans = false;
        for(int i = 1;i <= n;i ++){
            cin >> s;
            if(insert(s))
                ans = true;
        }
        if(ans)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
int ch[N][26], cnt[N], n;
int idx = 0, ans = 0;
string s;
void insert(string s){
    int p = 0, pre = 0;
    for(int i = 0;i < s.size();i ++){
        int x = s[i] - 'a';
        if(!ch[p][x])
            ch[p][x] = ++ idx;
        pre += cnt[p];
        p = ch[p][x];
    }
    cnt[p] ++;
    ans = max(ans, pre + cnt[p]);
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> s;
        insert(s);
    }
    cout << ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int ch[N][26], cnt[N];
int n, m, idx = 0, vis[N];
void insert(string s){
    int p = 0;
    for(int i = 0;i < s.size();i ++){
        int x = s[i] - 'a';
        if(!ch[p][x])
            ch[p][x] = ++ idx;
        p = ch[p][x];
    }
    cnt[p] ++;
}
void find(string s){
    int p = 0;
    for(int i = 0;i < s.size();i ++){
        int x = s[i] - 'a';
        if(!ch[p][x]){
            cout << "WRONG" << endl;
            return;
        }
        p = ch[p][x];
    }
    if(cnt[p]){
        if(!vis[p]){
            cout << "OK" << endl;
            vis[p] = 1;
        }
        else 
            cout << "REPEAT" << endl;
    }
    else 
        cout << "WRONG" << endl;
}
string s;
int main(){
    cin >> n;
    while(n --){
        cin >> s;
        insert(s);
    }
    cin >> m;
    while(m --){
        cin >> s;
        find(s);
    }
    return 0;
}*/
//trie
#include<bits/stdc++.h>
using namespace std;
string d_to_b(int x){
    string ret = "";
    while(x > 0){
        ret += char(x % 2);
        x /= 2;
    }
    ret = reverse(ret.begin(), ret.end());
    return ret;
}
int b_to_d(string s){
    int ret = 0;
    for(int i = 0;i < s.size();i ++){
        ret = ret * 2 + (s[i] - '0');
    }
    return ret;
}
int main(){

    return 0;
}
