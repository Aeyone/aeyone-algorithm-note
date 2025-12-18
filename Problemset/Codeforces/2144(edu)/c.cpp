#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2), b(n + 2);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	a[n + 1] = 1e9;
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	b[n + 1] = 1e9;

	for(int i = 1; i <= n; i ++){
		if(a[i] - a[i - 1] < 0 || b[i] - b[i - 1] < 0)
			swap(a[i], b[i]);
	}
	bool ok1 = true;
	for(int i = 1; i <= n; i ++){
		ok1 &= (a[i] - a[i - 1] >= 0 && b[i] - b[i - 1] >= 0);
	}
	if(!ok1){
		cout << 0 << '\n';
		return;
	}
	i64 pre = 1;
	for(int i = 1; i < n; i ++){
		if(a[i + 1] - b[i] >= 0 && b[i + 1] - a[i] >= 0)
			pre = pre * 2 % mod;
	}
	i64 suf = 1;
	for(int i = n; i > 1; i --){
		if(a[i] - b[i - 1] >= 0 && b[i] - a[i - 1] >= 0)
			suf = suf * 2 % mod;
	}
	cout << (pre + suf) % mod << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}