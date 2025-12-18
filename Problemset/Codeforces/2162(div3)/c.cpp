#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	i64 a, b;
	cin >> a >> b;
	i64 num1 = 0, num2 = 0;
	for(int i = 0; a >> i > 0; i ++){
		num1 += !(a >> i & 1) * (1 << i);
		num2 += !(b >> i & 1) * (1 << i);
	}
	if((i64)(a ^ num1 ^ num2) != b){
		cout << -1 << '\n';
		return;
	}
	cout << 2 << '\n' << num1 << ' ' << num2 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}