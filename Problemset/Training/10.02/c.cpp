#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int query(int a, int b){
	cout << "? " << a << ' ' << b << endl;
	int x;
	cin >> x;
	return x;
}

void solve() {
	int l = 1, r = 1000;
	while(l < r){
		int m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3;
		int S = query(m1, m2);
		if(S == (m1 + 1) * (m2 + 1)){
			r = m1;
		}
		if(S == m1 * (m2 + 1)){
			l = m1 + 1, r = m2;
		}
		if(S == m1 * m2){
			l = m2 + 1;
		}
	}
	cout << "! " << l << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}