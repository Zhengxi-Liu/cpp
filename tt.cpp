#include<bits/stdc++.h>
using namespace std;

int main(){
    
    for(long long n = 1;n <= 30;n ++)
        cout << pow(2, n) * pow(2, n) << ' ' << pow(2, n * n) << ' ' << pow(pow(2, n), n) << endl;
    return 0;
}