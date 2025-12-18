#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(k);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < k; i ++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	i64 ans = 0;
	for(int i = 0; i < k; i ++){
		if(b[i] > a.size()){
			break;
		}
		while(b[i] > 1 && a.size() > 1){
			ans += a.back();
			a.pop_back();
			b[i] --;
		}
		a.pop_back(), b[i] --;
	}
	while(a.size())
		ans += a.back(), a.pop_back();
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}