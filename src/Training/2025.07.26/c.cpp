#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> a;
	if(abs(n - m) <= k && (n >= k || m >= k)){
		int sign = 0;

		if(n > m)
			n -= k;
		else
			m -= k, sign = 1;

		while(k --)
			a.push_back(sign);

		while(n > 0 && m > 0){
			a.push_back(!sign);
			a.push_back(sign);
			n --, m --;
		}
		while(n --)
			a.push_back(0);
		while(m --)
			a.push_back(1);
 
		for(auto e : a)
			cout << e;
		cout << '\n';
	}else{
		cout << -1 << '\n';
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