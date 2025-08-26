//P11839 [USACO25FEB] The Best Lineup S
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7, INF = 1e9;

int n, t, s[N], ans[N], cnt;

struct str{
    int x, pos;
}a[N];

bool cmp(str a, str b){
    if(a.x != b.x) return a.x > b.x;
    return a.pos < b.pos;
}

int main(){

    cin >> t;

    while(t --){

        cin >> n;

        for(int i = 1; i <= n; i ++)
            cin >> s[i], a[i] = {s[i], i};

        sort(a + 1, a + n + 1, cmp);

        a[0] = {INF, 0}, s[0] = INF, cnt = 0;

        bool f = 0;

        int lst = 0, d;

        for(int i = 1; i <= n; i ++){
            int val = a[i].x, p = a[i].pos;
            if(lst > p){
                if(f || p < d) continue;
                f = 1;
            }
            ans[++ cnt] = val;
            d = lst;
            lst = p;
        }

        for(int i = 1; i <= cnt; i ++){
            cout << ans[i];
            if(i < cnt) cout << ' ';
        }
        cout << endl;

    }



    return 0;
}*/

//P11840 [USACO25FEB] Vocabulary Quiz S
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

vector <int> a[N];

int n, x, cnt;

int ans[N], fa[N], dep[N], sz[N];

void dfs(int x, int lst){

    dep[x] = !x ? 0 : dep[fa[x]] + 1;
    ans[x] = lst;
    sz[x] = a[x].size();

    if(a[x].empty()){
        cnt ++;
        return;
    }

    for(int to : a[x]){
        if(a[x].size() >= 2) dfs(to, to);
        else dfs(to, lst);
    }
    
}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        scanf("%d", &fa[i]);
        a[fa[i]].push_back(i);
    }

    dfs(0, 0);

    while(cnt --){

        scanf("%d", &x);

        if(!cnt){
            cout << 0 << endl;
            break;
        }

        int tmp = ans[x];
        sz[fa[tmp]] --;

        while(!sz[fa[tmp]]){
            tmp = ans[fa[tmp]];
            sz[fa[tmp]] --;
        }

        printf("%d\n", dep[tmp]);

    }

    return 0;
}*/

//P11841 [USACO25FEB] Transforming Pairs S
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

int a, b, x, y, t;

int cal(int a, int b, int x, int y){
    if(a > x || b > y) return -1;
    if(a == x && b == y) return 0;
    int res = 0;
    while(a < x || b < y){
        if(x > y){
            if(!y) return -1;
            int tmp = (x - a) / y;
            if(!tmp) return -1;
            x -= tmp * y;
            res += tmp;
        }
        else if(x < y){
            if(!x) return -1;
            int tmp = (y - b) / x;
            if(!tmp) return -1;
            y -= tmp * x;
            res += tmp;
        }
        else return -1;
    }
    if(a == x & b == y) return res;
    return -1;
}

signed main(){

    cin >> t;

    while(t --){
        cin >> a >> b >> x >> y;
        cout << cal(a, b, x, y) << endl;
    }


    return 0;
}*/

