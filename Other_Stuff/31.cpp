/*
ID: gsliu.t1
LANG: C++11
TASK: preface
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <cmath>
using namespace std;
ifstream fin("preface.in");
ofstream fout("preface.out");
const int N = 1000 + 7;
int a[N], n;
int weishu(int s){
    int ret = 0, x = s;
    while(x > 0){
        x /= 10;
        ret ++;
    }
    return ret;
}
int main(){
    fin >> n;
    for(int i = 1;i <= n;i ++){
        int temp = pow(10, weishu(i) - 1), x = i;
        if(i <= 9)
            temp = 1;
        //fout << temp << " // ";
        while(temp > 0 && x > 0){
            //fout << temp << ' ';
            if((x / temp) % 5 == 4){
                a[temp] ++;
                if(x / temp == 9)
                    a[temp * 10] ++;
                else 
                    a[temp * 5] ++;
            }
            else {
                if(x / temp >= 5){
                    a[temp * 5] ++;
                    x -= temp * 5;
                }
                //fout << "//" << x << ' ' << temp << endl;
                if(x / temp >= 1){
                    a[temp] += x / temp;
                }
                //fout << x << ' ';
            }
            x = x % temp;
            //fout << x % 10 << ' ' << temp << endl;
            temp /= 10;
            
            //fout << x << ' ' << temp << endl;
            //fout << "a[1] = " << a[1] << ' ' << "x = " << x << ' ';
        }
        //fout << endl;
    }
    //fout << endl;
    //for(int i = 1;i <= 10;i ++)
      //  fout << a[i] << ' ';
    if(a[1])
        fout << "I " << a[1] << endl;
    if(a[5])
        fout << "V " << a[5] << endl;
    if(a[10])
        fout << "X " << a[10] << endl;
    if(a[50])
        fout << "L " << a[50] << endl;
    if(a[100])
        fout << "C " << a[100] << endl;
    if(a[500])
        fout << "D " << a[500] << endl;
    if(a[1000])
        fout << "M " << a[1000] << endl;
    return 0;
}