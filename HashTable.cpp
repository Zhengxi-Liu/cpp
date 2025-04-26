/*#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long Ull;
const int b = 131, N = 1e6 + 7;
Ull dis[N], p[N];
int n, q, l1, l2, r1, r2;
string s;
int main(){
    cin >> s;
    n = s.size();
    s = " " + s;
    p[0] = 1;
    //cout << s << ' ';
    for(int i = 1;i <= n;i ++){
        p[i] = p[i - 1] * b;
        dis[i] = dis[i - 1] * b + (int(s[i]) - int('a') + 1);
    }
    scanf("%d", &q);
    while(q --){
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(dis[r1] - dis[l1 - 1] * p[r1 - l1 + 1] == dis[r2] - dis[l2 - 1] * p[r2 - l2 + 1])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 131, N = 4e5 + 7;
ULL p[N], dis[N];
int n;
string s;
bool is_Suffix_Prefix(int l, int r){
    int t1 = dis[l], t2 = dis[n] - dis[r - 1] * p[n - r + 1];
    if(t1 == t2)
        return true;
    return false;
}
int main(){
    p[0] = 1;
    while(cin >> s){
        n = s.size();
        s = " " + s;
        for(int i = 1;i <= n;i ++){
            p[i] = p[i - 1] * P;
            dis[i] = dis[i - 1] * P + (s[i] - 'a' + 1);
        }
        for(int i = 1;i <= n;i ++){
            if(is_Suffix_Prefix(i, n - i + 1))
                printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int hdr[N], nex[N], a[N], n, idx;
char s[10], t[N];
int moding()
void insert(int x){
    int v = (x % N + N) % N;
    idx ++;
    a[idx] = x;
    nex[idx] = hdr[v];
    hdr[v] = idx;
}
bool query(int x){
    int v = (x % N + N) % N;
    for(int i = hdr[v];i != 0;i = nex[i])
        if(a[i] == x)
            return true;
    return false;
}
int main(){
    cin >> n;
    while(n --){
        scanf("%s%d", s, t);
        if(s[0] == 'a')
            insert(t);
        else {
            if(query(t))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N = 3e4 + 7, MOD = 1e6 + 3, P = 131;
ULL a[N], nex[N], h[MOD];
int n, idx = 0;
string s, t;
ULL gethash(string t){
    ULL p = 0;
    for(int i = 1;i < t.size();i ++)
        p = p * P + t[i];
    //cout << p << ' ';
    return p;
}
void insert(ULL x){
    int v = x % MOD;
    idx ++;
    a[idx] = x;
    nex[idx] = h[v];
    h[v] = idx;
}
bool find(ULL x){
    int v = x % MOD;
    for(int i = h[v];i;i = nex[i])
        if(a[i] == x)
            return true;
    return false;
}
int main(){
    cin >> n;
    while(n --){
        cin >> s;
        getline(cin, t);
        if(s == "add"){
            insert(gethash(t));
        }
        else{
            if(find(gethash(t)))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    //for(int i = 1;i <= 1e6;i ++)
      //  if(h[i])
        //    cout << i << ' ';
    //cout << endl << idx << ' ' << gethash("Inside C#") << ' ' << gethash("Effective Java");
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], b[N], cnt[N], n;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int len = unique(b + 1, b + n + 1) - b - 1;
    for(int i = 1;i <= n;i ++){
        int idx = lower_bound(b + 1, b + len + 1, a[i]) - b;
        cnt[idx] ++;
    }
    for(int i = 1;i <= len;i ++)
        cout << b[i] << ' ' << cnt[i] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int p[N], x[N], l[N], r[N], n, m;
int a[N], c[N], idx = 0;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i ++){
        scanf("%d%d", &p[i], &x[i]);
        a[++ idx] = p[i];
    }
    for(int i = 1;i <= m;i ++){
        scanf("%d%d", &l[i], &r[i]);
        a[++ idx] = l[i];
        a[++ idx] = r[i];
    }
    sort(a + 1, a + idx + 1);
    idx = unique(a + 1, a + idx + 1) - a - 1;
    int len = unique(a + 1, a + n + 1) - a - 1;
    for(int i = 1;i <= n;i ++){
        p[i] = lower_bound(a + 1, a + idx + 1, p[i]) - a;
        c[p[i]] += x[i];
    }
    for(int i = 1;i <= idx;i ++)
        c[i] += c[i - 1];
    for(int i = 1;i <= m;i ++){
        l[i] = lower_bound(a + 1, a + idx + 1, l[i]) - a;
        r[i] = lower_bound(a + 1, a + idx + 1, r[i]) - a;
        printf("%d\n", c[r[i]] - c[l[i] - 1]);
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int x[N], y[N], e[N], n, t;
int a[N * 2], dsu[N * 2];
int find(int x){
    if(dsu[x] == x)
        return x;
    return dsu[x] = find(dsu[x]);
}
void merge(int x, int y){
    int t1 = find(x);
    int t2 = find(y);
    dsu[t1] = t2;
}
int main(){
    cin >> t;
    while(t --){
        cin >> n;
        int k = 0;
        for(int i = 1;i <= n * 2;i ++)
            dsu[i] = i;
        for(int i = 1;i <= n;i ++){
            cin >> x[i] >> y[i] >> e[i];
            a[++ k] = x[i];
            a[++ k] = y[i];
        }
        sort(a + 1, a + k + 1);
        k = unique(a + 1, a + k + 1) - a - 1;
        for(int i = 1;i <= n;i ++){
            x[i] = lower_bound(a + 1, a + k + 1, x[i]) - a;
            y[i] = lower_bound(a + 1, a + k + 1, y[i]) - a;
            if(e[i])
                merge(x[i], y[i]);
        }
        int flag = 0;
        for(int i = 1;i <= n;i ++)
            if(!e[i] && find(dsu[x[i]]) == find(dsu[y[i]])){
                cout << "NO" << endl;
                flag ++;
                break;
            }
        if(!flag)
            cout << "YES" << endl;
    }
}*/
