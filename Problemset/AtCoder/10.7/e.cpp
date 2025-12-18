#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {
	int n;
	cin >> n;
	vector<int> Q(n + 1), P(n + 1);
	for(int i = 1; i <= n; i ++){//编号为i的人看着编号为P[i]的人
		cin >> P[i];
	}
	for(int i = 1; i <= n; i ++){//编号i的人穿着编号为Q[i]的围裙
		cin >> Q[i];
	}
	vector<int> res(n + 1);
	for(int i = 1; i <= n; i ++){//穿着编号为Q[i]围裙的人，看着编号为P[i]的人穿着编号为Q[P[i]]的围裙
		res[Q[i]] = Q[P[i]];
	}
	for(int i = 1; i <= n; i ++){
		cout << res[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}