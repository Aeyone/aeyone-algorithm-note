#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {//差分好题
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s;
	cin >> t;
	vector<int> dif(n + 1), sum(n + 1);
	while(m --){
		int l, r;
		cin >> l >> r;
		l --, r --;
		dif[l] ++, dif[r + 1] --;
	}
	sum[0] = dif[0];
	for(int i = 1; i < n; i ++)
		sum[i] = sum[i - 1] + dif[i];
	for(int i = 0; i < n; i ++){
		if(sum[i] & 1)
			cout << t[i];
		else
			cout << s[i];
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}