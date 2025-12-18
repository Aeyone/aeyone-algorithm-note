#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string ss;
	cin >> ss;
	int n = ss.size();
	ss = " " + ss;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		if (ss[i] == '(')
			a[i] = 1;
		else
			a[i] = -1;
	}
	vector<int> s(n + 1);
	bool ok = false;
	for (int i = 1; i < n; i ++)
		s[i] = s[i - 1] + a[i], ok |= (s[i] == 0);

	if (ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

}

signed main() {
//	freopen("data.in", "r", stdin), freopen("data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _;
	cin >> _;
	while (_ --)
		solve();
}

