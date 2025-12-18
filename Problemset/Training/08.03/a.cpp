#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;

	a.push_back(0);
	vector<vector<int>> dp(m + 1, vector<int>(m + 1, -inf));
	vector<int> I, S;
	dp[0][0] = 0;
	for(int i = 0, idx = -1; i <= n; i ++){
		if(idx == -1 && a[i] != 0)
			continue;

		if(a[i] != 0){
			if(a[i] > 0)
				I.push_back(a[i]);
			else
				S.push_back(-a[i]);
			continue;
		}

		idx ++;
		if(idx == 0)
			continue;
		int cntS = 0, cntI = I.size();
		sort(I.begin(), I.end()), sort(S.begin(), S.end());
		for(int j = idx; j >= 0; j --){//j点智力
			int k = idx - j;//k点力量
			while(cntI > 0 && I[cntI - 1] > j)
				cntI --;
			while(cntS < S.size() && S[cntS] <= k)
				cntS ++;

			if(j - 1 >= 0)
				dp[idx][j] = max(dp[idx][j], dp[idx - 1][j - 1] + cntI + cntS);//选智力
			if(k - 1 >= 0)
				dp[idx][j] = max(dp[idx][j], dp[idx - 1][j] + cntI + cntS);//选力量
		}
		I.clear(), S.clear();
	}
	
	int ans = -inf;
	for(int i = 0; i <= m; i ++)
		ans = max(ans, dp[m][i]);
	cout << ans << '\n';
	// for(int i = 0; i <= m; i ++){
	// 	for(int j = 0; j <= m; j ++){
	// 		if(dp[i][j] != -inf)
	// 			cout << dp[i][j] << ' ';
	// 		else
	// 			cout << -1 << ' ';
	// 	}
	// 	cout << '\n';
	// }
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}