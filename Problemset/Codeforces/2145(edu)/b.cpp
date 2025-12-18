#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int l = 0, r = 0, cnt = 0;
	for(auto e : s){
		l += (e == '0');
		r += (e == '1');
		cnt += (e == '2');
	}
	string res = string(n, '+');
	for(int i = 0; i < n; i ++){
		if(l > 0){
			res[i] = '-';
			l --;
		}
	}
	for(int i = n - 1; i >= 0; i --){
		if(r > 0){
			res[i] = '-';
			r --;
		}
	}
	int L = 0, R = n - 1;
	while(res[L] == '-'){
		L ++;
	}
	while(res[R] == '-'){
		R --;
	}

	if(cnt >= R - L + 1){
		while(L <= R){
			res[L ++] = '-';
		}
	}else{
		while(cnt > 0 && L <= R){
			res[L ++ ] = '?';
			res[R --] = '?';
			cnt --;
		}
	}
	cout << res << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}