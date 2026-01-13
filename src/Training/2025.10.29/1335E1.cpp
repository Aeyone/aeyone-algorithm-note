#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//硬枚举，前缀和
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<vector<int>> s(n + 2, vector<int>(27));
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		s[i] = s[i - 1];
		s[i][a[i]] ++;
	}
	int ans = 0;
	for(int l = 1; l <= n; l ++){
		for(int r = l; r <= n; r ++){
			int mxlr = 0;
			for(int i = 1; i <= 26; i ++){
				mxlr = max(mxlr, min(s[l - 1][i], (s[n][i] - s[r][i])));
			}
			int mxmid = 0;
			for(int i = 1; i <= 26; i ++){
				mxmid = max(mxmid, s[r][i] - s[l - 1][i]);
			}
			ans = max(ans, 2 * mxlr + mxmid);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}