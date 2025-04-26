//BST 模版, Treap 基础
/*#include<bits/stdc++.h>
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
}*/

//Treap
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, INF = 1e9;
struct node{
    /*
    val: BST所维护的权值
    rd: 在堆中的优先级
    siz: 以该节点为根的子树大小
    cnt: 节点值出现的次数
    */
    int val, rd, l, r, siz, cnt;
}a[N];

int n, tot, root, op, x;

//利用子节点更新父节点
void push_up(int p){
    a[p].siz = a[a[p].l].siz + a[a[p].r].siz + a[p].cnt;
}

//新建节点
int create(int val){
    a[++ tot].val = val;
    a[tot].rd = rand();
    a[tot].siz = a[tot].cnt = 1;
    return tot;
}

//右旋
void zig(int &p){
    int q = a[p].l;
    a[p].l = a[q].r;
    a[q].r = p, p = q;
    push_up(a[p].r);
    push_up(p);
}

//左旋
void zag(int &p){
    int q = a[p].r;
    a[p].r = a[q].l;
    a[q].l = p, p = q;
    push_up(a[p].l);
    push_up(p);
}

//建树
void build(){
    create(-INF), create(INF);
    root = 1, a[1].r = 2;
    push_up(root);
    if(a[2].rd > a[1].rd)
        zag(root);
}

//插入
void insert(int &p, int x){
    if(!p) p = create(x);
    else if(x == a[p].val) a[p].cnt ++;
    else if(x < a[p].val){
        insert(a[p].l, x);
        if(a[a[p].l].rd > a[p].rd) zig(p);
    }
    else if(x > a[p].val){
        insert(a[p].r, x);
        if(a[a[p].r].rd > a[p].rd) zag(p);
    }
    push_up(p);
}

//删除
void remove(int &p, int x){
    if(!p) return;
    if(x == a[p].val){
        if(a[p].cnt > 1) a[p].cnt --;
        else {
            if(a[p].l || a[p].r){
                if(!a[p].r || a[a[p].l].rd > a[a[p].r].rd){
                    zig(p);
                    remove(a[p].r, x);
                }
                else {
                    zag(p);
                    remove(a[p].l, x);
                }
            }
            else
                p = 0;
        }
    }
    else if(x < a[p].val)
        remove(a[p].l, x);
    else if(x > a[p].val)
        remove(a[p].r, x);
    push_up(p);
}

//找排名
int getrank(int p, int x){
    if(!p) return 0;
    if(x == a[p].val) return a[a[p].l].siz + 1;
    else if(x < a[p].val) return getrank(a[p].l, x);
    else return a[a[p].l].siz + a[p].cnt + getrank(a[p].r, x);
}

//找排名为 x 的节点的值
int getnum(int p, int rank){
    if(!p) return INF;
    if(rank <= a[a[p].l].siz) return getnum(a[p].l, rank);
    else if(rank <= a[a[p].l].siz + a[p].cnt) return a[p].val;
    else return getnum(a[p].r, rank - a[a[p].l].siz - a[p].cnt);
}

//找比 x 小的最大节点值
int prev(int p, int x){
    if(!p) return -INF;
    if(x <= a[p].val) return prev(a[p].l, x);
    else return max(a[p].val, prev(a[p].r, x));
}

//找比 x 大的最小节点值
int ne(int p, int x){
    if(!p) return INF;
    if(x >= a[p].val) return ne(a[p].r, x);
    else return min(a[p].val, ne(a[p].l, x));
}

int main(){
    cin >> n;
    build();
    while(n --){
        cin >> op >> x;
        int ans = INF - 1;
        if(op == 1) insert(root, x);
        if(op == 2) remove(root, x);
        if(op == 3) ans = getrank(root, x) - 1;
        if(op == 4) ans = getnum(root, x + 1);
        if(op == 5) ans = prev(root, x);
        if(op == 6) ans = ne(root, x);
        if(op >= 3)
            cout << ans << endl;
    }
    return 0;
}
