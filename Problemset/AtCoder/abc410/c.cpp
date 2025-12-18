#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		a[i] = i + 1;

	int k = 0;
	while(q --){
		int sign;
		cin >> sign;
		if(sign == 1){
			int p, x;
			cin >> p >> x;
			a[(p + k + n - 1) % n] = x;
		}
		if(sign == 2){
			int p;
			cin >> p;
			cout << a[(p + k + n - 1) % n] << '\n';
		}
		if(sign == 3){
			int k1;
			cin >> k1;
			k = (k + k1) % n;
		}
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}