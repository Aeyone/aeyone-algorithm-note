#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int h, w, xa, ya, xb, yb;
	cin >> h >> w >> xa >> ya >> xb >> yb;
	if(xa >= xb){
		cout << "Draw" << '\n';
		return;
	}
	int dh = xb - xa, la, ra, lb, rb;
	
	if(dh & 1){
		int d = abs(yb - ya);
		if(d <= 1)
			cout << "Alice" << '\n';
		else{
			if(d - max(0, dh / 2 - (yb > ya ? w - yb : yb - 1)) <= 1)
				cout << "Alice" << '\n';
			else
				cout << "Draw" << '\n';
		}
	}else{
		int d = abs(ya - yb);
		if(d == 0)
			cout << "Bob" << '\n';
		else{
			if(max(0, dh / 2 - (ya > yb ? w - ya : ya - 1)) >= d)
				cout << "Bob" << '\n';
			else
				cout << "Draw" << '\n';
		}
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}