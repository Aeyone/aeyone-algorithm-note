#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void debug(i64 x, int siz){
	string res;
	for(int i = 0; (x >> i) > 0; i ++){
		if((x >> i) & 1)
			res += "1";
		else
			res += "0";
	}
	reverse(res.begin(), res.end());
	while(res.size() < siz)
		res = " " + res;
	cout << res << '\n';
}

void solve() {
	int x;
	cin >> x;
	i64 a = 0, b = 0;
	i64 res = x << 1;
	for(int i = 0; (x >> i) > 0; i ++){
		if((x >> i) & 1){
			if(!b)
				b += (1 << i);
			a += (1 << i);
		}else{
			if(((res >> (i + 1)) & 1) ^ ((x >> (i + 1)) & 1))
				a += (1 << i), b += (1 << i);
		}
	}
	// debug(x, 6);
	// debug(a, 6);
	// debug(b, 6);
	// debug(res, 6);
	// debug(a + b, 6);
	if((a ^ b) == (a + b) / 2 && (a ^ b) == x)
		cout << a << ' ' << b << '\n';
	else
		cout << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}