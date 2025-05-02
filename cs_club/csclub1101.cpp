/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], low[N], dp[N], b[N], ans[N], n, maxn = 0;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    b[0] = -1;
    for(int i = 1;i <= n;i ++){
        if(a[i] >= low[maxn]){
            low[++ maxn] = a[i];
            continue;
        }
        int idx = upper_bound(low + 1, low + n + 1, a[i]) - low;
        low[idx] = a[i];
        dp[idx] = i;
        b[i] = dp[idx - 1];
        if(maxn < idx)
            maxn = idx;
    }
    int k = maxn, idx = dp[maxn];
    while(idx != -1){
        ans[k --] = a[idx];
        idx = b[idx];
        cout << idx << ' ';
    }
    cout << endl;
    for(int i = 1;i <= maxn;i ++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}*/
/*
4964 9279 10661 10901 16748 19838 20803 26261 28237 34836 35433 38645 49487 53889 65524
2227 7719 8229 9731 11659 13773 22743 24290 29517 30884 33567 34895 41153 46197 49833 53173 55396 61833 66191 74172
*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
string a[N], low[N];
int dp[N], n, maxn = 0;
bool cmp(string x, string y){
    if(x.size() < y.size())
        return false;
    if(y == "")
        return true;
    for(int i = 0;i < y.size();i ++)
        if(x[i] != y[i])
            return false;
    return true;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    low[0] = "";
    for(int i = 1;i <= n;i ++){
        if(cmp(a[i], low[maxn])){
            low[++ maxn] = a[i];
            continue;
        }
        int l = 0, r = maxn, s = 0;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(!cmp(a[i], low[mid]) && cmp(a[i], low[mid - 1])){
                r = mid;
                break;
            }
            else if(cmp(low[mid], a[i]))
                r = mid;
            else
                l = mid;
            s ++;
        }
        //cout << r << ' ' << i << endl;
        low[r] = a[i];
        //int idx = upper_bound(low + 1, low + maxn + 1, a[i]) - low;
        //low[idx] = a[i];
    }
    for(int i = 1;i <= maxn;i ++)
        cout << low[i] << ' ';
    cout << endl << maxn << endl;
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], low[N], pos[N], prev_idx[N], ans[N];
int n, length = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    low[0] = -1e9; 
    for (int i = 1; i <= n; ++i)
        low[i] = 1e9; 
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(low + 1, low + n + 1, a[i]) - low;
        low[idx] = a[i];
        pos[idx] = i;
        prev_idx[i] = pos[idx - 1];
        if (idx > length)
            length = idx; 
    }
    int k = length;
    int idx = pos[length];
    while (k >= 1) {
        ans[k --] = a[idx];
        idx = prev_idx[idx];
    }
    for (int i = 1; i <= length; i++) 
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
