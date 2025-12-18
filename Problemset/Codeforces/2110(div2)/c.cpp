#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> d(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> d[i];

	vector<array<int, 2>> reg(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> reg[i][0] >> reg[i][1];

	int l = 0, r = 0;
	bool ok = true;
	vector<array<int, 2>> reg1(n + 1);
	for(int i = 1; i <= n; i ++){
		int a = reg[i][0], b = reg[i][1];
		if(d[i] == 1)
			l ++, r ++;
		if(d[i] == -1)
			r ++;
		l = max(l, a);
		r = min(r, b);
		ok &= (l <= r);
		reg1[i] = {l, r};
		// cout << l << " " << r << '\n';	
	}
	if(!ok){
		cout << -1 << '\n';
		return;
	}
	// cout << "@" << '\n';
	int h = l;
	for(int i = n; i >= 1; i --){
		if(d[i] == 1)
			h --;
		if(d[i] == -1){
			if(h - 1 >= reg1[i - 1][0] && h - 1 <= reg1[i - 1][1])
				h --, d[i] = 1;
			else
				d[i] = 0;
		}
	}
	for(int i = 1; i <= n; i ++)
		cout << d[i] << " ";
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _;
	cin >> _;
	while (_ --)
		solve();
}