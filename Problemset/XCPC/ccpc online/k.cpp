#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
	int n;
	cin >> n;
	if(n & 1)
		cout << (n + 1) / 2 * n << '\n';
	else
		cout << (n + 1) / 2 * n + n / 2 << '\n';
	for(int i = n; i >= 1; i --)
		cout << i << ' ';
	cout << '\n';

}

signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while(_ --)
		solve();
}