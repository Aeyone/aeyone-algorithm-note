#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(a[i][j] == 0){
				cout << ".";
			}else{
				cout << (char)('A' + a[i][j] - 1);
			}
		}
		cout << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}