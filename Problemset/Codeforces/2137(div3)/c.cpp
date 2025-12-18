#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 a, b;
	cin >> a >> b;
	if((a & 1) && (b & 1)){
		cout << a * b + 1 << '\n';
		return;
	}
	if(!(a & 1) && !(b & 1)){
		cout << a * (b / 2) + 2 << '\n';
		return;
	}
	if((a & 1) && !(b & 1)){
		if(b % 4 != 0)
			cout << -1 << '\n';
		else{
			cout << a * (b / 2) + 2 << '\n';
		}
		return;
	}
	cout << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}