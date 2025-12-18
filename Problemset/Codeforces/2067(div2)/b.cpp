#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cnt(n + 1);
	for(int i = 0; i < n; i ++)
		cin >> a[i], cnt[a[i]] ++;

	for(int i = n; i >= 1; i --){
		if(!(cnt[i] & 1))
			continue;
		int c = 1;
		for(int j = i - 1; j >= 1; j --){
			if(cnt[j] - 1 >= c){
				cnt[j] -= c;
				cnt[i] ++;
				break;
			}else{
				c -= cnt[j], cnt[j] = 1, c ++;
			}
		}
	}
	bool ok = true;
	for(int i = 1; i <= n; i ++)
		ok &= !(cnt[i] & 1);
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}