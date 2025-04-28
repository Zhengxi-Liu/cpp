#include<iostream>
using namespace std;
int main(){
    long long n = 7999999999, m;
    cin >> m;
    for(long long i = 3;i * i <= n;i += 2)
        if(n % i == 0)
            cout << i << ' ';
    return 0;
}