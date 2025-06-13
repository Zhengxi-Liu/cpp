#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, INF = 1e9;

char op[N][2];

int n, top, num[N][2], cnt[2], t;

string s;

int id(char c){
	if(c == '(') return 1;
	if(c == ')') return 2;
	if(c == '+' || c == '-') return 3;
	if(c == '*' || c == '/') return 4;
	return 5;
}

bool is_num(char c){
    if(c <= '9' && c >= '0') return true;
    return false;
}

int cal(int x, int y, char c){
    if(c == '+') return x + y;
    if(c == '-') return x - y;
    if(c == '*') return x * y;
    if(c == '/') return x / y;
    return pow(x, y);
}

int main(){
	
	cin >> s;
	s = " (" + s + ")";
	n = s.size() - 1;

    for(int i = 1; i <= n; i ++){
        num[i][t ^ 1] = INF;
        op[i][t ^ 1] = '.';
    }
	
	for(int i = 1; i <= n; i ++){
		if(is_num(s[i])){
            num[++ cnt[t ^ 1]][t ^ 1] = s[i] - '0';
            cout << s[i] << ' ';
        }
		else if(s[i] == '(') op[++ top][t] = s[i];
		else if(s[i] == '^') op[++ top][t] = s[i];
		else {
			while(id(op[top][t]) >= id(s[i])){
                op[++ cnt[t ^ 1]][t ^ 1] = op[top][t];
				cout << op[top --][t] << ' ';
            }
			if(s[i] == ')') top --;
			else op[++ top][t] = s[i];
		}
	}

	while(top){
        op[++ cnt[t ^ 1]][t ^ 1] = op[top][t];
		cout << op[top --][t] << ' ';
    }
	cout << endl;
    t ^= 1;
    // for(int i = 1; i <= cnt[t]; i ++){
    //     if(num[i][t] != INF) cout << num[i][t] << ' ';
    //     else cout << op[i][t] << ' ';
    // }
    // cout << endl;
    while(cnt[t] > 1){
        cnt[t ^ 1] = 0;
        for(int i = 1; i <= cnt[t]; i ++){
            num[i][t ^ 1] = INF;
            op[i][t ^ 1] = '.';
        }
        int flg = 0;
        for(int i = 1; i <= cnt[t]; i ++){
            if(!flg && i <= cnt[t] - 2 && num[i][t] != -1 && num[i + 1][t] != -1 && op[i + 2][t] != '.'){
                num[++ cnt[t ^ 1]][t ^ 1] = cal(num[i][t], num[i + 1][t], op[i + 2][t]);
                i += 2;
                flg = 1;
            }
            else if(num[i][t] != INF) num[++ cnt[t ^ 1]][t ^ 1] = num[i][t];
            else op[++ cnt[t ^ 1]][t ^ 1] = op[i][t];
        }
        t ^= 1;
        //cout << cnt[t ^ 1] << ' ' << cnt[t] << endl;
        for(int i = 1; i <= cnt[t]; i ++){
            if(num[i][t] != INF) cout << num[i][t] << ' ';
            else cout << op[i][t] << ' ';
        }
        cout << endl;
    }
    
	
	return 0;
}