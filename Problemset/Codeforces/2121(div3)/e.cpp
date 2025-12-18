#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int l, r, n;
	cin >> l >> r;
	string a = to_string(l);
	string b = to_string(r);
	n = a.size();
	if(l == r){
		cout << a.size() * 2 << '\n';
		return;
	}
	int d = r - l;

	int x = min(100, d);
	int tmp = l;
	int ans = 1000;
	while(x){
		tmp ++;
		string xx = to_string(tmp);
		int cnt = 0;
		for(int i = 0; i < n; i ++){
			if(xx[i] == a[i])
				cnt ++;
			if(xx[i] == b[i])
				cnt ++;
		}
		ans = min(ans, cnt);
		x --;
	}
	x = min(100, d);
	tmp = r;
	while(x){
		tmp --;
		string xx = to_string(tmp);
		int cnt = 0;
		for(int i = 0; i < n; i ++){
			if(xx[i] == a[i])
				cnt ++;
			if(xx[i] == b[i])
				cnt ++;
		}
		ans = min(ans, cnt);
		x --;
	}
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