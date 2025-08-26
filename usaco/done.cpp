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

