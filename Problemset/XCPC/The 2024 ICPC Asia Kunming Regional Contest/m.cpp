#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	int idx = 1;
	for(int i = 0; i < n + m; i ++){
		for(int j = 0, k = i; j < m && k >= 0; j ++, k --){
			if(k >= n){
				continue;
			}
			a[k][j] = idx ++;
		}
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}