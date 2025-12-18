#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int y;
	cin >> y;
	bool ok = (sqrt(y) == (int)sqrt(y));
	int sum = 0;
	while(y > 0){
		sum += y % 10;
		y /= 10;
	}
	ok &= (sqrt(sum) == (int)sqrt(sum));
	if(ok){
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}