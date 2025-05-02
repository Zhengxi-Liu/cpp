/*
ID: gsliu.t1
LANG: C++11
TASK: friday
*/
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
const int N = 7 + 7;
int n, a[N], last = 5;
int main(){
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    fin >> n;
    for(int i = 1;i <= n;i ++){
        int flag = 0, idx = 0;
        if((i + 1899) % 4 == 0 && (i + 1899) % 100 != 0 || (i + 1899) % 400 == 0)
            flag = 1;
        for(int j = 1;j <= 12;j ++){
            if(j == 3){
                if(flag)
                    last = (last + 29) % 7;
                else
                    last = (last + 28) % 7;
            }
            else if(j == 5 || j == 7 || j == 10 || j == 12)
                last = (last + 30) % 7;
            else
                last = (last + 31) % 7;
            if(!last)
                last = 7;
            a[last] ++;
        }
    }
    for(int i = 1;i <= 7;i ++){
        fout << a[i];
        if(i == 7)
            fout << endl;
        else
            fout << ' ';
    }
    return 0;
}