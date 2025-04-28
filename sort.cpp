//计数排序
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], cnt[N], b[N], n, ma;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        cnt[a[i]] ++;
        ma = max(ma, a[i]);
    }
    for(int i = 1;i <= ma;i ++){
        cnt[i] = cnt[i - 1] + cnt[i];
    }
    for(int i = n;i >= 1;i --){
        b[cnt[a[i]] --] = a[i];
    }
    for(int i = 1;i <= n;i ++)
        cout << b[i] << ' ';
    return 0;
}*/

//基数排序
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 10 + 7;
int a[N], cnt[M], b[N];
int n, ma;
void counting(int exp){
    memset(b, 0, sizeof(b));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1;i <= n;i ++)
        cnt[a[i] / exp % 10] ++;
    for(int i = 1;i <= 9;i ++)
        cnt[i] += cnt[i - 1];
    for(int i = n;i >= 1;i --)
        b[cnt[a[i] / exp % 10] --] = a[i];
    for(int i = 1;i <= n;i ++)
        a[i] = b[i];
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i], ma = max(ma, a[i]);
    for(int exp = 1; ma / exp > 0; exp *= 10)
        counting(exp);
    for(int i = 1;i <= n;i ++)
        cout << a[i] << ' ';
    return 0;
}*/

//归并排序
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], b[N], n;
void merge_sort(int l, int r){
    if(l >= r)
        return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) b[++ k] = a[i ++];
        else b[++ k] = a[j ++];
    }
    while(i <= mid) b[++ k] = a[i ++];
    while(j <= r) b[++ k] = a[j ++];
    for(int i = l, j = 1; i <= r; i ++, j ++)
        a[i] = b[j];
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    merge_sort(1, n);
    for(int i = 1;i <= n;i ++)
        cout << a[i] << ' ';
    return 0;
}*/

//归并排序求逆序对
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], b[N], n;
int merge_sort(int l, int r){
    if(l >= r)
        return 0;
    int mid = (l + r) >> 1, res = 0;
    res = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) b[++ k] = a[i ++];
        else {
            b[++ k] = a[j ++];
            res += mid - i + 1;
        }
    }
    while(i <= mid) b[++ k] = a[i ++];
    while(j <= r) b[++ k] = a[j ++];
    for(int i = l, j = 1; i <= r; i ++, j ++)
        a[i] = b[j];
    return res;
}
int main(){
    while(cin >> n && n){
        for(int i = 1;i <= n;i ++)
            cin >> a[i];
        cout << merge_sort(1, n) << endl;
    }
    return 0;
}