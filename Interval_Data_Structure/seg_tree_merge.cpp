//P3201 [HNOI2009] 梦幻布丁
/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)

const int N = 1e6 + 7;

struct node{
    int sum, L, R, lm, rm;
}T[N << 3];

int rt[N], tot;

int n, q, x, y, op, ans;

void push_up(int k, int l, int r){
    int ls = T[k].L, rs = T[k].R;
    T[k].sum = T[ls].sum + T[rs].sum;
    if(T[ls].rm == mid && T[rs].lm == mid + 1) T[k].sum --;
    if(!ls) T[k].lm = T[rs].lm, T[k].rm = T[rs].rm;
    else if(!rs) T[k].lm = T[ls].lm, T[k].rm = T[ls].rm;
    else T[k].lm = T[ls].lm, T[k].rm = T[rs].rm;
}

void upd(int &k, int l, int r, int x){
    if(!k) k = ++ tot;
    if(l == r){
        T[k].sum = 1;
        T[k].lm = T[k].rm = l;
        return;
    }
    if(mid >= x) upd(T[k].L, l, mid, x);
    else upd(T[k].R, mid + 1, r, x);
    push_up(k, l, r);
}

int merge(int x, int y, int l, int r){
    if(!x || !y) return x | y;
    T[x].L = merge(T[x].L, T[y].L, l, mid);
    T[x].R = merge(T[x].R, T[y].R, mid + 1, r);
    push_up(x, l, r);
    return x;
}

int main(){

    cin >> n >> q;

    for(int i = 1; i <= n; i ++){
        cin >> x;
        upd(rt[x], 1, n, i);
    }

    for(int i = 1; i < N; i ++)
        ans += T[rt[i]].sum;

    while(q --){

        cin >> op;

        if(op == 1){
            cin >> x >> y;
            if(x == y) continue;
            ans -= T[rt[x]].sum;
            ans -= T[rt[y]].sum;
            rt[y] = merge(rt[y], rt[x], 1, n);
            ans += T[rt[y]].sum;
            rt[x] = 0;
        }

        else cout << ans << endl;

    }

    return 0;
}*/
