#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	vector<int> a(5), p(1001);
	int cnt = 0;
	for(int i = 0; i < 5; i ++){
		cin >> a[i];
		if(a[i])
			cnt ++;
		p[a[i]] ++;
	}
	int k;
	cin >> k;
	if(!cnt)
		cout << "1/1000" << '\n';
	else if(!p[k])
		cout << "0/1" << '\n';
	else if(p[k] && cnt)
		cout << p[k] / __gcd(p[k], cnt) << '/' << cnt / __gcd(p[k], cnt) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}