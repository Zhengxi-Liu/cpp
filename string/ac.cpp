//AC自动机唯一正确模版
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
int ch[N][26], cnt[N], ne[N];
int n, t, idx;
void prep(){
    memset(ch, 0, sizeof(ch));
    memset(cnt, 0, sizeof(cnt));
    memset(ne, 0, sizeof(ne));
    idx = 0;
}
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
void init_next(){
    queue <int> q;
    for(int i = 0;i < 26;i ++){
        if(ch[0][i])
            q.push(ch[0][i]);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i < 26;i ++){
            int p = ch[now][i];
            if(ch[now][i]){
                ne[p] = ch[ne[now]][i];
                q.push(p);
            }
            else 
                ch[now][i] = ch[ne[now]][i];
        }
    }
}
char s[N];
int main(){
    while(cin >> n){
        if(!n)
            break;
        prep();
        while(n --){
            scanf("%s", &s);
            insert(s);
        }
        init_next();
        scanf("%s", &s);
        int ans = 0;
        for(int i = 0,j = 0;s[i];i ++){
            int x = s[i] - 'a';
            while(j && !ch[j][x])
                j = ne[j];
            if(ch[j][x])
                j = ch[j][x];
            int p = j;
            while(p){
                ans += cnt[p];
                p = ne[p];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int ch[N][26], ne[N], cnt[N], n, t, idx, ans = 0;
void init(){
    memset(ch, 0, sizeof(ch));
    memset(ne, 0, sizeof(ne));
    memset(cnt, 0, sizeof(cnt));
    idx = 0;
    ans = 0;
}
void insert(string s){
    int len = s.size(), p = 0;
    s = " " + s;
    for(int i = 1;i <= len;i ++){
        int x = s[i] - 'a';
        if(!ch[p][x])
            ch[p][x] = ++ idx;
        p = ch[p][x];
    }
    cnt[p] ++;
}
void init_next(){
    queue <int> q;
    for(int i = 0;i < 26;i ++){
        if(ch[0][i])
            q.push(ch[0][i]);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i < 26;i ++){
            if(ch[now][i]){
                ne[ch[now][i]] = ch[ne[now]][i];
                q.push(ch[now][i]);
            }
            else
                ch[now][i] = ch[ne[now]][i];
        }
    }
}
#define FASTIO cin.tie(nullptr), cout.tie(nullptr);
int main(){
    FASTIO
    cin >> t;
    while(t --){
        init();
        cin >> n;
        string s;
        for(int i = 1;i <= n;i ++){
            cin >> s;
            insert(s);
        }
        init_next();
        cin >> s;
        n = s.size();
        for(int i = 0, j = 0;i < n;i ++){
            int x = s[i] - 'a';
            while(j && !ch[j][x])
                j = ne[j];
            if(ch[j][x])
                j = ch[j][x];
            int p = j;
            while(p){
                ans += cnt[p];
                cnt[p] = 0;
                p = ne[p];
            }
        }
        cout << ans << endl;
    }

    return 0;
}