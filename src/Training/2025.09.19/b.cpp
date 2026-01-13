#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	if((n + x) & 1){
		cout << 0 << '\n';
		return;
	}
	int a = (n - x) / 2, b = (n + x - 2) / 2;
	set<int> st;
	auto factor = [&](int num)->void{
		for(int i = 1; i <= num / i; i ++) if(num % i == 0){
			if(i >= x - 1)
				st.insert(i);
			if(num / i >= x - 1)
				st.insert(num / i);
		}
	};
	factor(a), factor(b);
	cout << st.size() << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}