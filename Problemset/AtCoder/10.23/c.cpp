#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i ++){
		cin >> g[i];
	}
	int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
	int dy[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
	map<char, int> mp;
	mp['s'] = 0;
	mp['n'] = 1;
	mp['u'] = 2;
	mp['k'] = 3;
	mp['e'] = 4;
	vector<array<int, 2>> path(5);
	auto check = [&](int x, int y)->bool{
		for(int i = 0; i < 8; i ++){
			bool ok = true;
			for(int j = 0; j < 5; j ++){
				int a = x + j * dx[i], b = y + j * dy[i];
				ok &= (a >= 0 && a < n && b >= 0 && b < m && mp[g[a][b]] == j);
				path[j] = {a, b};
			}
			if(ok){
				for(auto [a, b] : path){
					cout << a + 1 << ' ' << b + 1 << '\n';
				}
				return true;
			}
		}
		return false;
	};
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++) if(g[i][j] == 's'){
			if(check(i, j)){
				return;
			}
		}
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