/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, x, k = 0;
void insert(int x){
    a[++ k] = x;
    int idx = k;
    while(idx > 1){
        int parent = idx / 2;
        if(a[parent] <= a[idx])
            break;
        swap(a[parent], a[idx]);
        idx = parent;
    }
}
void delet(){
    if(!k)
        return;
    a[1] = a[k];
    k --;
    int idx = 1;
    while(idx <= k){
        int l = idx * 2, r = l + 1, minn = idx;
        if(l <= k && a[l] < a[minn])
            minn = l;
        if(r <= k && a[r] < a[minn])
            minn = r;
        if(minn == idx)
            break;
        swap(a[idx], a[minn]);
        idx = minn;
    }
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> x;
        if(x == 1){
            cin >> x;
            insert(x);
        }
        else if(x == 2)
            cout << a[1] << endl;
        else 
            delet();
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, x, k = 0;
void insert(int x){
    a[++ k] = x;
    int idx = k;
    while(idx > 1){
        int parent = idx / 2;
        if(a[parent] <= a[idx])
            break;
        swap(a[parent], a[idx]);
        idx = parent;
    }
}
void delet(){
    if(!k)
        return;
    a[1] = a[k];
    k --;
    int idx = 1;
    while(idx <= k){
        int l = idx * 2, r = l + 1, minn = idx;
        if(l <= k && a[l] < a[minn])
            minn = l;
        if(r <= k && a[r] < a[minn])
            minn = r;
        if(minn == idx)
            break;
        swap(a[idx], a[minn]);
        idx = minn;
    }
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> x;
        insert(x);
    }
    for(int i = 1;i <= n;i ++){
        cout << a[1] << ' ';
        delet();
    }
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
priority_queue < int, vector <int>, greater <int> > q;//smaller
priority_queue < int, vector <int>, less <int> > p;//bigger
int n, x, y, median;
int main(){
    cin >> n >> median;
    cout << median << endl;
    for(int i = 1;i * 2 <= n - 1;i ++){
        cin >> x >> y;
        if(x > median && y > median){
            q.push(x);
            q.push(y);
            p.push(median);
            median = q.top();
            q.pop();
        }
        else if(x < median && y < median){
            p.push(x);
            p.push(y);
            q.push(median);
            median = p.top();
            p.pop();
        }
        else if(x == median){
            if(y == median){
                p.push(x);
                q.push(y);
            }
            else if(y < median){
                q.push(x);
                p.push(y);
            }
            else {
                p.push(x);
                q.push(y);
            }
        }
        else if(x > median){
            if(y == median){
                q.push(x);
                p.push(y);
            }
            else{
                q.push(x);
                p.push(y);
            }
        }
        else if(x < median){
            if(y == median){
                p.push(x);
                q.push(y);
            }
            else {
                p.push(x);
                q.push(y);
            }
        }
        cout << median << endl;
    }
    return 0;
}*/
//堆的模版,正确.
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
int h[N * 4], n, idx, op, x;
int top(){
    return h[1];
}
void modify(int k){
    if(k == 1 || h[k / 2] < h[k])
        return;
    swap(h[k], h[k / 2]);
    modify(k / 2);
}
void push(int x){
    h[++ idx] = x;
    modify(idx);
}
void repair(int k){
    if(k * 2 > idx)
        return;
    int t = k * 2;//取两个子节点中最小的.
    if(t + 1 <= idx){
        if(h[t] > h[t + 1])
            t ++;
    }
    if(h[k] > h[t]){
        swap(h[t], h[k]);
        repair(t);
    }
}
void pop(){
    swap(h[1], h[idx --]);
    repair(1);
}
signed main(){
    cin >> n;
    while(n --){
        cin >> op;
        if(op == 1){
            cin >> x;
            push(x);
        }
        else if(op == 2)
            cout << top() << endl;
        else
            pop();
    }
    return 0;
}