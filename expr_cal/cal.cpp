#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

string s;

int num[N], op[N];

int n, cnt, top;

map <char, int> mp;

int calc(int x, int y, char c){
	if(c == '*') return x * y;
	if(c == '/') return x / y;
	if(c == '+') return x + y;
	if(c == '-') return x - y;
	if(c == '^') return pow(x, y);
}

int main(){
	
	cin >> s;
	
	s = " (" + s + ")";
	n = s.size() - 1;
	
	mp['('] = 1, mp[')'] = 2, mp['+'] = mp['-'] = 3, mp['*'] = mp['/'] = 4, mp['^'] = 5;
	
	for(int i = 1; i <= n; i ++){
		if(s[i] <= '9' && s[i] >= '0'){
			int now = s[i] - '0';
			while(i + 1 <= n && s[i + 1] <= '9' && s[i + 1] >= '0'){
				i ++;
				now = now * 10 + (s[i] - '0');
			}
			num[++ cnt] = now;
		}
		else if(s[i] == '(') op[++ top] = s[i];
		else if(s[i] == '^') op[++ top] = s[i];
		else {
			while(mp[op[top]] >= mp[s[i]]){
				int y = num[cnt --], x = num[cnt --];
				num[++ cnt] = calc(x, y, op[top --]);
			}
			if(s[i] == ')') top --;
			else op[++ top] = s[i];
		}
	}
	cout << num[1] << endl;
	
	return 0;
}