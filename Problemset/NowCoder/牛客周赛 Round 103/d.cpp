#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	bool ok = false;
	for(int i = 0; i < n - 1; i ++){
		cnt += ((s[i] == '0' && s[i + 1] == '1') ||(s[i] == '1' && s[i + 1] == '0'));
		if(i <= n - 3)
			ok |= (s[i] == s[i + 1] && s[i + 1] == s[i + 2]);
	}
	if(cnt == 0 || (cnt == 1 && !ok) || s == "1001" || s == "0110")
		cout << 2 << '\n';
	else if(cnt == 2 || (cnt == 1 && ok))
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}