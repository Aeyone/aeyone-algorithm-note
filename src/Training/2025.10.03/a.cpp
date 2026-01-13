#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1);
	int idx = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i] == x){
			idx = i;
		}
	}
	int l = 1, r = n + 1;
	while(l < r - 1){
		int mid = (l + r) / 2;
		if(a[mid] <= x){
			l = mid;
		}else{
			r = mid;
		}
	}
	if(a[l] == x){
		cout << 0 << '\n';
		return;
	}
	cout << 1 << '\n';
	cout << idx << ' ' << l << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}