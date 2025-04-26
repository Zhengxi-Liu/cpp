#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int sum[N * 4], maxl[N * 4], maxr[N * 4], maxn[N * 4], a[N];
int n, m, k, a, b;
void push_up(int k){
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
    maxl[k] = max(maxl[k * 2], sum[k * 2] + maxl[k * 2 + 1]);
    maxr[k] = max(maxr[k * 2 + 1], sum[k * 2 + 1], maxr[k * 2]);
    maxn[k] = max({maxn[k * 2], maxn[k * 2 + 1], maxr[k * 2] + maxl[k * 2 + 1]});
}
void build(int k, int l, int r){
    if(l == r){
        maxl[k] = maxr[k] = sum[k] = maxn[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    if(l <= mid)
        build(k * 2, l, mid);
    if(r >= mid + 1)
        build(k * 2 + 1, mid + 1, r);
    push_up(k);
}
void update(int k, int l, int r, int x, int y){
    if(l == x && y == x){
        sum[k] = maxr[k] = maxr[k] = maxn[k] = y;
        return;
    }
    int mid = (l + r) / 2;
    if(x <= mid)
        build(k * 2, l, mid, x, y);
    else
        update(k * 2 + 1, mid + 1, r, x, y);
    push_up(k);
}
struct node{
    int sum, maxl, maxr, maxn;
};
node query(int l, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return ;
    int mid = (l + r) / 2, res = 0;
    if(x <= mid)

}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    build(1, 1, n);
    while(m --){
        cin >> k >> a >> b;
        if(k == 1){
            update(1, 1, n, a, b);
        }
        else{
            cout << query(1, 1, n, min(a, b), max(a, b)) << endl;
        }
    }
    return 0;
}