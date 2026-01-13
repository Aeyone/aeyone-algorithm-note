#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	auto query = [&](int u, int v)->bool{
		cout << u << ' ' << v << endl;
		int x;
		cin >> x;
		return x;
	};
	for(int len = 1; len <= n; len ++) {
		for(int i = 1; i + len <= n; i ++) {
			if(query(i, i + len)) {
				return;
			}
		}
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