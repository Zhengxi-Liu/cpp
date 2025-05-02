/*
ID: gsliu.t1
LANG: C++11
TASK: milk2
*/
#include<map>
#include<string>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5e3 + 7;
struct str {
    int x, y;
}a[N];
int n, b[N], c[N], t = 0, id1 = 0, id2 = 0;
bool cmp(str a, str b){
    return a.x < b.x;
}
bool cmp2(int a, int b){
    return a > b;
}
int main(){
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    fin >> n;
    for(int i = 1;i <= n;i ++)
        fin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1;i <= n;i ++){
        if(a[i].x > t || !t){
            if(t > 0)
                c[++ id2] = a[i].x - t;
            b[id1] = t - b[id1];
            b[++ id1] = a[i].x;
            t = a[i].y;
        }
        t = max(a[i].y, t);
        if(i == n)
           b[id1] = t - b[id1]; 
    }
    sort(b + 1, b + id1 + 1, cmp2);
    sort(c + 1, c + id2 + 1, cmp2);
    fout << b[1] << ' ' << c[1] << endl;
    return 0;
}