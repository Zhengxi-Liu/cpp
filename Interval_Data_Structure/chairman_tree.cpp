//https://www.luogu.com.cn/problem/P3834
//主席树模版
/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)

const int N = 2e5 + 7;

int sum[N << 5], L[N << 5], R[N << 5], T[N]; //sum, left node, right node, root node for i'th tree

int a[N], b[N];

int n, q, l, r, x, cnt, k, m;

inline int build(int l, int r){
    ++ cnt;
    int rt = cnt;
    sum[rt] = 0;
    if(l < r){
        L[rt] = build(l, mid);
        R[rt] = build(mid + 1, r);
    }
    return rt;
}

inline int update(int pre, int l, int r, int x){ // pre = 上一个 tree 的对应节点, l r 为范围, x 为新加入的值
    ++ cnt;
    int rt = cnt;
    L[rt] = L[pre], R[rt] = R[pre], sum[rt] = sum[pre] + 1;
    if(l < r){
        if(x <= mid)
            L[rt] = update(L[pre], l, mid, x); //如果 x 小于 中值, 则向左找, 并且 L[cnt] 指向新的节点
        else
            R[rt] = update(R[pre], mid + 1, r, x); //如果 x 大于 中值, 则向右找, 并且 R[cnt] 指向新的节点
    }
    return rt;
}

inline int query(int u, int v, int l, int r, int k){
    if(l == r)
        return l;
    int x = sum[L[v]] - sum[L[u]]; //计算一下 左子树在区间 [u, v] 一共增了多少个值
    if(x >= k) //如果新增的树的个数已经找过了第 k 个数的要求
        return query(L[u], L[v], l, mid, k);
    return query(R[u], R[v], mid + 1, r, k - x); //还有 k - x 个元素要找
}

int main(){
    //读入
    cin >> n >> q;
    for(int i = 1; i <= n; i ++)
        cin >> a[i], b[i] = a[i];

    //离散化
    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - b - 1;
    T[0] = build(1, m); //最大值为 m, 因为离散化后的最大下标 = 数组最大值 (最后一项会 bound 到第 b[m] 上)
    for(int i = 1; i <= n; i ++){
        a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
        //在主席树上新增节点
        T[i] = update(T[i - 1], 1, m, a[i]); //T[i] 记录在更新到第 i 项时的根节点
    }

    while(q --){
        cin >> l >> r >> x;
        int tmp = query(T[l - 1], T[r], 1, m, x);
        cout << b[tmp] << endl;
    }
    return 0;
}
*/

//https://www.luogu.com.cn/problem/P3919
//可持久化数组
#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)

const int N = 1e6 + 7;

int v[N * 25], L[N * 25], R[N * 25], root[N], cnt;

int a[N], n, q, x, y, op, stat;

inline int build(int l, int r){
    int x = ++ cnt;
    if(l == r){
        v[x] = a[l]; 
        return x;
    }
    L[x] = build(l, mid);
    R[x] = build(mid + 1, r);
    return x;
}

inline int update(int p, int l, int r, int x, int val){
    int rt = ++ cnt;
    v[rt] = v[p], L[rt] = L[p], R[rt] = R[p];
    if(l == r){
        v[rt] = val; 
        return rt;
    }
    if(x <= mid)
        L[rt] = update(L[p], l, mid, x, val);
    else
        R[rt] = update(R[p], mid + 1, r, x, val);
    return rt;
}

inline int query(int p, int l, int r, int x){
    if(l == r)
        return v[p];
    if(x <= mid)
        return query(L[p], l, mid, x);
    return query(R[p], mid + 1, r, x);
}

int main(){

    cin >> n >> q;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    
    root[0] = build(1, n);

    for(int i = 1; i <= q; i ++){
        scanf("%d %d %d", &stat, &op, &x);
        if(op == 1){
            scanf("%d", &y);
            root[i] = update(root[stat], 1, n, x, y);
        }
        else {
            printf("%d\n", query(root[stat], 1, n, x));
            root[i] = root[stat];
        }
    }

    return 0;
}