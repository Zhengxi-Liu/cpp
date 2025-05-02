/*
ID: gsliu.t1
LANG: C++11
TASK: palsquare
*/
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
const int N = 1e6 + 7;
int n, a[N], b[N];
int main(){
    ofstream fout("palsquare.out");
    ifstream fin("palsquare.in");
    fin >> n;
    for(int i = 1;i <= 300;i ++){
        int temp1 = i, temp2 = i * i;
        int idx1 = 0, idx2 = 0, f1 = 0, f2 = 0;
        while(temp1 > 0){
            a[++ idx1] = temp1 % n;
            temp1 /= n;
        }
        while(temp2 > 0){
            b[++ idx2] = temp2 % n;
            temp2 /= n;
        }
        for(int j = 1;j <= idx1 / 2;j ++)
            if(a[j] != a[idx1 - j + 1])
                f1 ++;
        for(int j = 1;j <= idx2 / 2;j ++)
            if(b[j] != b[idx2 - j + 1])
                f2 ++;
        if(/*!f1 &&*/ !f2){
            for(int j = idx1;j >= 1;j --){
                if(a[j] > 9)
                    fout << char(a[j] - 10 + int('A'));
                else
                    fout << a[j];
            }
            fout << ' ';
            for(int j = 1;j <= idx2;j ++){
                if(b[j] > 9)
                    fout << char(b[j] - 10 + int('A'));
                else
                    fout << b[j];
            }
            fout << endl;
        }
    }
    return 0;
}