#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(q);
	for(int i = 0; i < q; i ++)
		cin >> a[i];

	vector<int> b(n + 1), res(q);
	for(int i = 0; i < q; i ++){
		if(a[i] != 0){
			res[i] = a[i];
			b[a[i]] ++;
			continue;
		}
		int mn = 1;
		for(int j = 1; j <= n; j ++){
			if(b[mn] > b[j])
				mn = j;
		}
		b[mn] ++;
		res[i] = mn;
	}
	for(int e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}