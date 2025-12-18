#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> b(n), c(n);
	for(int i = 0; i < n; i ++)
		cin >> b[i];

	int s = 0;
	for(int i = 0; i < n; i ++)
		cin >> c[i], s += c[i];

	vector<int> cnt(1010, inf);
	queue<int> q;
	q.push(1);
	cnt[1] = 0;
	while(q.size()){
		int x = q.front();
		q.pop();
		for(int i = 1; i <= x; i ++){
			int y = x + x / i;
			if(y > 1000)
				continue;
			if(cnt[y] > cnt[x] + 1){
				cnt[y] = cnt[x] + 1;
				q.push(y);
			}
		}
	}

	int sum = 0;
	for(auto e : b)
		sum += cnt[e];

	if(k > sum){
		cout << s << '\n';
		return;
	}
	vector<int> dp(k + 1);
	for(int i = 0; i < n; i ++)
		for(int j = k; j >= cnt[b[i]]; j --)
			dp[j] = max(dp[j], dp[j - cnt[b[i]]] + c[i]);
		
	int ans = 0;
	for(int i = 0; i <= k; i ++)
		ans = max(ans, dp[i]);

	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}