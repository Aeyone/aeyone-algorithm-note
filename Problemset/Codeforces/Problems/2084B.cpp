#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 infll = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	i64 mn = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(a[i] < a[mn])
			mn = i;
	}

	i64 g = -1;
	for(int i = 0; i < n; i ++){
		if(i == mn)
			continue;
		if(a[i] % a[mn] == 0){
			if(g == -1)
				g = a[i];
			g = gcd(g, a[i]);
		}
	}
	
	if(a[mn] == g)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}