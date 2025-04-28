/*
ID: gsliu.t1
LANG: C++11
TASK: dualpal
*/
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N], cnt = 0;
int main(){
    ofstream fout("dualpal.out");
    ifstream fin("dualpal.in");
    fin >> n >> m;
    for(int i = m + 1;;i ++){
        int sign = 0;
        for(int j = 2;j <= 10;j ++){
            int temp = i, idx = 0, flag = 0;
            while(temp > 0){
                a[++ idx] = temp % j;
                temp /= j;
            }
            for(int k = 1;k <= idx / 2;k ++)
                if(a[k] != a[idx - k + 1])
                    flag ++;
            if(!flag && a[1] != 0)
                sign ++;
        }
        if(sign >= 2){
            fout << i << endl;
            cnt ++;
        }
        if(cnt == n)
            break;
    }
    return 0;
}