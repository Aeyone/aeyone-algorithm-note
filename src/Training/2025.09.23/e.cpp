#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {//辗转相除好题
	i64 L, R, x;
	cin >> L >> R >> x;
	bool ok = false;
	auto f = [&](auto &&self, i64 a, i64 b)->void{
		if(a == 0)
			return;
		if((x - (b % a)) % a == 0){
			ok |= ((x - (b % a)) / a <= b / a);
		}
		self(self, b % a, a);
	};
	f(f, L, R);
	if(ok){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}