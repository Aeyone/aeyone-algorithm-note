#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n), res(n, -1);
	int mx[2] = {-inf, -1};
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		a[i] += (!i ? c : 0);//先默认把c加在a[0]上
		if(a[i] > mx[0])
			mx[0] = a[i], mx[1] = i;
	}
	res[mx[1]] = 0;//最大的数就不需要删了
	i64 pre = 0;//要想某个i获胜，在一般情况下需要将它前面所有的数都删去
	for(int i = 0; i < n; i ++) if(res[i] != 0){
		res[i] = (i < mx[1] && pre + a[i] < mx[0]) + i;//a[i]在最大的数之前时，需要判断需不需要把最大的数删去
		pre += a[i];
	}
	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}