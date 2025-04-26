/*#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 7;
long long a[N], b[N], n, q;
int main(){
    cin >> n >> q;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    while(q --){
        long long x, l, r;
        cin >> x >> l >> r;
        if(x == 1){
            a[l] = r;
            continue;
        }
        else if(x == 2){
            memset(b, 0, sizeof(b));
            for(int i = l;i <= r;i ++)
                b[a[i]] += 1;
            for(int i = 1;i <= n;i ++)
                if(b[i] == 0){
                    cout << i << endl;
                    break;
                }
        }
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], b[N], ans[N], ans2[N], c[N];
int n, idx = 0;
vector <int> d[N];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        d[a[i]].push_back(i);
    }
    for(int i = 1;i <= n;i ++){
        //cout << a[i] << ' ';
        b[a[i]] = i;
    }
    for(int i = 1;i <= n;i ++)
        if(a[i] != i && d[a[i]].size() == 1){
            ans[++ idx] = i;
            ans2[idx] = b[i];
            a[b[i]] = a[i];
            b[a[i]] = b[i];
            b[i] = i;
            a[i] = i;
        }
    int t = idx;
    for(int i = 1;i <= n;i ++)
        if(a[i] == i)
            c[i] = 1;
    for(int i = 1;i <= n;i ++){//the i'th toy
        //cout << d[i].size() << ' ';
        if(d[i].size() > 1){
            //cout << "/" << c[i] << ' ';
            if(c[i] == 1){
                for(int j = 0;j < d[i].size();j ++){
                    if(d[i][j] != i){
                        ans2[++ idx] = i;
                        ans[idx] = d[i][j];
                        a[d[i][j]] = 0;
                    }
                }
            }
            else {
                for(int j = 1;j < d[i].size();j ++){
                    ans2[++ idx] = d[i][0];
                    ans[idx] = d[i][j];
                    a[d[i][j]] = 0;
                }
            }
        }
        //cout << endl;
    }
    cout << idx << endl;
    for(int i = 1;i <= idx;i ++){
        if(i <= t)
            cout << "1 ";
        else
            cout << "2 ";
        cout << ans[i] << ' ' << ans2[i] << endl;
    }
    return 0;
}*/
