#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		mp[a[i]] ++;
	}
	i64 sum = 0, cnt = 0;
	vector<int> v;
	for(auto &[e, c] : mp){
		sum += (i64)e * c - (c & 1 ? e : 0);
		cnt += (c / 2);
		if(c & 1){
			v.push_back(e);
		}
	}
	sort(v.begin(), v.end(), greater<int>{});
	int m = v.size();
	int ans = 0;
	for(int i = 0; i < m; i ++){
		if(v[i] - (i + 1 == m ? 0 : v[i + 1]) < sum){
			ans = max(ans, v[i] + (i + 1 == m ? 0 : v[i + 1]));
		}
	}
	if(ans == 0 && cnt == 1){
		cout << 0 << '\n';
		return;
	}
	cout << sum + ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}