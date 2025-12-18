#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int ans = 0;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		if(a[i] == 0) {
			a[i] = INF;
			ans --;
		}
		if(a[i] <= 4) {
			a[i] += (a[i] & 1);
		}
	}
	vector<array<int, 2>> seg;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && (a[l] > 4) == (a[r] > 4)) {
			r ++;
		}
		if(a[l] <= 4) {
			seg.push_back({l, r});
		}else{
			ans += (r - l);
		}
	}
	vector<vector<int>> dp(n, vector<int>(4, INF));
	for(auto [L, R] : seg) {
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}