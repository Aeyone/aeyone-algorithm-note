#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> d(2 * n);
	for(int i = 0; i < 2 * n; i ++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	int x = d[0];
	bool ok = true;
	for(auto &e : d) {
		ok &= !(e & 1);
		e -= x;
	}
	if(!ok || d[0] != d[1]){
		cout << "NO" << '\n';
		return;
	}
	int sum = 0;
	for(int i = 2; i < 2 * n; i += 2) {
		if(d[i] == d[i - 2]|| d[i] != d[i + 1] || (d[i] & 1) || (sum + d[i] / 2) % (i / 2) != 0) {
			cout << "NO" << '\n';
			return;
		}
		cerr << "num = " << (sum + d[i] / 2) / (i / 2) << '\n';
		sum += (sum + d[i] / 2) / (i / 2);
	}
	cerr << x / 2 - sum << '\n';
	if(x / 2 > sum && (x / 2 - sum) % n == 0){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';	
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}