#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL
#define vt vector
/*  
	一道dp好题。
	求去掉最多k个牌子之后的总和最小值，那我们就求出删掉最多k个牌子能产生的最大贡献。
	设f[i][j][la]表示在前i个牌子中，删去其中j个，且最后一次留下的牌子是第la个时产生的最大贡献。
	状态转移方程如下：
		1、考虑不删除第i个牌子，对于0 ~ min(k, i)中的所有j： 
			f[i][j][i] = max(f[i - 1][j][0], f[i - 1][j][1], ..., f[i - 1][j][i - 1])
		2、考虑删除第i个牌子，对于1 ~ min(k, i)中的所有j：
			f[i][j][0] = f[i - 1][j - 1][0] + (x[i + 1] - x[i]) * (a[i] - a[0]) 
			f[i][j][1] = f[i - 1][j - 1][1] + (x[i + 1] - x[i]) * (a[i] - a[1]) 
			...
			f[i][j][i - 1] = f[i - 1][j - 1][i - 1] + (x[i + 1] - x[i]) * (a[i] - a[i - 1])
	即整个数组最大贡献为max(f[n - 1][0 ~ k][0 ~ n - 1])
*/
void solve() {//
	int n, l, k;
	cin >> n >> l >> k;
	vector<int> x(n + 1), a(n), d(n);
	x[n] = l;
	for(int i = 0; i < n; i ++){
		cin >> x[i];
	}
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	i64 sum = 0;
	for(int i = 0; i < n; i ++){
		d[i] = x[i + 1] - x[i];
		sum += d[i] * a[i];
	}
	vt<vt<vt<i64>>> f(2, vt<vt<i64>> (k + 1, vt<i64>(n, -INFLL)));
	f[0][0][0] = 0;
	for(int i = 1; i < n; i ++){
		fill(f[i & 1].begin(), f[i & 1].end(), vt<i64>(n, -INFLL));
		for(int j = 0; j <= min(k, i); j ++){
			for(int la = 0; la < i; la ++){
				if(i - 1 >= j){
					f[i & 1][j][i] = max(f[i & 1][j][i], f[!(i & 1)][j][la]);
				}
				if(j >= 1){
					f[i & 1][j][la] = max(f[i & 1][j][la], f[!(i & 1)][j - 1][la] + (i64)d[i] * (a[i] - a[la]));
				}
			}
		}
	}
	i64 ans = 0;
	for(int i = 0; i <= k; i ++){
		for(int j = 0; j < n; j ++){
			ans = max(ans, f[(n - 1) & 1][i][j]);
		}
	}
	cout << sum - ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}