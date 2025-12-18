#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {
	int x, y;
	cin >> x >> y;

	if(x == 0 && y == 0){
		cout << 4 << '\n';
	}else if(x == 1 && y == 0){
		cout << 3 << '\n';
	}else if(x == 2 && y == 0){
		cout << 2 << '\n';
	}else if(x == 0 && y == 1){
		cout << 4 << '\n';
	}else if(x == 1 && y == 1){
		cout << 3 << '\n';
	}else if(x == 2 && y == 1){
		cout << 2 << '\n';
	}else if(x == 0 && y == 2){
		cout << 6 << '\n';
	}else if(x == 1 && y == 2){
		cout << 4 << '\n';
	}else if(x == 2 && y == 2){
		cout << 2 << '\n';
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