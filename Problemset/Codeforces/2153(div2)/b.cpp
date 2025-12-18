#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {
	int x, y, z;
	cin >> x >> y >> z;
	bool ok = true;
	for(int i = 0; i <= 30; i ++){
		int cnt = 0;
		cnt += (x >> i & 1);
		cnt += (y >> i & 1);
		cnt += (z >> i & 1);
		ok &= (cnt != 2);
	}
	if(ok){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
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