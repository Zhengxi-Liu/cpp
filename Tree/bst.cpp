#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, INF = 1e9;
struct str{
    int val, l, r;
}a[N];
int root, tot, x, n;
int create(int val){
    a[++ tot].val = val;
    return tot;
}
void build(){
    create(-INF), create(INF);
    root = 1;
    a[1].r = 2;
}
void insert(int &p, int val){
    if(!p)
        p = create(val); //这里的 p 其实就是上一次的 a[p].l / r, 这里让它指向了 新的节点编号 (a[++ tot])
    else if(val < a[p].val)
        insert(a[p].l, val);
    else if(val > a[p].val)
        insert(a[p].r, val);
}
void dfs(int op, int x){
    if(a[x].val == INF){
        dfs(op, a[x].l); return;}
    if(a[x].val == -INF){
        dfs(op, a[x].r); return;}
    if(a[x].l) 
        dfs(op, a[x].l);
    if(op == 1)
        cout << a[x].val << ' ';
    if(a[x].r)
        dfs(op, a[x].r);
    if(op == 2)
        cout << a[x].val << ' ';
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> x;
        insert(root, x);
    }
    dfs(1, 1);
    cout << endl;
    dfs(2, 1);
    cout << endl;
    return 0;
}