#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 infll = 0x3f3f3f3f3f3f3f3f;

void solve() {
	int n, y;
	cin >> n >> y;
	vector<int> c(n), cnt(400010);
	int M = 0;
	for(auto &e : c)
		cin >> e, cnt[e] ++, M = max(M, e);
	
	vector<int> pre(2 * M + 1);
	for(int i = 1; i <= 2 * M; i ++){
		pre[i] = pre[i - 1] + cnt[i];
		// cout << "i = " << i << " pre = " << pre[i] << '\n'; 
	}
	
	i64 ans = n - (i64)y * (n - cnt[1]);
	for(int x = 2; x <= M; x ++){
		i64 tag = 0, sum = 0;
		for(int i = x; i < M + x; i += x){
			sum += (i64)(i / x) * (pre[i] - pre[i - x]);
			tag += max(0, pre[i] - pre[i - x] - cnt[(i / x)]);
			// cout << "i = " << i << " tag = " << tag << '\n';
		}
		ans = max(ans, sum - tag * y);
	}
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