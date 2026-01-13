#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> p(n);
	vector<int> x, y;//计算曼哈顿距离可以把x和y都视为单独的，分开计算
	for(int i = 0; i < n; i ++){
		cin >> p[i][0] >> p[i][1];
		x.push_back(p[i][0]);
		y.push_back(p[i][1]);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int l = 0, h = 0;
	if(n & 1)
		l = 1 , h = 1;
	else{
		l = (x[x.size() / 2] - x[x.size() / 2 - 1] + 1);
		h = (y[y.size() / 2] - y[y.size() / 2 - 1] + 1);
	}
	cout << (i64)l * h << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}