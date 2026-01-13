#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<array<int, 2>> p(k), t(k);
	for(auto &[x, y] : p){
		cin >> x >> y;
	}
	for(auto &[x, y] : t){
		cin >> x >> y;
	}
	string res = string(m - 1, 'L') + string(n - 1, 'U');
	for(int i = 0; i < min(n, m); i ++){
		if(n <= m){
			res += string(m - 1, (i & 1 ? 'L' : 'R'));
			res += "D";
		}else{
			res += string(n - 1, (i & 1 ? 'U' : 'D'));
			res += "R";
		}
	}
	//n * m + n + m - 1 + min(n, m)
	res.pop_back();
	cout << res.size() << '\n';
	cout << res << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}