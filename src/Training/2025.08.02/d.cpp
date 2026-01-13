#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	i64 cnt = 0, ans = (i64)n * (n + 1) / 2;
	for(int i = n - 1; i >= 0; i --){
		if(s[i] == '1'){
			if(i - cnt >= 1)
				ans -= (i + 1), cnt ++;
			else
				cnt = max(0ll, cnt - 1);
		}else
			cnt = max(0ll, cnt - 1);
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