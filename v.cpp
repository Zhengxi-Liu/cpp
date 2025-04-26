#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
long long n, m, k, dsu[N];
struct str{
    long long a, b, c;
}s[N];
int find(long long x){
    if(dsu[x] == x)
        return x;
    return dsu[x] = find(dsu[x]);
}
void merge(long long x, long long y){
    int s1 = find(x);
    int s2 = find(y);
    dsu[s1] = dsu[s2];
}
bool cmp(str x, str y){
    return x.c > y.c;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i ++)
        dsu[i] = i;
    for(int i = 1;i <= m;i ++)
        cin >> s[i].a >> s[i].b >> s[i].c;
    sort(s + 1, s + m + 1, cmp);
    long long cnt = n, ans = -1;
    for(int i = 1;i <= m;i ++){
        if(find(s[i].a) != find(s[i].b)){
            cnt -= 1;
            merge(s[i].a, s[i].b);
        }
        if(cnt == k){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    if(ans == -1){
       cout << "IMPOSSIBLE" << endl;
    }
    else {
        for(int i = ans + 1;i <= m;i ++){
            if(find(s[i].a) != find(s[i].b)){
                cout << s[i].c + 1 << endl;
                return 0;
            }
        }
        cout << "0" << endl;
    }
    return 0;
}