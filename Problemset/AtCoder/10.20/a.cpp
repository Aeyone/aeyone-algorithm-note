#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	bool ok = true;
	vector<int> a(8);
	for(int i = 0; i < 8; i ++){
		cin >> a[i];
		ok &= (a[i] % 25 == 0 && a[i] >= 100 && a[i] <= 675);
		if(i > 0){
			ok &= (a[i] - a[i - 1] >= 0);
		}
	}
	if(ok){
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}