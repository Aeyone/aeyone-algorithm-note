#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a){
		cin >> e;
	}
	vector<vector<int>> f(n, vector<int>(n + 1));//f[i][j]表示第i个数，在从j开始的后面所有数(k)中，满足a[i]>a[k]的个数
	vector<int> sum(n);//当前位置左右s产生的逆序对数量
	for(int i = 0; i < n; i ++){
		for(int j = n - 1; j >= i + 2; j --){
			f[i][j] = f[i][j + 1] + (a[i] > a[j]);
		}
		for(int j = i + 2; j < n; j ++){
			sum[j] += f[i][j];
		}
	}
	i64 ans = 0;
	for(int i = 0; i <= n - 4; i ++){
		for(int j = i + 2; j < n; j ++){
			sum[j] -= f[i][j];
		}
		for(int j = i + 2; j <= n - 2; j ++){
			if(a[i] < a[j]){
				ans += sum[j + 1];
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}