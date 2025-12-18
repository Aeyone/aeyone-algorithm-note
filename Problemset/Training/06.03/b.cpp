#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> res(n + 1);
	for(int i = 1; i < n; i ++){
		if(res[i] != 0)
			continue;
		for(int j = i + 1; j <= n; j ++){	
			if(res[j] != 0)
				continue;
			int a, b;
			cout << "? " << i << " " << j << '\n';
			cout.flush();
			cin >> a;
			cout << "? " << j << " " << i << '\n';
			cout.flush();
			cin >> b;
			if(a > b){
				res[i] = a;
				break;
			}else
				res[j] = b;
		}
	}
	cout << "! " << '\n';
	for(int i = 1; i <= n; i ++){
		if(res[i] == 0)
			res[i] = n;
		cout << res[i] << ' ';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}