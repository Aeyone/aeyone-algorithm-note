#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, d;
	cin >> n >> d;
	if(d == 0) {
		vector<int> a(n);
		for(int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		cout << n - a.size() << '\n';
		return;
	}
	vector<vector<int>> a(d);
	for(int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		a[x % d].push_back(x / d);
	} 
	int ans = 0;
	for(auto &v : a) {
		if(v.size() == 0) {
			continue;
		}
		sort(v.begin(), v.end());
		int m = v.size();
		vector<array<int, 2>> arr;
		for(int l = 0, r = 0; l < m; l = r) {
			while(r < m && v[r] == v[l]){
				r ++;
			}
			arr.push_back({v[l], r - l});
		}
		m = arr.size();
		for(int l = 0, r = 1; r < m; l = r, r ++){
			vector<int> b;
			b.push_back(arr[l][1]);
			while(r < m && arr[r][0] == arr[r - 1][0] + 1) {
				b.push_back(arr[r][1]);
				r ++;
			}
			if(b.size() <= 1){
				continue;
			}
			int len = r - l;
			vector<int> dp(len, INF);
			dp[0] = b[0], dp[1] = b[1];
			for(int i = 2; i < len; i ++) {
				dp[i] = min(dp[i - 1], dp[i - 2]) + b[i];
			}
			ans += min(dp[len - 2], dp[len - 1]);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}