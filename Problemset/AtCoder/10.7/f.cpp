#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {
	int n = 9;
	vector<vector<int>> g(n, vector<int>(n));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			cin >> g[i][j];
		}
	}
	vector<int> vis(n + 1);
	bool ok = true;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			vis[g[i][j]] = true;
		}
		bool flag = true;
		for(int j = 1; j <= 9; j ++){
			flag &= (vis[j]);
			vis[j] = false;
		}
		ok &= flag;
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			vis[g[j][i]] = true;
		}
		bool flag = true;
		for(int j = 1; j <= 9; j ++){
			flag &= (vis[j]);
			vis[j] = false;
		}
		ok &= flag;
	}
	auto check = [&](int x, int y)->bool{
		for(int i = x; i <= x + 2; i ++){
			for(int j = y; j <= y + 2; j ++){
				vis[g[i][j]] = true;
			}
		}
		bool flag = true;
		for(int j = 1; j <= 9; j ++){
			flag &= (vis[j]);
			vis[j] = false;
		}
		return flag;
	};
	for(int i = 0; i < n; i += 3){
		for(int j = 0; j < n; j += 3){
			ok &= check(i, j);
		}
	}
	if(ok){
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
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