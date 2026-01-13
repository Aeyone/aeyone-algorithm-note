#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	if(k == n - 1){
		if(n == 4)
			cout << -1 << '\n';
		else{
			cout << n - 1 << ' ' << n - 2 << '\n';
			cout << 1 << ' ' << 3 << '\n';
			cout << 0 << ' ' << n - 3 - 1 << '\n';
			for(int i = 2; i < n / 2; i ++){
				if(i == 3)
					continue;
				cout << i << ' ' << n - i - 1 << '\n';
			}
		}
		return;
	}
	for(int i = 1; i < n / 2; i ++){
		if(i == k || n - i - 1 == k)
			continue;
		cout << i << ' ' << n - i - 1 << '\n';
	}
	if(k == 0)
		cout << 0 << ' ' << n - 1 << '\n';
	else{
		cout << k << ' ' << n - 1 << '\n';
		cout << 0 << ' ' << n - k - 1 << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}