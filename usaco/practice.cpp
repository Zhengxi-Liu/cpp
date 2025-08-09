#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct str{
    int l, r, t;
}a[N];

bool cmp(str a, str b){
    return a.l < b.l;
}

int t, n, m;

int p[N];

typedef pair <int, int> PI;

multiset <PI> idx, val;

// idx: <right range, trees left>
// val: <trees left, right range>

int main(){

    cin >> t;

    while(t --){

        cin >> n >> m;

        for(int i = 1; i <= n; i ++)
            cin >> p[i];

        for(int i = 1; i <= m; i ++)
            cin >> a[i].l >> a[i].r >> a[i].t;

        int L = 1, R = 0, now = 0, ans = 0;

        idx.clear();
        val.clear();
        idx.insert({2e9, 0});

        for(int i = 1; i <= n; i ++){
            while(a[R + 1].l <= p[i] && R < n){
                R ++;
                idx.insert({a[R].r, a[R].t + now});
                val.insert({a[R].t + now, a[R].r});
            }
            PI tmp = *idx.begin();
            while(tmp.first < p[i]){
                idx.erase(idx.find({tmp.first, tmp.second}));
                val.erase(val.find({tmp.second, tmp.first}));
                tmp = *idx.begin();
            }
            if(val.empty()) ans ++;
            else {
                PI tmp = *val.begin();
                if(tmp.first - now > 0) now ++, ans ++;
            }
        }

    }


    return 0;
}