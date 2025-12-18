#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int s[18] = {0, 1, 2, 0, 2, 1, 1, 0, 2, 1, 2, 0, 2, 1, 0,2, 0, 1};

void solve() {
	int n;
	cin >> n;
	vector<array<int,2>> v(3);
	for(auto &[a, b] : v)
		cin >> a >> b;

	int ans = 0x7f7f7f7f;
	for(int i = 0; i < 1 << 3; i ++){
		for(int j = 0; j < 6; j ++){
			int tmp = n;
			for(int k = 0; k < 3; k ++){
				int t = s[j * 3 + k];
				if((i >> t) & 1 && tmp >= v[t][0])
					tmp = (tmp - v[t][1] < 0 ? 0 : tmp - v[t][1]);
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _;
	cin >> _;
	while (_ --)
		solve();
}