#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//简单异或构造题
	i64 u, v;
	cin >> u >> v;
	i64 d = v - u;
	if(d < 0 || (d & 1)){
		cout << -1 << '\n';
		return;
	}
	if(u == 0 && v == 0){
		cout << 0 << '\n';
		return;
	}
	d >>= 1;
	if(d == 0){
		cout << 1 << '\n';
		cout << u << '\n';
	}else if((u + d) == (u ^ d)){
		cout << 2 << '\n';
		cout << u + d << ' ' << d << '\n';
	}else{
		cout << 3 << '\n';
		cout << u << ' ' << d << ' ' << d << '\n';
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