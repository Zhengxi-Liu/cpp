#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
int n, m, k, q, dsu[N], a[N];
int t1, t2, b[N], c[N], d[N], idx = 0;
int find(int x){
    if(dsu[x] == x)
        return x;
    return dsu[x] = find(dsu[x]);
}
void merge(int x, int y){
    int xx = find(dsu[x]);
    int yy = find(dsu[y]);
    dsu[yy] = xx;
}
int main(){
    cin >> n >> m >> k >> q;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        dsu[i] = i;
    }
    for(int i = 1;i <= k;i ++){
        cin >> b[i] >> c[i];
    }
    for(int i = 1;i <= q;i ++){
        cin >> t1 >> t2;
        for(int j = 0;t1 + j < t2 - j;j ++)
            merge(t1 + j, t2 - j);
    }
    for(int i = 1;i <= n;i ++)
        if(dsu[i] == i){
            d[++ idx] = 1;
            for(int j = 1;j <= n;j ++)
                if(dsu[j] == i) 
                    d[idx] += 1;
        }
    for(int i = 1;i <= idx;i ++){
        for(int j = 1;j <= m;j ++)

    }   
    return 0;
}