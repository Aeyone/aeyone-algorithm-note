#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	if(n < 4){
		cout << -1 << '\n';
		return;
	}
	if(n == 4){
		cout << "3 1 4 2" << '\n';
		return;
	}
	vector<int> res;
	for(int i = 1; i <= n; i ++)
		if(i & 1)
			res.push_back(i);

	int x = -1;
	if(n % 2 == 0)
		x = n, n --;

	int tmp = -1;	
	for(int i = n; i >= 1; i --){
		if(i % 2 == 0){
			if(tmp == -1)
				tmp = i;
			else if(tmp != 0){
				res.push_back(i);
				if(x != -1)
					res.push_back(x);
				res.push_back(tmp);
				tmp = 0;
			}else
				res.push_back(i);
		}
	}
	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}