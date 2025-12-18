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
	int dh = xb - xa - 1, la, ra, lb, rb;
	
	if(dh & 1){
		la = max(1, ya - (dh + 1) / 2);
		ra = min(w, ya + (dh + 1) / 2);
		lb = max(1, yb - (dh + 1) / 2);
		rb = min(w, yb + (dh + 1) / 2);
		if(lb <= la && rb >= ra)
			cout << "Bob" << '\n';
		else
			cout << "Draw" << '\n';		
	}else{
		la = max(1, ya - (dh + 1) / 2 - 1);
		ra = min(w, ya + (dh + 1) / 2 + 1);
		lb = max(1, yb - (dh + 1) / 2);
		rb = min(w, yb + (dh + 1) / 2);
		if(la <= rb && ra >= rb)
			cout << "Alice" << '\n';
		else
			cout << "Draw" << '\n';
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