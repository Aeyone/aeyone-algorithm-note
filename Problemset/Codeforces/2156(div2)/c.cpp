#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	map<int, int> mp;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		mp[a[i]] ++;
	}
	sort(a.begin(), a.end());
	for(int p = n; p >= 2; p --){
		int need = lower_bound(a.begin(), a.end(), 4 * p) - a.begin();
		need -= (mp[p] + mp[2 * p] + mp[3 * p]);
		if(need <= k){
			cout << p << '\n';
			return;
		}
	}
	cout << 1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}