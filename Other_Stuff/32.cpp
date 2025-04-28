/*
ID: gsliu.t1
LANG: C++11
TASK: subset
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("subset.in");
ofstream fout("subset.out");
const int N = 2e3 + 7;
long long a[N], b[N], n, sum, ans = 0;
int main(){
    fin >> n;
    sum = n * (n + 1) / 2;
    if(sum % 2 == 1){
        fout << '0' << endl;
        return 0;
    }
    sum /= 2;
    a[0] = 1;
    for(int i = 1;i <= n;i ++){
        //memset(b, 0, sizeof(b));
        for(int j = i;j <= sum;j ++){
            if(a[j - i])
                b[j] = a[j - i];
        }
        for(int j = i;j <= sum;j ++){
            a[j] += b[j];
            //fout << a[j] << ' ';
            b[j] = 0;
        }
        //fout << endl;
    }
    //for(int i = 1;i <= sum;i ++)
        //fout << a[i] << ' ';
    //fout << endl;
    fout << a[sum] / 2 << endl;
    return 0;
}