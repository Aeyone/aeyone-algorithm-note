#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> cnt(3);
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		cnt[x] ++;
	}
	int mx = cnt[1] + 2 * (cnt[2] - 1);
	int d = mx - k;
	if(d < 0 || d > cnt[2] - 1){
		cout << -1 << '\n';
		return;
	}
	vector<int> res(n);
	for(int i = 0; i < n; i ++){
		if(!(i & 1)){
			if(cnt[1] > 0 && d == 0)
				res[i] = 1, cnt[1] --;
			else{
				res[i] = 2, cnt[2] --;
				if(d > 0)
					d --;
			}
		}else{
			if(cnt[1] > 0)
				res[i] = 1, cnt[1] --;
			else
				res[i] = 2, cnt[2] --;
		}
	}
	for(int i = 0; i < n; i ++)
		cout << res[i] << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}