#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<vector<i64>> dif(1010, vector<i64>(1010));
	vector<vector<i64>> sum(1010, vector<i64>(1010));
	for(int i = 0; i < n; i ++){
		int h, w;
		cin >> h >> w;
		int s = h * w;
		dif[1][1] += s;
		dif[h + 1][1] -= s;
		dif[1][w + 1] -= s;
		dif[h + 1][w + 1] += s;
	}
	for(int i = 1; i <= 1000; i ++)
		for(int j = 1; j <= 1000; j ++)
			sum[i][j] = (dif[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);

	while(q --){
		int hs, ws, hb, wb;
		cin >> hs >> ws >> hb >> wb;
		cout << sum[hs + 1][ws + 1] - sum[hb][ws + 1] - sum[hs + 1][wb] + sum[hb][wb] << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}