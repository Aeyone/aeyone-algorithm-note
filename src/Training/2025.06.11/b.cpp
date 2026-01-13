#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i ++)
		cin >> a[i], sum += a[i];
	
	if(sum & 1){
		cout << 0 << '\n';
		return;
	}
	vector<int> dp(sum + 1);
	dp[0] = 1;
	for(int i = 0; i < n; i ++)
		for(int j = sum; j > 0; j --)
			if(j - a[i] >= 0)
				dp[j] |= (dp[j - a[i]]);

	if(!dp[sum >> 1]){
		cout << 0 << '\n';
		return;
	}
	int mn = 0;
	cout << 1 << '\n';
	while(1){
		for(int i = 0; i < n; i ++){
			if(a[i] & 1){
				cout << i + 1 << '\n';
				return;
			}
			a[i] >>= 1;
		}
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}