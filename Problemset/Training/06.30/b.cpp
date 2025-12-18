#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x7f7f7f7f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int num = -1;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	i64 x = 0, h = inf;
	for(int i = 1; i < n; i ++){
		if(h == inf && a[i] >= a[i - 1])
			h = a[i - 1] + (a[i] + a[i - 1] + 1) / 2;

		if(a[i] < a[i - 1])
			x += (a[i] + (a[i - 1] - a[i] + 1) / 2);
		if(x > h){
			cout << -1 << '\n';
			return;
		}
	}
	a[0] = abs(a[0] - x);
	for(int i = 1; i < n; i ++){
		a[i] = abs(a[i] - x);
		if(a[i] < a[i - 1]){
			cout << -1 << '\n';
			return;
		}
	}
	cout << x << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}