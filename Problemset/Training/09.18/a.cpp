#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int query(int i, int j, int k){
	int res = 0;
	cout << "? " << i << ' ' << j << ' ' << k << endl;
	cin >> res;
	return res;
}

void solve() {
	int n;
	cin >> n;
    mt19937 rd(time(nullptr));
	array<int, 3> a = {1, 2, 3};
	int x = query(a[0], a[1], a[2]);
	while(x != 0){
		a[0] = a[1];
		a[1] = a[2];
		a[2] = x;
		x = query(a[0], a[1], a[2]);
		shuffle(a.begin(), a.end(), rd);//随机化处理 很恶心
	}
	cout << "! " << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	// ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}