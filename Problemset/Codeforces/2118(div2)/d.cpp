#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<i64> p(n), d(n);
	for(int i = 0; i < n; i ++)
		cin >> p[i];
	for(int i = 0; i < n; i ++)
		cin >> d[i];
	int q;
	cin >> q;
	while(q --){
		bool ok = true;
		i64 x;
		cin >> x;
		int u = 0;
		for(int i = 0; i < n; i ++)
			if(x <= p[i]){
				u = i;
				break;
			}
			

		i64 now = 0;
		bool back = false;
		int mx = 250000, cnt = 0;
		for(int i = u; i < n && i >= 0;){
			now = (now + abs(p[i] - x)) % k;
			x = p[i];

			if(now == d[i])
				back = !back;
			cnt ++;
			if(cnt >= mx){
				ok = false;
				break;
			}
			
			if(!back)
				i ++;
			else
				i --;
		}
		if(ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
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