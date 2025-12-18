#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	string res;
	bool up = true;
	int l = 0, r = n - 1;
	while(b.size() < n){
		if(up){
			if(a[l] > a[r]){
				res += "L";
				b.push_back(a[l]);
				l ++;
			}else{
				res += "R";
				b.push_back(a[r]);
				r --;
			}
		}else{
			if(a[l] < a[r]){
				res += "L";
				b.push_back(a[l]);
				l ++;
			}else{
				res += "R";
				b.push_back(a[r]);
				r --;
			}
		}
		up = !up;
	}
	// for(int i = 0; i < n; i ++)
	// 	cout << b[i] << ' ';
	// cout << '\n';
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}