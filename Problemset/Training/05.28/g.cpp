#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	for(int i = 0; i < n - 2; i ++)
		for(int j = i + 1; j < n - 1; j ++)
			for(int k = j + 1; k < n; k ++){
				if(a[i] ==  a[j] + a[k]){
					cout << i + 1 << " " << j + 1 << " " << k + 1 << '\n';
					return;
				}
				if(a[j] == a[k] + a[i]){
					cout << j + 1 << " " << k + 1 << " " << i + 1 << '\n';
					return;
				}
				if(a[k] == a[j] + a[i]){
					cout << k + 1 << " " << j + 1 << " " << i + 1 << '\n';
					return;
				}
			}

	cout << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}