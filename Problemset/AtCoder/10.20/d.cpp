#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<string> g(n);
	for(int i = 0; i < n; i ++){
		cin >> g[i];
	}
	for(int i = 1; i < n; i ++){
		swap(g[i][0], g[i - 1][0]);
	}
	for(int i = 1; i < n; i ++){
		swap(g[n - 1][i], g[n - 1][i - 1]);
	}
	for(int i = n - 2; i >= 0; i --){
		swap(g[i][n - 1], g[i + 1][n - 1]);
	}
	for(int i = n - 2; i >= 1; i --){
		swap(g[0][i], g[0][i + 1]);
	}
	for(int i = 0; i < n; i ++){
		cout << g[i] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}