#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 7;
struct block{
    long double x1, y1, x2, y2, m, rx;
}a[N];
int n, t;
bool f;
block dfs(int p){
    block tmp;
    bool ff = false;
    tmp.rx = tmp.m = 0;
    if(p * 2 + 1 < n){
        ff = true;
        if(a[p * 2 + 1].y1 != a[p].y2)
            f = true;
        block ss = dfs(p * 2 + 1);
        tmp.rx += ss.rx * ss.m;
        tmp.m += ss.m;
        //cout << ss.m << endl;
    }
    if(p * 2 + 2 < n){
        if(a[p * 2 + 2].y1 != a[p].y2)
            f = true;
        ff = true;
        block ss = dfs(p * 2 + 2);
        tmp.rx += ss.rx * ss.m;
        tmp.m += ss.m;
        //cout << ss.m << endl;
    }
    //cout << p << endl;
    if(ff == true && (tmp.rx < a[p].x1 || tmp.rx > a[p].x2))
        f = true;
    block ret;
    ret.m = tmp.m + a[p].m;
    ret.rx = (tmp.rx + a[p].m * a[p].rx) / ret.m;
    return ret;
}
int main(){
    cin >> t;
    while(t --){
        cin >> n;
        for(int i = 0;i < n;i ++){
            cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
            a[i].m = abs(a[i].x1 - a[i].x2) * abs(a[i].y1 - a[i].y2);
            a[i].rx = (a[i].x1 + a[i].x2) / 2;
        }
        f = false;
        if(a[0].y1 != 0)
            f = true;
        dfs(0);
        if(f == false)
            cout << "Stable" << endl;
        else
            cout << "Unstable" << endl;
    }
    return 0;
}