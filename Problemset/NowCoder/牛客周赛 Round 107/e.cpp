#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, a, k;
	cin >> n >> a >> k;
	if(n == 1){
		if(a != k)
			cout << -1 << '\n';
		else
			cout << a << '\n';
		return;
	}

	if(k - (n + 1) / 2 > a - n || k < (a + 1) / 2){
		cout << -1 << '\n';
		return;
	};
	
	vector<int> arr(n, 1);
	a -= n;
	k -= (n + 1) / 2;
	arr[0] += k;
	arr[1] += k;
	int d = n + 2 * k - (a + n);
	arr[1] -= d;
	for(auto e : arr)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}