#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 2e5 + 10;

void solve() {
	string s;
	cin >> s;
	int tmp = 1 << (s.size() - 1), cnt = 1;
	bool ok = false;
	for(auto e : s){
		ok |= (e - '0' > 1);
		if(!ok && e == '0')
			cnt += tmp;
		tmp >>= 1;
	}
	cout << (1 << s.size()) - cnt << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}