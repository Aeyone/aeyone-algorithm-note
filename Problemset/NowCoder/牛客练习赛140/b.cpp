#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, s;
	cin >> n >> s;
	i64 l = 1, r = n, tar = 1;
	while(l <= r){
		i64 mid = (r + l) >> 1;
		if(n / mid >= s)
			tar = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	i64 x1 = n / tar, x2 = n / (tar + 1), x = 0;//x为转移到离目标最近的坐标
	if(abs(x1 - s) <= abs(x2 - s))
		x = x1;
	else
		x = x2, tar ++;

	i64 ans = 0;
	if(s - 1 > abs(x - s) + tar){
		ans += abs(x - s) + tar;//需要转移
		// cout << 1 << ": " << x << " " << tar << '\n';
	}else{
		ans = s - 1;//直接走
		// cout << 2 << ": " << s << "\n";
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}