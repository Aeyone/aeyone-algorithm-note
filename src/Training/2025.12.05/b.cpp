#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {//有趣的简单构造题
	int n, k;
	cin >> n >> k;
	if(k % n == 0){
		cout << 0 << '\n';
	}else{
		cout << 2 << '\n';
	}
	vector<vector<int>> g(n, vector<int>(n));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(k > 0){
				g[j][(i + j) % n] = 1;
				k --;
			}
		}
	}
	for(auto v : g){
		for(auto e : v){
			cout << e;
		}
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}